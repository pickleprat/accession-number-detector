# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O2
INCLUDES = -I. -Idatabases -Idatabases/ddbj -Idatabases/kegg -Idatabases/pdb -Idatabases/refseq

# Directories
SRCDIR = .
BINDIR = ./bin
OBJDIR = ./obj

# Source files
MAIN_SRC = main.cpp
DB_SOURCES = $(wildcard databases/*/*.cpp)
ALL_SOURCES = $(MAIN_SRC) $(DB_SOURCES)

# Object files
MAIN_OBJ = $(OBJDIR)/main.o
DB_OBJECTS = $(patsubst databases/%.cpp,$(OBJDIR)/%.o,$(DB_SOURCES))
ALL_OBJECTS = $(MAIN_OBJ) $(DB_OBJECTS)

# Target executable
TARGET = $(BINDIR)/main

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/ddbj
	@mkdir -p $(OBJDIR)/kegg
	@mkdir -p $(OBJDIR)/pdb
	@mkdir -p $(OBJDIR)/refseq

# Main executable
$(TARGET): $(ALL_OBJECTS)
	$(CXX) $(CXXFLAGS) $(ALL_OBJECTS) -o $@
	@echo "✅ Built main executable: $(TARGET)"

# Main object file
$(OBJDIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Database object files
$(OBJDIR)/ddbj/%.o: databases/ddbj/%.cpp databases/ddbj/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/kegg/%.o: databases/kegg/%.cpp databases/kegg/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/pdb/%.o: databases/pdb/%.cpp databases/pdb/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/refseq/%.o: databases/refseq/%.cpp databases/refseq/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Individual database targets (if you want to build specific modules)
ddbj: directories $(OBJDIR)/ddbj/ddbj.o
	@echo "✅ Built DDBJ module"

kegg: directories $(OBJDIR)/kegg/kegg.o
	@echo "✅ Built KEGG module"

pdb: directories $(OBJDIR)/pdb/pdb.o
	@echo "✅ Built PDB module"

refseq: directories $(OBJDIR)/refseq/refseq.o
	@echo "✅ Built RefSeq module"

# Run the main program
run: $(TARGET)
	@echo "🚀 Running $(TARGET)..."
	@$(TARGET)

# Debug version
debug: CXXFLAGS += -DDEBUG -g3
debug: clean all

# Release version  
release: CXXFLAGS += -O3 -DNDEBUG
release: clean all

# Clean build files
clean:
	@echo "🧹 Cleaning build files..."
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)

# Clean and rebuild
rebuild: clean all

# Install (copy to system path - optional)
install: $(TARGET)
	@echo "📦 Installing to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build everything (default)"
	@echo "  run      - Build and run the main program"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build optimized release version"
	@echo "  clean    - Remove all build files"
	@echo "  rebuild  - Clean and build everything"
	@echo "  install  - Install binary to system"
	@echo "  ddbj     - Build only DDBJ module"
	@echo "  kegg     - Build only KEGG module" 
	@echo "  pdb      - Build only PDB module"
	@echo "  refseq  - Build only refseq module"
	@echo "  help     - Show this help message"

# Dependency tracking (automatic header dependency detection)
-include $(ALL_OBJECTS:.o=.d)

$(OBJDIR)/%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT $(@:.d=.o) $< > $@

# Phony targets
.PHONY: all clean rebuild run debug release install help directories ddbj kegg pdb refseq
