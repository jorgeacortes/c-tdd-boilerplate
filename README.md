# C Test Driven Development boilerplate
> Ready to go boilerplate for doing TDD with C and SCons as builder.

Boilerplate for C development using TDD and SCons.

Uses [Unity](https://github.com/ThrowTheSwitch/Unity/) for unit testing and [CMock](https://github.com/ThrowTheSwitch/CMock/) to create mocks.

Has already a sample module called _func1_ with some unit tests and mocks to ease the use of the boilerplate.

## Sample usage

To test that your setup is ready, run the following commands. If not, go to [Installation and SetUp](#installation-and-setup).

```sh
scons MOCK=yes # Creates mock files
scons # Builds the app and tests
```

## Including your code

To include your code you need to modify at least:

* project.scons
  * include_path_list: add all include paths for production code or common ones.
  * mocks_list: in case mocks are needed.
* app.scons
  * lib_sources: include all sources to compile
* test.scons
  * tests_lib_sources: include all sources to compile (mocks and tests)
  * Add more runners if needed

## Installation and SetUp

### Requirements

* Ruby (for CMock)
* Python (for SCons)
* Pip

### Steps

```sh
git clone --recursive https://github.com/jorgeacortes/c-tdd-boilerplate
pip install scons # Install SCons throgh pip
cd vendor/CMock
bundle install # Installs CMock, ensures you have all RubyGems needed
scons MOCK=yes # Creates Mock files
scons # Builds the app and tests
```

## Release History

* 1.0.0
    * First version

## Contributing

Feel free to contribute opening issues or pull requests.

## To do list

* Launch all runners option
* Colorize scons console output
* Colorize tests console outputs
* Implement debug/release mode
* Try to include all header paths inside a path
* Delete build folder after a clean
