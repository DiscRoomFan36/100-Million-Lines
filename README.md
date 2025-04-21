# 100 Million Lines of Code

I was annoyed at the 'fact' that A Car Runs on [100 Million Lines of code](https://medium.com/next-level-german-engineering/porsche-future-of-code-526eb3de3bbe)
Since this is obviously false, (and probably some sort of marketing tactic), I wondered how long it would take to even run 100 Million lines of code.

This project is about seeing what 100 Million lines of code looks like.

## What I've Done

Currently theirs a 1,000,000 line file. and it takes a very small amount of time to run.

Probably because im only interacting with a small number of variables, and the compiler is just doing all the calculations in the registers.

I've tried upping the lines, but my computer crashes if I have more the 10 Million lines. next step is to put code into seperate compilation units, add call them one at a time.

## Side Note.

Im coming to believe the old adage "if its slow, it has loops." The test doesn't make any loops, (Its just a straight line of code), so it is fast.

Can a 3 billion line program be done in under a second with a 3GHz processor? im exited to find out.

## Usage
```sh
# compile a 1,000,000 line c file
# (I'll rename it eventually)
make thing

# run it
time ./thing
```
