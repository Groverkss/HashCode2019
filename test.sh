#!/bin/bash

mkdir $1
./a.out < test/c.in > $1/c.out
./a.out < test/d.in > $1/d.out
./a.out < test/e.in > $1/e.out
./a.out < test/f.in > $1/f.out