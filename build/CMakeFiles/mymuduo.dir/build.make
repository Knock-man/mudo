# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xbj/FuxianCode/fuxian_mudo/mudo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xbj/FuxianCode/fuxian_mudo/mudo/build

# Include any dependencies generated for this target.
include CMakeFiles/mymuduo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mymuduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mymuduo.dir/flags.make

CMakeFiles/mymuduo.dir/src/Channel.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/Channel.cpp.o: ../src/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mymuduo.dir/src/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/Channel.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Channel.cpp

CMakeFiles/mymuduo.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Channel.cpp > CMakeFiles/mymuduo.dir/src/Channel.cpp.i

CMakeFiles/mymuduo.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Channel.cpp -o CMakeFiles/mymuduo.dir/src/Channel.cpp.s

CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o: ../src/CurrentThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/CurrentThread.cpp

CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/CurrentThread.cpp > CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.i

CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/CurrentThread.cpp -o CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.s

CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o: ../src/DefaultPoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/DefaultPoller.cpp

CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/DefaultPoller.cpp > CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.i

CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/DefaultPoller.cpp -o CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.s

CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o: ../src/EpollPoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/EpollPoller.cpp

CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/EpollPoller.cpp > CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.i

CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/EpollPoller.cpp -o CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.s

CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o: ../src/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/InetAddress.cpp

CMakeFiles/mymuduo.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/InetAddress.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/InetAddress.cpp > CMakeFiles/mymuduo.dir/src/InetAddress.cpp.i

CMakeFiles/mymuduo.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/InetAddress.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/InetAddress.cpp -o CMakeFiles/mymuduo.dir/src/InetAddress.cpp.s

CMakeFiles/mymuduo.dir/src/Logger.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/Logger.cpp.o: ../src/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mymuduo.dir/src/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/Logger.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Logger.cpp

CMakeFiles/mymuduo.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Logger.cpp > CMakeFiles/mymuduo.dir/src/Logger.cpp.i

CMakeFiles/mymuduo.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Logger.cpp -o CMakeFiles/mymuduo.dir/src/Logger.cpp.s

CMakeFiles/mymuduo.dir/src/Poller.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/Poller.cpp.o: ../src/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mymuduo.dir/src/Poller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/Poller.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Poller.cpp

CMakeFiles/mymuduo.dir/src/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/Poller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Poller.cpp > CMakeFiles/mymuduo.dir/src/Poller.cpp.i

CMakeFiles/mymuduo.dir/src/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/Poller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Poller.cpp -o CMakeFiles/mymuduo.dir/src/Poller.cpp.s

CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o: ../src/Timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o -c /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Timestamp.cpp

CMakeFiles/mymuduo.dir/src/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/src/Timestamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Timestamp.cpp > CMakeFiles/mymuduo.dir/src/Timestamp.cpp.i

CMakeFiles/mymuduo.dir/src/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/src/Timestamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xbj/FuxianCode/fuxian_mudo/mudo/src/Timestamp.cpp -o CMakeFiles/mymuduo.dir/src/Timestamp.cpp.s

# Object files for target mymuduo
mymuduo_OBJECTS = \
"CMakeFiles/mymuduo.dir/src/Channel.cpp.o" \
"CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o" \
"CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o" \
"CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o" \
"CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o" \
"CMakeFiles/mymuduo.dir/src/Logger.cpp.o" \
"CMakeFiles/mymuduo.dir/src/Poller.cpp.o" \
"CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o"

# External object files for target mymuduo
mymuduo_EXTERNAL_OBJECTS =

../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/Channel.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/CurrentThread.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/DefaultPoller.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/EpollPoller.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/InetAddress.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/Logger.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/Poller.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/src/Timestamp.cpp.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/build.make
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../lib/libmymuduo.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mymuduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mymuduo.dir/build: ../lib/libmymuduo.so

.PHONY : CMakeFiles/mymuduo.dir/build

CMakeFiles/mymuduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mymuduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mymuduo.dir/clean

CMakeFiles/mymuduo.dir/depend:
	cd /home/xbj/FuxianCode/fuxian_mudo/mudo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xbj/FuxianCode/fuxian_mudo/mudo /home/xbj/FuxianCode/fuxian_mudo/mudo /home/xbj/FuxianCode/fuxian_mudo/mudo/build /home/xbj/FuxianCode/fuxian_mudo/mudo/build /home/xbj/FuxianCode/fuxian_mudo/mudo/build/CMakeFiles/mymuduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mymuduo.dir/depend

