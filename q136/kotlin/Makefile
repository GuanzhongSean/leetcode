KOTLINC = kotlinc
OUTPUT = app.jar
SOURCES = Main.kt src/Solution.kt

all: run

build:
	$(KOTLINC) $(SOURCES) -include-runtime -d $(OUTPUT)

run: build
	java -jar $(OUTPUT)

clean:
	rm -f $(OUTPUT)
	@echo "Cleaned up build files."
