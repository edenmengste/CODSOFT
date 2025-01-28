#banking system 

print("Welcome to Your Banking System!")
balance=1000 #lets just assume the initial balance is 1000

while True:
 print("1. Check Balance")
 print("2. Deposit Money")
 print("3. Withdraw Money")
 print("4. Exit\n")


 choice = int(input("Please select an option (1-4):") )

 if choice==1:
    print(f"Your current balance is {balance}")

 elif choice==2: 
      deposited= float(input("Enter the amount they want to deposit: "))

      if deposited >= 0:
       balance += deposited
       print(f"Deposited {deposited}, your current balance is {balance}")
      else:
         print("invalid input, enter a positive number")

 elif choice==3:
     withdrawn= float(input("Enter the amount they want to withdraw: "))

     if balance >= 0 and withdrawn < balance :
        balance -= withdrawn
        print(f"Withdrawn {withdrawn}, your current blanace is {balance}")
     elif balance < 0: 
        print("invalid input enter a positive number")
     else: 
        print("insufficient amount") 

 elif choice==4:
   print("Thank You!")
   break
 else:
   print("INVALID NUMBER")   
          

    