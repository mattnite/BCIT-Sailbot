# Project Guidelines

This document outlines the structure and organization of the BCIT Sailbot
Development Team.

## Roles and Responsibilities

The structure for the BCIT Sailbot Team is meant to be simple and fluid. During
this project different components will have different lifetimes, the roles of
lead designers will change, and different members will wear many hats (eg.
project manager making a driver for the GPS module). 

### Project Manager

The project manager's role is to provide top-level organization of the project. 

### Lead Designer

A Lead designer is given a large component of the sailbot to complete, they will
organize their designers on sub-tasks and communicate with other relevant lead
designers to ensure that their components integrate well together.

### Designer

Designers are given tasks by their leads and their responsibility is to simply
give a time estimate and complete their task on time. Since this is a volunteer
based project, everyone puts in as much work as they want, the only expectation
is that you finish what you say you'll do.

## Project Management

We will organize our project around the Agile methodology. Zenhub, which is a
Github integration, provides a platform for the team do this. Please see [Using
Zenhub](zenhub.md) for details. We use git as our version control software under
github, sice it is widely used and works well for groups of programmers. It is
important to note that we use the
[Gitflow](http://nvie.com/posts/a-successful-git-branching-model/) methodology as our
git branching model.

## Decision Making

When making a isignificant design decision, it is important to discuss with other team
members. The final say goes to the project manager once the different options
are explored. It will then be recorded in Zenhub under the relevent issue.

## Communication

The team has three main avenues of communication, Zenhub, Facebook
Messenger, and in-person meetings. Zenhub, as outlined above, is meant for
formal discussion and organization of the project, it is where design questions,
suggestions, and decisions take place, or at least where they are recorded.
Messenger is for informal communication such as announcements, meeting
scheduling, or showing off some of your work ;). Finally, in-person meetings are
important so that the team can get together and talk about things face-to-face.
Team unity is important and so there is likely to be drinks afterwards as well!

## Organization of Repository

The repository organization for this project follows the main conventions of
many C++ projects. Each directory is quickly described below:

### bin

This is where executables are compiled to after running make. Do not commit
files in here

### build

This directory houses the object files during the compilation process. Do not
commit files in here

### source

The source directory is where all the source and implementaiton files are
located.

### include

All header files are stored in include. 

### test

Any code written to test components of the software systems in the sailbot are
contained here. We use [Google Test](https://github.com/google/googletest) to
test our C++ code.

### docs

And finally the docs folder contains all the markdown files used to generate
this site.
