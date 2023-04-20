#include<iostream>
//#include"Run.h"

using namespace std;
void Reservation();
void Guest_Show();
void Room_data();
bool Exit(){return false;}

void Run()
{
	bool Power = true;
	while(Power)
	{
		printf("※신규 회원 가입시 포인트1,000지급!\n");
		printf("최근 1년간 구매 실적기준\n");
		printf("Diamod:1년 동안 500만원 이상 결제시\n");
		printf("Platinum:1년 동안 350만원 이상 결제시\n");
		printf("Gold:1년 동안 200만원 이상 결제시\n");
		printf("Silver:1년 동안 100만원 이상 결제시\n");
		printf("Classic:예약 1회 이상\n\n");
	
		printf("★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
		printf("★ 1. 예약					  ★\n");
		printf("★ 2. 회원 목록					  ★\n");
		printf("★ 3. 객실 정보				  	  ★\n");
		printf("★ 4. 종료					  ★\n"); 
		printf("★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
		cout << "어떤 작업을 진행하시겠습니까? :";
		int Choice;
		cin >> Choice;
		cin.ignore();
		switch (Choice)
		{
			case 1:
				Reservation();
				break;
			case 2:
				Guest_Show();
				break;
			case 3:
				Room_data();
				break;
			case 4:
				Power = Exit();
				break;
			default:
				cout << "없는 작업입니다." << endl;
				break; 
		}
	}
}
