#! /bin/bash

git_short_version=$(git describe --dirty --always --abbrev=0)

header=src/version.h.gen

echo /\* Generated by generate_version.sh--do not edit! \*/ > $header
echo \#ifndef VERSION_H >> $header
echo \#define VERSION_H >> $header
echo \#define GIT_SHORT_VERSION \(\"$git_short_version\"\) >> $header
echo \#define COPYRIGHT \(\"Copyright \(c\) `date +'%Y'` The KnightOS Group\\n\"\) >> $header
echo \#define LICENSE \(\"License MIT/X11\\n\"\) >> $header
echo \#endif >> $header
