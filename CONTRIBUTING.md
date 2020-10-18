# Contributing Guide

-   [Issue Reporting Guidelines](#issue-reporting-guidelines)
-   [Pull Request Guidelines](#pull-request-guidelines)
-   [Development Setup](#development-setup)

## Issue Reporting Guidelines

-   The issue list of this repo is **exclusively** for bug reports and feature requests. Non-conforming issues will be closed immediately.

-   Try to search for your issue, it may have already been answered or even fixed in the development branch.

-   Check if the issue is reproducible with the latest stable version of [Unreal Engine 4](https://github.com/EpicGames/UnrealEngine). If you are using a pre-release, please indicate the specific version you are using.

-   It is **required** that you clearly describe the steps necessary to reproduce the issue you are running into. Issues with no clear repro steps will not be triaged. If an issue labeled "need repro" receives no further input from the issue author for more than 5 days, it will be closed.

-   For bugs that involves build setups, you can create a reproduction repository with steps in the README.

-   If your issue is resolved but still open, don’t hesitate to close it. In case you found a solution by yourself, it could be helpful to explain how you fixed it.

## Pull Request Guidelines

-   The `master` branch is basically just a snapshot of the latest stable release. All development should be done in dedicated branches. **Do not submit PRs against the `master` branch.**

-   Checkout a topic branch from the relevant branch, e.g. `develop`, and merge back against that branch.

-   It's OK to have multiple small commits as you work on the PR - we will let GitHub automatically squash it before merging.

-   If adding new feature:

    -   Add accompanying test case.
    -   Provide convincing reason to add this feature. Ideally you should open a suggestion issue first and have it greenlighted before working on it.

-   If fixing a bug:
    -   Provide detailed description of the bug in the PR. Live demo preferred.
    -   Add appropriate test coverage if applicable.

### Work Step Example

:exclamation: to write

## Development Setup

:exclamation: to write

### Coding standard

I try to respect the [UE4 coding standard](https://docs.unrealengine.com/en-US/Programming/Development/CodingStandard/index.html). So please read it to give you an idea.

However I consider that developers should be focus on **coding smart things** instead of **obsessively look their code format**, thus I prefer using "robots" (here: **code formatter**) which are really good to make repeatitive and boring tasks :smiley:.

I use [omnisharp.json](./omnisharp.json) **(C#)**, [.clang-format](./.clang-format) **(C++)** and [.prettierrc](./.prettierrc) **(.uplugin/.uproject)** files to help configure code formatter, you should consider using their respective formatter's plugins in your code editor. I give you some tips in [README formatting](https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv/README.md#5-formatting) section.
