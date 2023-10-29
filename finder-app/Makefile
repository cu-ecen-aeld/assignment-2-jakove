CROSS_COMPILE ?=
TARGET = writer

# Default Target
.PHONY: $(TARGET)
all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CROSS_COMPILE)gcc -o $(TARGET) $(TARGET).c

# Clean up make
.PHONY: clean 
clean:
	rm -f $(TARGET)