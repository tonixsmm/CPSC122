#include "PA6.h"

int main() {
	// runMusicManager();
	Song testSong1("cardigan", "taylor swift", "indie", 5);
	Song testSong2("mirrorball", "taylor swift", "indie", 5);
	Song testSong3("lover", "taylor swift", "pop", 5);
	Song testSong4("willow", "taylor swift", "indie folk", 5);
	SongLibrary lib;

	lib.performInsertSongInOrder(&testSong1);
	lib.performInsertSongInOrder(&testSong2);
	lib.performInsertSongInOrder(&testSong3);
	lib.performInsertSongInOrder(&testSong4);

	cout << "--------" << endl;

	SongLibrary lib2(lib);

	lib2.displayLibrary();

	return 0;
}
