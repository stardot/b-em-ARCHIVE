/* B-em */
/*
 * Standard wrappers around system calls,
 */

#include "compat_wrappers.h"

FILE *
x_fopen(const char *path, const char *mode)
{
	/* Check to see if the path exists.  If it does, return the resultant
	 * FILE * pointer, otherwise bail out.
	 */

	FILE	*fp = NULL;
	char	*err;

	if (path == NULL || path[0] == '\0')
		return (NULL);

	if ((fp = fopen(path, mode)) == NULL) {
		if ((asprintf(&err, "Failed to load '%s' - %s\n", path,
			strerror(errno))) == -1) {

			exit(-1);
		}
		bem_error(err);
		free(err);
		exit(-1);
	}

	return (fp);
}
