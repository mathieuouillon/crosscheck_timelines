# Croos check CLAS12 timelines
C++ program to cross-check the RG-D timelines.

# Instruction to build it
## Dependencies
- Meson and ninja:
    - Meson: https://mesonbuild.com/
    - Ninja: https://ninja-build.org/

- Likely available in your package manager (apt, brew, dnf, etc.), but the versions may be too old, in which case, use pip (`python -m pip install meson ninja`)

# Building
Use standard [Meson commands](https://mesonbuild.com/Quick-guide.html) to build HIPO.

```
meson setup build
cd build 
meson compile
```