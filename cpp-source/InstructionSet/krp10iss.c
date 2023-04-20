#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

uint32_t PC;
uint32_t IR = -1;
uint32_t opcode;
uint32_t Accessed_memory_index = -1;
int32_t reg[32];
uint8_t memory[4096];
uint8_t data_memory[4096];

void Make_Instruction_memory(char* filename, char* buf, int len) //명령어를 메모리에 올린다
{
	int i = 0, j = 0,k = 0;
	unsigned char* p1 = (unsigned char*)buf;

	for (i = 0; i < len; i++)
	{
		memory[i] = *(p1 + i);
	}
}

void print_memory(int len) // 메모리 출력하기
{
	for (int i = 1; i <= len; i++)
	{
		printf("%02x", memory[i - 1]);
		if (i % 4 == 0)printf("\n");
	}
}

void Instrution_Fetch() // 명령어를 메모리에서 가져온다
{
	IR = 0;
	for (int i = 3; i >= 0; i--)
	{
		IR = IR | memory[PC + i]; // 읽을 때 거꾸로 읽는다.
		if(i != 0) IR = (IR << 8);
	}
	if (IR == 0)return;
	else PC += 4;
}

void setopcode() // opcode를 IR로부터 얻는다
{
	uint32_t temp = 31;
	temp = (temp << 27) & IR;
	temp = (temp >> 27);
	opcode = temp;
}

int getimm(int x) // imm의 값을 구하기위해 사용가능한 비트를 모두 1로 바꾼다.
{
	uint32_t imm = 1;
	for (int i = 0; i < x-1; i++)
	{
		imm = (imm << 1);
		imm = (imm | 1);
	}
	return imm;
}

void setRegIndex(uint32_t* reg,int n) // 몇번 째 레지스터인지 인덱스를 세팅한다.
{
	*reg = (*reg << n) & IR;
	*reg = (*reg >> n);
}

void store_memory(int32_t data,uint32_t start_address) // 레지스터 -> 메모리로 (ST)
{
	uint8_t temp = -1;
	for (int i = 0; i < 4; i++)
	{
		uint8_t result = (temp & data);
		data >>= 8;
		data_memory[start_address + i] = result; // 메모리 주소가 낮은 순서부터 저장(리틀 엔디언)
	}

}

int32_t load_memory(uint32_t start_address) // 메모리 -> 레지스터로 LD(로드)
{
	int32_t temp = 0;
	for (int i = 3; i >= 0; i--) //메모리 주소가 높은 순서부터 불러와 왼쪽으로 쉬프트
	{
		temp |= data_memory[start_address + i];
		if (i != 0)temp <<= 8;
	}
	return temp;
}

void Instruction_Execute() // 명령어를 실행한다.
{
	if (IR == 0) return;
	Accessed_memory_index = -1;
	setopcode(); // opcode 설정
//	printf("opcode: %d\n",opcode);
	uint32_t ra = 31; // 레지스터가 5비트이기 때문에 31를 할당해 놓는다.
	uint32_t rb = 31;
	uint32_t rc = 31;
	uint32_t imm = 0; 
	uint32_t cond = 1; // BR,BRL을 위한 cond
	uint32_t i = 0; // ASR,LSR,SHL,ROR을 위한 i
	int32_t toggle, temp;

	switch (opcode)
	{
	case 0: // ADDI
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		imm = getimm(17) & IR;
		reg[ra] = reg[rb] + imm;
		break;

	case 2: // ORI
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		imm = getimm(17) & IR;
		reg[ra] = reg[rb] | imm;
		break;

	case 4: // ANDI
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		imm = getimm(17) & IR;
		reg[ra] = reg[rb] & imm;
		break;

	case 6: // MOVI
		setRegIndex(&ra, 22);
		imm = getimm(17) & IR;
		reg[ra] = imm;
		break;

	case 8: // ADD
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = reg[rb] + reg[rc];
		break;
	
	case 9: // SUB
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = reg[rb] - reg[rc];
		break;

	case 10: // NOT
		setRegIndex(&ra, 22);
		setRegIndex(&rc, 12);
		reg[ra] = ~reg[rc];
		break;

	case 11: // NEG
		setRegIndex(&ra, 22);
		setRegIndex(&rc, 12);
		reg[ra] =  -reg[rc]; 
		break;

	case 12: // OR
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = reg[rb] | reg[rc];
		break;

	case 13: // AND
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = reg[rb] & reg[rc];
		break;

	case 14: // XOR
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = reg[rb] ^ reg[rc];
		break;

	case 15: // ASR
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		i = 32;
		i = (i & IR); // 5번째 비트 확인하기 위해
		if (i == 0) 
		{
			imm = getimm(5) & IR;
			reg[ra] = (reg[rb] >> imm);
		}
		else
		{
			reg[ra] = ( reg[rb] >> reg[rc]);
		}
		break;

	case 16: // LSR
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		i = 32; // 32 = 2^5이므로
		i = (i & IR); // 5번째 비트 확인하기 위해
		toggle = INT32_MAX,temp = reg[rb];
		imm = getimm(5) & IR;
		if (i == 0 && imm > 0)
		{
			temp >>= 1;
			temp &= toggle; // 부호의 영향을 받지 않도록 &연산을 통해 0으로 바꾼다.
			temp >>= (imm - 1); //한번 0으로 바꾸면 그 이후는 계속 0이므로
		}
		else if(reg[rc] > 0)
		{
			temp >>= 1;
			temp &= toggle;
			temp >>= (reg[rc]- 1);
		}
		reg[ra] = temp;
		break;

	case 17: // SHL
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		i = 32;
		i = (i & IR); // 5번째 비트 확인하기 위해
		if (i == 0)
		{
			imm = getimm(5) & IR;
			reg[ra] = (reg[rb] << imm);
		}
		else
		{
			reg[ra] = (reg[rb] << reg[rc]);
		}
		break;

	case 18: // ROR
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		i = 32;
		i = (i & IR); // 5번째 비트 확인하기 위해
		int32_t left_bit = INT32_MIN;
		int32_t right_bit = 1;
		temp = reg[rb];
		imm = getimm(5) & IR;
		if (i == 0)
		{
			for (int j = 0; j < imm; j++)
			{
				bool rightCh = right_bit & temp;
				bool leftCh = left_bit & temp;
				temp >>= 1;
				if (rightCh & leftCh || !rightCh & !leftCh)	continue; //가장 오른쪽 비트와 왼쪽 비트가 서로 같다면
				else temp ^= left_bit; //같지 않을 경우 비트를 바꿔준다
			}
		}
		else
		{
			for (int j = 0; j < reg[rc]; j++)
			{
				bool rightCh = right_bit & temp;
				bool leftCh = left_bit & temp;
				temp >>= 1;
				if ((rightCh & leftCh) || (!rightCh & !leftCh))	continue;
				else temp ^= left_bit;
			}
		}
		reg[ra] = temp;
		break;

	case 19: // BR
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		//reg[rb] = PC; // 다음 명령으로 가기 위한 설정 (임시)
		//reg[rc] = 0; // 다음 명령어로 가기위한 설정(임시)
		cond = getimm(3) & IR;
		
		if (cond == 0) { /* Never */
			//do_nothing;
		}
		else if (cond == 1) { /* Always */
			PC = reg[rb];
		}
		else if (cond == 2) { /* Zero */
			if (reg[rc] == 0)
				PC = reg[rb];
		}
		else if (cond == 3) { /* Nonzero */
			if (reg[rc] != 0)
				PC = reg[rb];
		}
		else if (cond == 4) { /* Plus */
			if (reg[rc] >= 0)
				PC = reg[rb];
		}
		else if (cond == 5) { /* Minus */
			if (reg[rc] < 0)
				PC = reg[rb];
		}
		break;

	case 20: // BRL
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		setRegIndex(&rc, 12);
		reg[ra] = PC;
		//reg[rb] = PC;//(임시)
		//reg[rc] = 1; // (임시)
		cond = getimm(3) & IR;
		if (cond == 0) { /* Never */
			//do_nothing;
		}
		else if (cond == 1) { /* Always */
			PC = reg[rb];
		}
		else if (cond == 2) { /* Zero */
			if (reg[rc] == 0)
				PC = reg[rb];
		}
		else if (cond == 3) { /* Nonzero */
			if (reg[rc] != 0)
				PC = reg[rb];
		}
		else if (cond == 4) { /* Plus */
			if (reg[rc] >= 0)
				PC = reg[rb];
		}
		else if (cond == 5) { /* Minus */
			if (reg[rc] < 0)
				PC = reg[rb];
		}
		break;

	case 21: // J
		imm = getimm(22) & IR;
		PC = PC + imm;
		break;

	case 22: // JL
		setRegIndex(&ra, 22);
		reg[ra] = PC;
		imm = getimm(22) & IR;
		PC = PC + imm;
		break;

	case 23: // LD
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		imm = getimm(17) & IR;
		if(rb == 31) // b'11111
		{
			reg[ra] = load_memory(imm);
			Accessed_memory_index = imm;
		}
		else
		{
			reg[ra] = load_memory(imm + reg[rb]);
			Accessed_memory_index = imm + reg[rb];
		}
		break;

	case 24: // LDR
		setRegIndex(&ra, 22);
		imm = getimm(22) & IR;
		reg[ra] = load_memory(PC + imm);
		Accessed_memory_index = PC + imm;
		break;

	case 25: // ST
		setRegIndex(&ra, 22);
		setRegIndex(&rb, 17);
		imm = getimm(17) & IR;
		if (rb == 31)
		{
			store_memory(reg[ra], imm);
			Accessed_memory_index = imm;
		}
		else
		{
			store_memory(reg[ra], imm);
			Accessed_memory_index = imm + reg[rb];
		}
		break;

	case 26: // STR
		setRegIndex(&ra, 22);
		imm = getimm(22) & IR;
		store_memory(reg[ra],PC+imm);
		Accessed_memory_index = PC + imm;
		break;

	case 27: // LEA
		setRegIndex(&ra, 22);
		imm = getimm(22) & IR;
		reg[ra] = PC + imm;
		break;

	case 28: // MSN
		setRegIndex(&ra, 22);
		reg[ra] = 20201326;
		break;

	default :
		printf("없는 명령어 입니다.\n");
		break;
	}
	return;

}

void print_reg()
{
	int index = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("reg[%d]: %d  ", index, reg[index]);
			index += 1;
		}
		printf("\n");
	}
}

void read_file() // 파일을 읽고 명령어를 메모리에 올린다.
{
	FILE* fp = fopen("input_file", "rb");
	char* read_buf = NULL;
	int size = 0;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	read_buf = (char*)calloc(size + 1, sizeof(char));
	fread(read_buf, sizeof(char), size, fp);
	fclose(fp);

	Make_Instruction_memory((char*)"input_file", read_buf, size);
}

void write_file()
{
	FILE* fp = fopen("output_file.txt", "w");

	for (int i = 0; i < 4096; i+=4)
	{
		fprintf(fp,"0x%08x: %02x %02x %02x %02x\n",i,
			data_memory[i+0],
			data_memory[i+1],
			data_memory[i+2],
			data_memory[i+3]);
	}
	fclose(fp);
}

int main()
{
	read_file();

	while(IR > 0)
	{
		uint32_t tempIR = IR; // 명령어를 저장해놓고 명령어가 다종료되면 마지막 명령어를 출력할 수 있도록 하기위해
		char request;
		printf("Request>> ");
		scanf("%c", &request);
		if(request != 10) getchar(); // 엔터키 눌럿을 경우을 제외한 나머지 경우
		
		if (request == 's') // s가 눌린경우
		{
			printf("--------------------------------------------------\n");
			Instrution_Fetch(); //PC 증가됨
			if (IR != 0) tempIR = IR;
			else break;
			printf("PC: %08x\n", PC - 4);
			printf("IR: %08x\n", tempIR);
			Instruction_Execute();
			print_reg(); // 범용 레지스터들 출력
			if (Accessed_memory_index != -1)
			{
				printf("접근한 메모리 0x%08x : %02x %02x %02x %02x\n",
					Accessed_memory_index,
					data_memory[Accessed_memory_index + 0],
					data_memory[Accessed_memory_index + 1],
					data_memory[Accessed_memory_index + 2],
					data_memory[Accessed_memory_index + 3]);
			}

			printf("--------------------------------------------------\n");
		}

		else if(request == 'r') // r이 눌린경우
		{
			printf("--------------------------------------------------\n");
			while (IR != 0)
			{
				tempIR = IR;
				Instrution_Fetch();
				if (IR == 0) break;
				Instruction_Execute();
				if (Accessed_memory_index != -1)
				{
					printf("Accessed mamory = 0x%08x : %02x %02x %02x %02x\n",
						Accessed_memory_index,
						data_memory[Accessed_memory_index + 0],
						data_memory[Accessed_memory_index + 1],
						data_memory[Accessed_memory_index + 2],
						data_memory[Accessed_memory_index + 3]);
				}
			}
			printf("PC: %08x\n", PC);
			printf("IR: %08x\n", tempIR);
			print_reg();
			printf("--------------------------------------------------\n");
		}
		
		else
		{
			printf("--------------------------------------------------\n");
			printf("잘못 입력하셨습니다.\n");
			printf("--------------------------------------------------\n");
			continue;
		}

	}
	
	write_file();
	return 0;
}
