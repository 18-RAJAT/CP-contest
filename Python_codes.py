Balance=0
while 1:
    print("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit")
    choice=input("Choose an option: ")

    if choice=="1":
        Amount=float(input("Enter deposit Amount: "))
        if Amount>0:
            Balance+=Amount
            print(f"Deposited: ₹{Amount:.2f}")
        else:
            print("Deposit Amount must be positive")

    elif choice=="2":
        Amount=float(input("Enter withdrawal Amount: "))
        if Amount<=0:
            print("Withdrawal Amount must be positive")
        elif Amount>Balance:
            print("Insufficient Balance")
        else:
            Balance-=Amount
            print(f"Withdrew: ₹{Amount:.2f}")


    elif choice=="3":
        print(f"Current Balance: ₹{Balance:.2f}")

    elif choice=="4":
        break
    else:
        print("Invalid")
