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

After successfully building the project via CMake, you can run the solution for a particular problem by passing the problem number to the executable:

```bash
./build/project_euler_c/project_euler_c 10
```

The executable runs the solution and compares the computed answer against the correct answer, the list of which was obtained from [luckytoilet/projecteuler-solutions][projecteuler-solutions].

[projecteuler-solutions]: https://github.com/luckytoilet/projecteuler-solutions
