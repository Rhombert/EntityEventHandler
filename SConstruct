#!/usr/bin/env python
import os
import sys

godot_env = SConscript("godot-cpp/SConstruct",
                 duplicate=0)

env = godot_env.Clone()

# godot-cpp wants to hide the commands, so this yanks them back.
env["CXXCOMSTR"] = env["CXXCOM"]
env["SHLINKCOMSTR"] = env["SHLINKCOM"]

# Cut out the C++ version assigned by godot_env
env["CXXFLAGS"] = [
    flag for flag in env["CXXFLAGS"]
    if not flag.startswith("-std=")
]
env.Append(
    CXXFLAGS=["-std=c++20"],
    CPPPATH=[
        "src/",
    ]
)

env_test = env.Clone()

sources = (
    Glob("src/*.cpp") + 
    Glob("src/**/*.cpp")
)

lib_filename = "{}entity_event_handler{}{}".format(
                    env.subst('$SHLIBPREFIX'), 
                    env["suffix"], 
                    env.subst('$SHLIBSUFFIX'))

# Creates a SCons target for the path with our sources.
library = env.SharedLibrary(
    "project/bin/{}".format(lib_filename),
    source=sources,
)

Export("library")
Export("env_test")
# Selects the shared library as the default target.
# Default(library)
prog_test = SConscript("tests/SConscript",
                       duplicate=0)
Default(library, prog_test)
