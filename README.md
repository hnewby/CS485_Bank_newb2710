# CS485_Bank_newb2710 Project Breakdown
This project was designed to replicate common features of bank. It was broken up into four milestones. In depth descriptions of each milestones can be found in the milestone folder. To Run: open the solution file and see test case below.

**Two types of Accounts**\
(S)avings\
(C)hecking

**Currency**\
All money has a currency (USD, GBP, YEN)\
Currency must be converted based on input rates

**Interest Rate**\
(F)lat\
(T)iered

Savings accounts also have a **MonthlyFee** and a **MinMonthlyBalance**\
CheckingAccounts have a **MinBalance** and a **MinBalanceFee**.

Accounts.txt looks like\
TYPE(S) Acct# CurrencyType InitialBalance INTEREST CurrenncyType MonthlyFee CurrenncyType MinMonthlyBalance\
TYPE(C) Acct# CurrencyType InitialBalance INTEREST CurrenncyType MinBalance CurrenncyType MinBalanceFee

**Commands**\
W - Withdraw\
D - Deposit\
P - Print all accounts (in the same order they appear in Accounts.txt) \
M - Charge monthly fees to savings accounts and generate interest in all accounts (in that order).\
B - Backup all checking accounts to a checking file and all savings accounts to a savings file. 

# Sample Test Case
Set 04_Bank as the startup project and run

**In Accounts.txt enter**\
S 1 USD 10000 F 0.01 USD 100 USD 100\
C 4 USD 90000 F 0.01 USD 100 USD 100\
S 3 GBP 10000 F 0.01 GBP 100 USD 100

**In Commands.txt enter**\
P\
W 1 GBP 100\
D 3 USD 100\
D 1 YEN 1000\
P\
B c.txt s.txt\
M\
P\
W 1 USD 9900\
P\
M\
P\
D 1 USD 102\
P\
M\
P\
P\
M\
P\
D 1 GBP 100\
W 3 GBP 100\
P\
W 4 YEN 1000\
P

**In c.txt enter**\
4, USD900.00, F 1.00%, USD1.00, USD1.00

**In s.txt enter**\
1, USD98.69, F 1.00%, USD1.00, USD1.00\
3, GBP100.76, F 1.00%, GBP1.00, USD1.00

## Expected Output
-------------\
1, USD100.00, F 1.00%, USD1.00, USD1.00\
3, GBP100.00, F 1.00%, GBP1.00, USD1.00\
4, USD900.00, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD98.69, F 1.00%, USD1.00, USD1.00\
3, GBP100.76, F 1.00%, GBP1.00, USD1.00\
4, USD900.00, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD99.67, F 1.00%, USD1.00, USD1.00\
3, GBP101.76, F 1.00%, GBP1.00, USD1.00\
4, USD909.00, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD0.67, F 1.00%, USD1.00, USD1.00\
3, GBP101.76, F 1.00%, GBP1.00, USD1.00\
4, USD909.00, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD-0.33, F 1.00%, USD1.00, USD1.00
3, GBP102.77, F 1.00%, GBP1.00, USD1.00
4, USD918.09, F 1.00%, USD1.00, USD1.00
-------------\
-------------\
1, USD0.69, F 1.00%, USD1.00, USD1.00\
3, GBP102.77, F 1.00%, GBP1.00, USD1.00\
4, USD918.09, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD-0.31, F 1.00%, USD1.00, USD1.00\
3, GBP103.79, F 1.00%, GBP1.00, USD1.00\
4, USD927.27, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD-0.31,  1.00%, USD1.00, USD1.00\
3, GBP103.79, F 1.00%, GBP1.00, USD1.00\
4, USD927.27, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD-1.31, F 1.00%, USD1.00, USD1.00\
3, GBP104.82, F 1.00%, GBP1.00, USD1.00\
4, USD936.54, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD0.00, F 1.00%, USD1.00, USD1.00\
3, GBP103.82, F 1.00%, GBP1.00, USD1.00\
4, USD936.54, F 1.00%, USD1.00, USD1.00\
-------------\
-------------\
1, USD0.00, F 1.00%, USD1.00, USD1.00\
3, GBP103.82, F 1.00%, GBP1.00, USD1.00\
4, USD936.54, F 1.00%, USD1.00, USD1.00\
-------------\
\
