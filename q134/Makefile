# Compiler
CSC = mcs

# Source files
SOURCES = src/Solution.cs Program.cs

# Output binary
OUTPUT = exec

# Library paths
LIBRARIES = ../.cs/NUnit.4.3.2/lib/net462/nunit.framework.dll

# Default rule to compile and run
all: clean $(OUTPUT)
	mono $(OUTPUT)

# Rule to compile the project
$(OUTPUT): $(SOURCES)
	$(CSC) -out:$(OUTPUT) $(SOURCES) $(addprefix -r:, $(LIBRARIES))

# Clean rule to remove compiled files
clean:
	rm -f $(OUTPUT)
