checker: plagiarismChecker.o plagiarismFuncts.o
	gcc plagiarismChecker.o plagiarismFuncts.o -o checker
	
plagiarismChecker.o: plagiarismChecker.c plagiarismFuncts.h
	gcc plagiarismChecker.c -c -o plagiarismChecker.o

plagiarismFuncts.o: plagiarismFuncts.c plagiarismFuncts.h
	gcc plagiarismFuncts.c -c -o plagiarismFuncts.o
	

clean:
	rm checker
	rm *.o
	
run: 
	./checker
	
runVal:
	valgrind --leak-check=full -s ./checker
