#ifndef INC_COM
#define INC_COM

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>

// This file is only valid for the revision 0 of the KPKG format
#define KPKG_FORMAT_VERSION 0

typedef struct {
	uint8_t major;
	uint8_t minor;
	uint8_t patch;
} versionData;

typedef struct {
	int included;
	versionData version;
	uint8_t nameLength;
	char *name;
} packageDependency;

struct {
	// Runtime
	FILE *config;
	char *configName;
	int pack;
	char *filename;
	char *rootName;
	FILE *output;
	//
	// Package
	//
	char *pkgname;
	char *repo;
	versionData version;
	// Metadata
	uint8_t mdlen;
	// Files
	uint8_t compressionType;
	uint8_t sumType;
	uint8_t flen;
} packager;

enum {
	KEY_PKG_NAME,
	KEY_PKG_REPO,
	KEY_PKG_DESCRIPTION,
	KEY_PKG_DEPS,
	KEY_PKG_VERSION,
	KEY_PKG_AUTHOR,
	KEY_PKG_MAINTENER,
	KEY_PKG_COPYRIGHT,
	KEY_INFO_URL
};

enum {
	COMPRESSION_NONE,
	COMPRESSION_RLE,
	COMPRESSION_PUCRUNCH
};

enum {
	SUM_NONE,
	SUM_CRC16,
	SUM_SHA1,
	SUM_MD5
};

extern void displayUsage();
#endif
