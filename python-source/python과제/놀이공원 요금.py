def enter(time,age):
	if age>=19 and age<=64:
		if time==10:
			print("주간권","대인","요금:","56,000원")
		elif time==16:
			print("야간권","대인","요금:","46,000원")
		elif time=="2day":
			print("2일권","대인","요금:","87,000원")
		else :
			print("잘못된입력입니다.")
	elif age>=13 and age<=18:
		if time==10:
			print("주간권","청소년","요금:","47,000원")
		elif time==16:
			print("야간권","청소년","요금:","40,000원")
		elif time=="2day":
			print("2일권","청소년","요금:","73,000원")
		else :
			print("잘못된입력입니다.")
	elif age<=12 and age>=1 or age>=65:
		if time==10:
			print("주간권","소인/경로","요금:","44,000원")
		elif time==16:
			print("야간권","소인/경로","요금:","37,000원")
		elif time=="2day":
			print("2일권","소인/경로","요금:","69,000원")
		else :
			print("잘못된입력입니다.")

time = int(input("입장시간를 입력해주세요.:"))
age = int(input("나이를 입력해주세요.:"))
enter(time,age)
