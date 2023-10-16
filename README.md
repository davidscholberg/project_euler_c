# Project Euler

These are my solutions to the [Project Euler][project-euler-site] problem set. The solutions are written in [C][c-lang].

[project-euler-site]: https://projecteuler.net/
[c-lang]: https://en.wikipedia.org/wiki/C_(programming_language)

### Development Setup

To build and run this project, you'll need a C compiler and [CMake][cmake]. For example, if you want to use [GCC][gcc] on [Fedora Linux][fedora], you would run the following:

```bash
sudo dnf install gcc cmake
```

Building the project will depend on how your development environment handles CMake. Refer to the relevant documentation for instructions.


[cmake]: https://cmake.org/
[gcc]: https://gcc.gnu.org/
[fedora]: https://fedoraproject.org/

### Running Solutions

You can run the solution for a particular problem by passing the problem number to the [solve script][solve-script]:

```bash
./solve 10
```

The script builds and launches the project, which runs the solver for the particular problem and compares the computed answer against the correct answer, the list of which was obtained from [luckytoilet/projecteuler-solutions][projecteuler-solutions].

[solve-script]: solve
[projecteuler-solutions]: https://github.com/luckytoilet/projecteuler-solutions

### Running Tests

This project manages unit tests via [CTest][ctest]. To run the unit tests, you can launch the tests from your IDE or run the [test script][test-script].

[ctest]: https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html
[test-script]: test
