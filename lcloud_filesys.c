////////////////////////////////////////////////////////////////////////////////
//
//  File           : lcloud_filesys.c
//  Description    : This is the implementation of the Lion Cloud device 
//                   filesystem interfaces.
//
//   Author        : *** INSERT YOUR NAME ***
//   Last Modified : *** DATE ***
//

// Include files
#include <stdlib.h>
#include <string.h>
#include <cmpsc311_log.h>

// Project include files
#include <lcloud_filesys.h>
#include <lcloud_controller.h>

//
// File system interface implementation

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcopen
// Description  : Open the file for for reading and writing
//
// Inputs       : path - the path/filename of the file to be read
// Outputs      : file handle if successful test, -1 if failure

LcFHandle lcopen( const char *path ) {
    return( 0 ); // Likely wrong
} 

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcread
// Description  : Read data from the file 
//
// Inputs       : fh - file handle for the file to read from
//                buf - place to put the data
//                len - the length of the read
// Outputs      : number of bytes read, -1 if failure
int lcread( LcFHandle fh, char *buf, size_t len ) {
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcwrite
// Description  : write data to the file
//
// Inputs       : fh - file handle for the file to write to
//                buf - pointer to data to write
//                len - the length of the write
// Outputs      : number of bytes written if successful test, -1 if failure

int lcwrite( LcFHandle fh, char *buf, size_t len ) {
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcseek
// Description  : Seek to a specific place in the file
//
// Inputs       : fh - the file handle of the file to seek in
//                off - offset within the file to seek to
// Outputs      : 0 if successful test, -1 if failure

int lcseek( LcFHandle fh, size_t off ) {
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcclose
// Description  : Close the file
//
// Inputs       : fh - the file handle of the file to close
// Outputs      : 0 if successful test, -1 if failure

int lcclose( LcFHandle fh ) {
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcshutdown
// Description  : Shut down the filesystem
//
// Inputs       : none
// Outputs      : 0 if successful test, -1 if failure

int lcshutdown( void ) {

    return( 0 );
}
