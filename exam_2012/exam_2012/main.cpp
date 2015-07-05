/* 2012上机考试题 */
/* 2014-11-05 10:56 PM */
#include "outmap.h"
#include "outshf.h"
#include "outred.h"

int main() {
	char* datafile = "data.txt";
	char* mapfile = outmap(datafile);
	char* shffile = outshf(mapfile);
	char* redfile = outred(shffile);
	/* 写完才发现2、3步可以合在一块做( ╯□╰ ) */
}