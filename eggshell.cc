#include <glib.h>
#include "eggshell.hh"

/**
 * egg_shell:
 * @shell: the value of the SHELL env variable
 *
 * Retrieves the user's preferred shell.
 *
 * Returns: A newly allocated string that is the path to the shell.
 */
char *
egg_shell (const char *shell)
{
	auto snapdir = g_getenv("SNAP");
	if (snapdir == nullptr) {
		return nullptr;
	}

	return g_strdup_printf("%s/lxd-terminal-run", snapdir);
}
