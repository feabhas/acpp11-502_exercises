# Advanced Real-Time Modern C++ (C++11/14/17) Exercises

Exercise solutions and cmake projects for:

   * AC++11-502 Advanced Real-Time Modern C++ (C++11/14/17)

**Contents**
- [Advanced Real-Time Modern C++ (C++11/14/17) Exercises](#advanced-real-time-modern-c-c111417-exercises)
- [Folder structure](#folder-structure)
  - [Solutions](#solutions)
- [Pre-built Projects](#pre-built-projects)
  - [Building an exercise solution](#building-an-exercise-solution)
- [Disclaimer](#disclaimer)

# Folder structure

## Solutions

Solutions are provided for all exercises. 

Each exercise is number and named associated with the Advanced C++ Exercise in your supplied manual, e.g.

For Exercise 1 - User-defined types, the associated solution folder is

   `01-user-defined-types`

Many of the solutions have an `src` and `test` folder.

# Pre-Built Projects

These solutions are intended to be used with pre-defined CMake projects

## CMake-Host

The CMake-Host project is contructed to run the C++ exercises natively. It requires local installation of:
* C++ compiler
* CMake
* md5sum / md5sha1sum
* VSCode (optional if running from the CLI)
* (optional) GoogleTest

Full project details and the download can be found at the [CMake-Host repository](https://github.com/feabhas/cmake-host).

## Docker-Host

The Docker-Host project is designed to run using VSCode and the DevContainer extension.
To run it requires:
* Docker Desktop
* VSCode with devcontainer extension

Full project details and download can be found at [Docker-Host repository](https://github.com/feabhas/docker-host).

## Building an exercise solution

After copying the solutions directory into your project (CMake-Host/Docker-Host), you can build any of the individual exercise solutions.

To build a particular solution run the script:
```
$ ./build-one.sh N 
```
where `N` is the exercise number.

The script will initially look in the workspace for a folder 
called `exercises` and copy the colutions from there. Fallback locations for solutions icnlude a `solutions` folder in the workspace or
and `exercises` or `solutions` folder in the home directory.

**NOTE:** building a solution will copy all files in the `src` directory to 
the `src.bak` directory having removed any files already present in `src.bak`.

The `build-one.sh` script supports the `--help` option for more information.

Do not use the `--all` option as this will build each solution in turn and is used as part of our Continuous Integration testing.

# Disclaimer

Feabhas is furnishing these items *"as is"*. Feabhas does not provide any
warranty of them whatsoever, whether express, implied, or statutory,
including, but not limited to, any warranty of merchantability or fitness
for a particular purpose or any warranty that the contents their will
be error-free.

In no respect shall Feabhas incur any liability for any damages, including,
but limited to, direct, indirect, special, or consequential damages arising
out of, resulting from, or any way connected to the use of the item, whether
or not based upon warranty, contract, tort, or otherwise; whether or not
injury was sustained by persons or property or otherwise; and whether or not
loss was sustained from, or arose out of, the results of, the item, or any
services that may be provided by Feabhas.

The items are intended for use as an educational aid.Typically code solutions 
will show best practice of language features that have been introduced during 
the associated training, but do not represent production quality code. 
Comments and structured documentation are not included because the code 
itself is intended to be studied as part of the learning process.
