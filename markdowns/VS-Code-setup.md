## Install dependencies

### VS Code IDE Setup
```
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
```





### Install dependencies

Current dependencies
- boost-algorithm
- gtest

#### Boost-Algorithm
```
vcpkg install boost-algorithm
```

Results after the running the above command  script
```
-- Performing post-build validation
Stored binary cache: "C:\Users\<username>\AppData\Local\vcpkg\archives\75\75f31361e880fb3dc031f8ecf4b9044a8631582db7ba9600cc894f0dddb94212.zip"
Elapsed time to handle boost-algorithm:x86-windows: 4.381 s
Total install time: 2.816 min
The package boost is compatible with built-in CMake targets:

    find_package(Boost REQUIRED [COMPONENTS <libs>...])
    target_link_libraries(main PRIVATE Boost::boost Boost::<lib1> Boost::<lib2> ...)

```
#### Gtest
```
vcpkg install gtest
```

The result should be:
```
-- Performing post-build validation
Stored binary cache: "C:\Users\<username>\AppData\Local\vcpkg\archives\9e\9e756b4be685a66c077d4d824f6f06d4c16ea02b1546a44ffd1ab6a3a8a52f9e.zip"
Elapsed time to handle gtest:x86-windows: 27.82 s
Total install time: 32.46 s
gtest provides CMake targets:

    # this is heuristically generated, and may not be correct
    find_package(GTest CONFIG REQUIRED)
    target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
```

### References
- https://vcpkg.io/en/getting-started.html
