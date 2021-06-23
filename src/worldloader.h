#ifndef WORLDLOADER_H_
#define WORLDLOADER_H_

#include "./chunk.h"
#include "./helper.h"
#include <filesystem>
#include <map.hpp>
#include <nbt/nbt.hpp>

namespace Terrain {

struct Data {
  using Chunk = mcmap::Chunk;
  using ChunkCoordinates = mcmap::Chunk::coordinates;
  using ChunkStore = std::map<ChunkCoordinates, Chunk>;

  // The loaded chunks, organized as a map of coordinatesxchunk
  ChunkStore chunks;

  fs::path regionDir;
  const Colors::Palette &palette;

  // Default constructor
  explicit Data(const std::filesystem::path &dir, const Colors::Palette &p)
      : regionDir(dir), palette(p) {}

  // Chunk pre-processing methods
  void stripChunk(std::vector<nbt::NBT> *);
  void inflateChunk(std::vector<nbt::NBT> *);

  // Chunk loading - should never be used, called by chunkAt in case of chunk
  // fault
  void loadChunk(const ChunkCoordinates);

  // Access a chunk from the save file
  const Chunk &chunkAt(const ChunkCoordinates, const Map::Orientation, bool);

  // Mark a chunk as done and ready for deletion
  void free_chunk(const ChunkCoordinates);
};

} // namespace Terrain

#endif // WORLDLOADER_H_
