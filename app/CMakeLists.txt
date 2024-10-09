# Any C++ source files needed to build this target (shell-app).
add_executable(pid_controller-app
  # list of source cpp files:
  main.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.

# Any dependent libraires needed to build this target.
target_link_libraries(pid_controller-app PUBLIC -static
  # list of libraries
  pid
  )

  
