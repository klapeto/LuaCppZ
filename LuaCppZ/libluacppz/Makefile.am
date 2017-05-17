#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libluacppz.la

#######################################
# Build information for each library

# Sources for libluacppz
libluacppz_la_SOURCES = \
LuaState.cpp \
LuaValue.cpp \
LuaReference.cpp\
LuaTable.cpp \
Tokenizer.cpp \
LuaNumber.cpp \
LuaString.cpp

# Linker options libTestProgram
libluacppz_la_LDFLAGS = $(lua51_LIBS)

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libluacppz_la_CPPFLAGS = $(CXXFLAGS) -I$(top_srcdir)/include $(lua51_CFLAGS)

