g++ lab1.cpp  -Wall  -lm  -o  lab1
./lab1 5  > temp5.txt
diff temp5.txt output5.txt
./lab1 10  > temp10.txt
diff temp10.txt output10.txt
./lab1 15  > temp15.txt
diff temp15.txt output15.txt
