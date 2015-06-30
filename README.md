# SimpleQueryParser
A simple query parser using flex and bison

Introduction
============

This is a simple query parser that recognizes logic queries like:

 - this that     // Parsed as "this AND that"
 - this AND that
 - this AND NOT that
 - this AND NOT (he AND her)

Compile
=======

 - $ mkdir build
 - $ cd build
 - $ cmake ..
 - $ make

Usage
=====

./parser "this AND that"