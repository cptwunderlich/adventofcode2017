# Advent of Code 2017

Usually I'm not a fan of coding competitions and puzzles. After all I'm already programming
for Work and University, so when I code in my spare time, I'd rather do something useful or
informative.
But I stumpled upon this and tried the first puzzle and got hooked.

My Rules: I'll try to solve them all, but I have no intention of getting up at 6 AM to try
and get on the leader board. Furthermore I'm not playing code golf.
But I'll try to solve the problems in a more "functional" way and using languages I might
not be using that often.

I'll document my progress here in this document, while the solutions are in their respective
directories.

## Day 1 & 2

I only started putting this up on Github on day 4.
For these two I used Python 3 and tried to use no raw loops. It took me way too long to
solve these and my Python 3 is woefully rusty. I use it maybe once a year and I don't
think I've used functools before.

Anyway, my solutions are hideous and way too complicated. Take a look at the solution
megathreads at https://www.reddit.com/r/adventofcode/ for some nicer ones.

## Day 3

I was actually too busy that day and didn't get to look at the problem, until I was lying
awake at 3 AM. I took a look at the solution megathread of the day and "solved" it the
next day. Many people figured out, that you didn't need code for that one.
You might consider it cheating, but meh.

## Day 4

For this one I broke out Java 8/9. I'm mostly stuck with 7 at work, so I didn't have a
chance yet to play with streams. This one seemed fairly easy, easier than days 1 and 2
and I solved it rather quickly. I'm also fairly pleased with how it looks.

I did incorporate one piece of feedback that I got from reddit after posting my solution
there. Namely using `.map(s -> s.split(" "))`, where I wasn't sure how to get rid of
two "manual" splits in filter.

## Day 5

The task is to follow the 'jump' instructions until you exit the array bounds.
I used C++ and at first I made a simple iterative approach and solved the puzzle.
Then I wanted to make it "prettier". To me it seems, like this is a problem more
suited for an iterative approach as opposed to a functional one. The solutions in
functional languages on Reddit also don't seem as succinct and elegant as usually.

## Day 6

I was busy all day, so I solved this one on the evening of Day 7.
While I used Kotlin for the solution, this program is absolutely ugly.
I just wanted to get it done. It's not idiomatic, it's a complete hack.
But it did the job.

