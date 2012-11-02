#Andrea Chalmers 11256339
#Sonelisiwe Njozela 11272882

main : main.o Equation.o ExpressionFactory.o OperatorFactory.o GAUtility.o Expression.o Operator.o Variable.o Stack.o Queue.o
	g++  -static -o main main.o Equation.o ExpressionFactory.o OperatorFactory.o GAUtility.o Expression.o Operator.o Variable.o Stack.o Queue.o

main.o: main.cpp Equation.h 
	g++ -c main.cpp

Equation.o: Equation.cpp Equation.h
	g++ -c Equation.cpp

ExpressionFactory.o: ExpressionFactory.cpp ExpressionFactory.h Expression.h Constant.h Variable.h Operator.h OperatorFactory.h
	g++ -c ExpressionFactory.cpp

OperatorFactory.o : OperatorFactory.cpp OperatorFactory.h Operator.h
	g++ -c OperatorFactory.cpp

GAUtility.o: GAUtility.cpp GAUtility.h 
	g++ -c GAUtility.cpp

Expression.o: Expression.cpp Expression.h
	g++ -c Expression.cpp

Operator.o: Operator.cpp Operator.h Expression.h
	g++ -c Operator.cpp

Variable.o: Variable.cpp Variable.h Expression.h
	g++ -c Variable.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

Equation.h: ExpressionFactory.h OperatorFactory.h Expression.h Queue.h Stack.h

ExpressionFactory.h: Expression.h Constant.h Variable.h Operator.h OperatorFactory.h

Expression.h: ExpressionType.h GAUtility.h
