FLAGS = -Wall
TARGET = main
CHROMOSOME = Chromosome
GENE = Gene
PARENTUNIT = ParentUnit
POPULATION = Population
GAUTLILTY = GAUtility

OBJECTS = $(TARGET).o $(CHROMOSOME).o $(GENE).o $(PARENTUNIT).o $(POPULATION).o $(GAUTLILTY).o

CC = g++

all: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(TARGET)
	
$(TARGET).o: $(TARGET).cpp $(POPULATION).h $(PARENTUNIT).h $(CHROMOSOME).h $(GENE).h $(GAUTLILTY).h
	$(CC) -c $(TARGET).cpp
	
$(POPULATION).o : $(POPULATION).cpp $(POPULATION).h $(PARENTUNIT).h $(CHROMOSOME).h $(GENE).h
	$(CC) -c $(POPULATION).cpp
	
$(PARENTUNIT).o: $(PARENTUNIT).cpp $(PARENTUNIT).h $(CHROMOSOME).h $(GENE).h
	$(CC) -c $(PARENTUNIT).cpp

$(CHROMOSOME).o: $(CHROMOSOME).cpp $(CHROMOSOME).h $(GENE).h $(GAUTLILTY).h
	$(CC) -c $(CHROMOSOME).cpp

$(GENE).o: $(GENE).cpp $(GENE).h
	$(CC) -c $(GENE).cpp
	
$(GAUTLILTY).o: $(GAUTLILTY).cpp $(GAUTLILTY).h
	$(CC) -c $(GAUTLILTY).cpp
	
run: 
	$(TARGET)
	
clean:
	rm -f *.o *~ $(TARGET)