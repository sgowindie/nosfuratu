//
//  MainAssetsMapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 11/9/16.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "MainAssetsMapper.h"

#include "Assets.h"
#include "TextureRegion.h"
#include "Animation.h"
#include "GameConstants.h"

MainAssetsMapper::MainAssetsMapper() : IAssetsMapper()
{
    // Empty
}

MainAssetsMapper::~MainAssetsMapper()
{
    // Empty
}

void MainAssetsMapper::mapAssets()
{
    /// Texture Regions
    ASSETS->getTextureRegionMap()["CutsceneEffectType_Shadow_One"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_2, 0, 0, 966, 504, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutsceneEffectType_Shadow_Two"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_2, 0, 508, 1600, 760, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_One"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 0, 0, 1600, 1200, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Two"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 0, 1204, 1600, 900, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Three"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 0, 2108, 1600, 900, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Four"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 1604, 0, 1600, 900, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Five"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 0, 3012, 1600, 900, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Six"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 1604, 904, 1600, 1200, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CutscenePanelType_Opening_Seven"] = new TextureRegion(TEX_WORLD_1_CUTSCENE_1, 1604, 2108, 1600, 900, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["WorldMapPanel"] = new TextureRegion(TEX_WORLD_MAP_1, 0, 0, 1088, 612, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["AbilitySlot_Locked"] = new TextureRegion(TEX_WORLD_MAP_2, 0, 458, 118, 114, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BossLevelThumbnail_Cleared"] = new TextureRegion(TEX_WORLD_MAP_2, 0, 1832, 198, 204, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BossLevelThumbnail_Unlocked"] = new TextureRegion(TEX_WORLD_MAP_2, 198, 1420, 198, 204, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BossLevelThumbnail_Locked"] = new TextureRegion(TEX_WORLD_MAP_2, 990, 1008, 198, 204, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["NormalLevelThumbnail_Cleared"] = new TextureRegion(TEX_WORLD_MAP_2, 0, 330, 124, 124, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["NormalLevelThumbnail_Playable"] = new TextureRegion(TEX_WORLD_MAP_2, 124, 78, 124, 124, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["NormalLevelThumbnail_Unplayable"] = new TextureRegion(TEX_WORLD_MAP_2, 0, 78, 124, 124, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Upper"] = new TextureRegion(TEX_WORLD_1_BG_UPPER, 0, 0, PIXEL_WIDTH_FOR_GAME, 1536, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Mid_Hills"] = new TextureRegion(TEX_WORLD_1_BG_MID, 0, 0, PIXEL_WIDTH_FOR_GAME, 804, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Mid_Trees"] = new TextureRegion(TEX_WORLD_1_BG_MID, 0, 1312, PIXEL_WIDTH_FOR_GAME, 736, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Lower_Top"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_1, 0, 96, PIXEL_WIDTH_FOR_GAME, 980, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Lower_Bottom"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_1, 0, 1524, PIXEL_WIDTH_FOR_GAME, 524, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Lower_Inner"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_2, 0, 160, PIXEL_WIDTH_FOR_GAME, 944, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_Lower_Innermost"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_2, 0, 1104, PIXEL_WIDTH_FOR_GAME, 944, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_WaterBack"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_2, 0, 18, PIXEL_WIDTH_FOR_GAME, 64, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["BackgroundType_WaterFront"] = new TextureRegion(TEX_WORLD_1_BG_LOWER_2, 0, 98, PIXEL_WIDTH_FOR_GAME, 48, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["MidgroundType_TreeOne"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1664, 0, 992, 864, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_TreeTwo"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2694, 0, 1120, 800, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_TreeThree"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1404, 904, 288, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_DeepCaveColumnSmall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3136, 1824, 96, 288, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_DeepCaveColumnMedium"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3968, 1280, 128, 832, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_DeepCaveColumnBig"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3394, 1280, 256, 832, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Plant"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1714, 914, 304, 320, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Metal_Tower_Section"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 1108, 128, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Billboard_Count_Hiss"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 0, 768, 448, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Billboard_Slag_Town"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 448, 768, 448, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Billboard_Jon_Wanted"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 768, 448, 768, 448, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Hill"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 928, 1376, 176, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Train_Car"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 24, 3186, 1568, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Short_Stump"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 604, 1128, 192, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Tall_Stump"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3056, 948, 128, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Thin_Tall_Tree"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3056, 1158, 192, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Thin_Short_Tree"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3266, 870, 256, 320, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Stone_Square"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1298, 3688, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Stone_Diamond"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1698, 3688, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Wall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1028, 3838, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_Roof"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 1028, 3774, 256, 64, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_DiagonalChain"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2738, 3252, 128, 832, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["MidgroundType_StraightChain"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2920, 3252, 48, 832, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveExtraDeepEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 1132, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveExtraDeepSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 1132, 512, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveExtraDeepMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 1132, 1024, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveExtraDeepLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 1132, 2048, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveExtraDeepEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 1132, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveDeepEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 1264, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveDeepSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 1264, 512, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveDeepMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 1264, 1024, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveDeepLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 1264, 2048, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveDeepEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 1264, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 1912, 128, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 1912, 512, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 1912, 1024, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 1912, 2048, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 1912, 128, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveRaisedEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 1396, 128, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveRaisedSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 1396, 512, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveRaisedMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 1396, 1024, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveRaisedLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 1396, 2048, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_CaveRaisedEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 1396, 128, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithCaveEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 2300, 128, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithCaveSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 2300, 512, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithCaveMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 2300, 1024, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithCaveLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 2300, 2048, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithCaveEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 2300, 128, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithoutCaveEndLeft"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 2496, 128, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithoutCaveSmall"] = new TextureRegion(TEX_WORLD_1_GROUND, 128, 2496, 512, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithoutCaveMedium"] = new TextureRegion(TEX_WORLD_1_GROUND, 640, 2496, 1024, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithoutCaveLarge"] = new TextureRegion(TEX_WORLD_1_GROUND, 1664, 2496, 2048, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassWithoutCaveEndRight"] = new TextureRegion(TEX_WORLD_1_GROUND, 3712, 2496, 128, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassPitSmall"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 2208, 880, 512, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassPitMedium"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 2954, 880, 1024, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassPitLarge"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 0, 880, 2048, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_GrassPitExtraLarge"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 0, 2496, 4096, 1600, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ExitGroundType_GrassWithCaveSmallExitMid"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 0, 512, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ExitGroundType_GrassWithCaveSmallExitEnd"] = new TextureRegion(TEX_WORLD_1_GROUND, 3500, 228, 512, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ExitGroundType_CaveSmallExit"] = new TextureRegion(TEX_WORLD_1_GROUND, 0, 228, 512, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["HoleType_GrassTileLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 1400, 256, 368, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["HoleType_GrassTileCenter"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 1772, 256, 368, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["HoleType_GrassTileRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 2144, 256, 368, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["HoleType_Grass"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 2528, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["HoleType_Cave"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 2788, 272, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GrassPlatformLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2000, 600, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GrassPlatformCenter"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2064, 600, 224, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GrassPlatformRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2288, 600, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_CavePlatformLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2378, 600, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_CavePlatformCenter"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2442, 600, 224, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_CavePlatformRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2666, 600, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_RockLarge"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 0, 28, 704, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_RockMedium"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 0, 684, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_RockSmall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3624, 2158, 384, 368, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_StumpBig"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 388, 696, 256, 288, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_StumpSmall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 0, 1080, 320, 272, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_EndSign"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 704, 688, 112, 160, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_ThornsLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1156, 1196, 80, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_ThornsCenterSmall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1588, 1196, 176, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_ThornsCenterBig"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1236, 1196, 352, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_ThornsRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1764, 1196, 80, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_LogVerticalTall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 452, 1004, 128, 176, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_LogVerticalShort"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 452, 1190, 128, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeGrassSingle"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1904, 900, 96, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeGrassFour"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2000, 900, 288, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeGrassEight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2288, 900, 544, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveSingle"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1904, 1108, 96, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveFour"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2000, 1108, 288, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveEight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2288, 1108, 544, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveCeilingSingle"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1904, 1004, 96, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveCeilingFour"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2000, 1004, 288, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeCaveCeilingEight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2288, 1004, 544, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeWallSingle"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 4000, 3140, 96, 64, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeWallFour"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 4000, 3824, 96, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeWallEight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 4000, 3248, 96, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeStar"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 890, 1162, 224, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GiantTree"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 832, 0, 1088, 1040, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GiantPerchTree"] = new TextureRegion(TEX_WORLD_1_MID_BOSS_3, 3008, 2080, 1088, 1040, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeTower"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3062, 3200, 512, 896, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikeTowerBg"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3578, 3200, 512, 896, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikedBallRolling"] = new TextureRegion(TEX_WORLD_1_END_BOSS_1, 3440, 2104, 512, 480, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_SpikedBall"] = new TextureRegion(TEX_WORLD_1_END_BOSS_1, 3440, 2588, 512, 480, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["SnakeBody_Left"] = new TextureRegion(TEX_WORLD_1_END_BOSS_1, 0, 548, 3488, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["SnakeBody_Right"] = new TextureRegion(TEX_WORLD_1_END_BOSS_2, 0, 1640, 3488, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EndBossSnakeState_Sleeping_Awakening"] = new TextureRegion(TEX_WORLD_1_END_BOSS_1, 0, 0, 864, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EndBossSnakeState_OpenMouthLeft_ChargingLeft"] = new TextureRegion(TEX_WORLD_1_END_BOSS_1, 1728, 0, 864, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EndBossSnakeState_Pursuing_Waiting_Damaged"] = new TextureRegion(TEX_WORLD_1_END_BOSS_2, 0, 0, 864, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EndBossSnakeState_OpenMouthRight_ChargingRight"] = new TextureRegion(TEX_WORLD_1_END_BOSS_2, 1728, 0, 864, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EndBossSnakeState_DeadSpiritReleasing_Dead"] = new TextureRegion(TEX_WORLD_1_END_BOSS_3, 2592, 2720, 864, 544, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CollectibleItemType_Carrot_Not_Collected"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 0, 3204, 218, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CollectibleItemType_GoldenCarrot_Previously_Collected"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2286, 3204, 254, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CollectibleItemType_GoldenCarrot_Not_Collected"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2032, 3204, 254, 224, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["CollectibleItemType_BigCarrot_Not_Collected"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3028, 248, 432, 432, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameButtonType_ToggleMusic"] = new TextureRegion(TEX_WORLD_MAP_1, 1626, 1774, 128, 128, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_ToggleSound"] = new TextureRegion(TEX_WORLD_MAP_1, 1626, 1906, 128, 128, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_BackToTitle"] = new TextureRegion(TEX_WORLD_MAP_1, 1800, 0, 104, 104, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_GameController"] = new TextureRegion(TEX_WORLD_MAP_1, 1908, 8, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_GameControllerAlt"] = new TextureRegion(TEX_WORLD_MAP_1, 1840, 128, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_Achievements"] = new TextureRegion(TEX_WORLD_MAP_1, 1736, 224, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_Leaderboards"] = new TextureRegion(TEX_WORLD_MAP_1, 1736, 320, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_SignIn"] = new TextureRegion(TEX_WORLD_MAP_1, 1736, 416, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_SignOut"] = new TextureRegion(TEX_WORLD_MAP_1, 1840, 416, 88, 88, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_ViewOpeningCutscene"] = new TextureRegion(TEX_WORLD_MAP_1, 1152, 0, 96, 64, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameButtonType_BackToLevelSelect"] = new TextureRegion(TEX_MISC, 0, 0, 104, 104, TEXTURE_SIZE_1024);
    ASSETS->getTextureRegionMap()["GameButtonType_LevelEditor"] = new TextureRegion(TEX_TITLE, 800, 780, 190, 62, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["GameHudItem_Golden"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1904, 1254, 96, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameHudItem_Normal"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 884, 1054, 96, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameHudItem_Vial"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 128, 1536, 96, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["EditorEntitiesPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 0, 46, 592, 1338, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["EditorActionsPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 840, 46, 592, 1338, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["TrashCan_Highlighted"] = new TextureRegion(TEX_LEVEL_EDITOR, 128, 1454, 128, 128, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["TrashCan_Normal"] = new TextureRegion(TEX_LEVEL_EDITOR, 0, 1454, 128, 128, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["SelectorPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 1538, 12, 510, 510, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["OffsetPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 1538, 542, 510, 510, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["ConfirmResetPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 938, 1484, 510, 510, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["ConfirmExitPanel"] = new TextureRegion(TEX_LEVEL_EDITOR, 1538, 1072, 510, 510, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["CarrotCountMarker"] = new TextureRegion(TEX_MISC, 256, 0, 32, 32, TEXTURE_SIZE_1024);
    ASSETS->getTextureRegionMap()["ClockIcon"] = new TextureRegion(TEX_MISC, 512, 0, 72, 72, TEXTURE_SIZE_1024);
    ASSETS->getTextureRegionMap()["ResumeButton"] = new TextureRegion(TEX_VAMPIRE, 2048, 1792, 192, 192, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ComingSoonScreen"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 0, 2204, 1280, 720, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1680, 2204, 768, 592, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameButtonType_Replay"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2218, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel_Clock"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2304, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel_Carrot"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2384, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel_GoldenCarrot"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2464, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel_Vial"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2544, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["LevelCompletePanel_Enemy"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2500, 2624, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameButtonType_ContinueToLevelSelect"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2634, 2218, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GameButtonType_PostScore"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2634, 2628, 72, 72, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["SpeedBarFrame"] = new TextureRegion(TEX_MISC, 8, 654, 516, 20, TEXTURE_SIZE_1024);
    ASSETS->getTextureRegionMap()["SpeedBar"] = new TextureRegion(TEX_MISC, 8, 678, 516, 20, TEXTURE_SIZE_1024);
    ASSETS->getTextureRegionMap()["TitlePanel_Background"] = new TextureRegion(TEX_TITLE, 0, 0, 1280, 720, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["TitlePanel_Logo"] = new TextureRegion(TEX_TITLE, 1024, 1070, 874, 434, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["TitlePanel_Small_Cloud"] = new TextureRegion(TEX_TITLE, 0, 1940, 634, 94, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["TitlePanel_Big_Cloud"] = new TextureRegion(TEX_TITLE, 964, 1940, 1084, 108, TEXTURE_SIZE_2048);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Tree"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 3584, 2238, 448, 816, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Plant"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2234, 3456, 336, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Bush"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2452, 1154, 400, 240, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Ferns"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2452, 978, 528, 176, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_PassThrough"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 256, 3582, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Bottom_PassThrough"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 3838, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Window_PassThrough"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 0, 3582, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Window_Bottom_PassThrough"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 256, 3838, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 768, 3582, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Bottom"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 512, 3838, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Window"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 512, 3582, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Wall_Window_Bottom"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 768, 3838, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Roof_Side_Left"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2142, 3914, 256, 64, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Roof_Side_Right"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2398, 3914, 256, 64, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Roof_Plain"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2142, 3986, 256, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundCoverObjectType_Roof_Chimney"] = new TextureRegion(TEX_WORLD_1_OBJECTS_2, 2398, 3986, 256, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_MetalGrassPlatform"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2048, 474, 256, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_MetalGrassPlatformLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1984, 368, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_MetalGrassPlatformCenter"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2048, 368, 256, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_MetalGrassPlatformRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2304, 368, 64, 96, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_WoodPlatform"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2384, 498, 256, 64, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_WoodBoxTop"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2758, 344, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_WoodBox"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2758, 604, 256, 256, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GreenThornsLeft"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 1948, 0, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GreenThornsCenterSmall"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2460, 0, 192, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GreenThornsCenterBig"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2076, 0, 384, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_GreenThornsRight"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2652, 0, 128, 128, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Logs"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2464, 3744, 592, 160, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Stone_Bottom"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3078, 3698, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Stone_Middle"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3484, 3298, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Stone_Top"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3484, 3698, 448, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Stone_Platform"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3484, 3128, 448, 112, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Stone_Square"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 3084, 3284, 384, 384, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["ForegroundObjectType_Floating_Platform"] = new TextureRegion(TEX_WORLD_1_OBJECTS_1, 2384, 284, 320, 176, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_PitTunnelLeft"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 1284, 0, 384, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_PitTunnelCenter"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 1668, 0, 512, 512, TEXTURE_SIZE_4096);
    ASSETS->getTextureRegionMap()["GroundType_PitTunnelRight"] = new TextureRegion(TEX_WORLD_1_SPECIAL, 2180, 0, 384, 512, TEXTURE_SIZE_4096);
    
    /// Animations
    ASSETS->getAnimationsMap()["CutsceneEffectType_POW"] = new Animation(TEX_WORLD_1_CUTSCENE_2, 0, 1270, 1952, 1412, 3904, 2824, TEXTURE_SIZE_4096, false, 0.20f, 3);
    ASSETS->getAnimationsMap()["AbilitySlot_Unlocking"] = new Animation(TEX_WORLD_MAP_2, 0, 458, 118, 114, 1180, 114, TEXTURE_SIZE_2048, false, 0.10f, 10);
    ASSETS->getAnimationsMap()["AbilitySlotType_Drill"] = new Animation(TEX_WORLD_MAP_2, 0, 572, 118, 114, 1298, 114, TEXTURE_SIZE_2048, false, 0.10f, 11);
    ASSETS->getAnimationsMap()["AbilitySlotType_Dash"] = new Animation(TEX_WORLD_MAP_2, 0, 686, 118, 114, 1298, 114, TEXTURE_SIZE_2048, false, 0.10f, 11);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Unlocking"] = new Animation(TEX_WORLD_MAP_2, 0, 804, 198, 204, 1980, 408, TEXTURE_SIZE_2048, false, 0.10f, 13);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Selected_Cleared"] = new Animation(TEX_WORLD_MAP_2, 198, 1832, 198, 204, 1782, 204, TEXTURE_SIZE_2048, true, 0.10f, 9);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Selected"] = new Animation(TEX_WORLD_MAP_2, 0, 1216, 198, 204, 1782, 204, TEXTURE_SIZE_2048, true, 0.10f, 9);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Selecting_Cleared"] = new Animation(TEX_WORLD_MAP_2, 1386, 1628, 198, 204, 792, 204, TEXTURE_SIZE_2048, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Selecting"] = new Animation(TEX_WORLD_MAP_2, 198, 1420, 198, 204, 594, 204, TEXTURE_SIZE_2048, false, 0.10f, 3);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Clearing"] = new Animation(TEX_WORLD_MAP_2, 0, 1628, 198, 204, 1386, 204, TEXTURE_SIZE_2048, false, 0.10f, 7);
    ASSETS->getAnimationsMap()["BossLevelThumbnail_Locked_Jaw_Moving"] = new Animation(TEX_WORLD_MAP_2, 990, 1008, 198, 204, 990, 204, TEXTURE_SIZE_2048, true, 0.10f, 5, 3);
    ASSETS->getAnimationsMap()["NormalLevelThumbnail_Selected_Cleared"] = new Animation(TEX_WORLD_MAP_2, 744, 330, 124, 124, 1240, 124, TEXTURE_SIZE_2048, true, 0.10f, 10);
    ASSETS->getAnimationsMap()["NormalLevelThumbnail_Selected"] = new Animation(TEX_WORLD_MAP_2, 868, 78, 124, 124, 1116, 124, TEXTURE_SIZE_2048, true, 0.10f, 9);
    ASSETS->getAnimationsMap()["NormalLevelThumbnail_Selecting_Cleared"] = new Animation(TEX_WORLD_MAP_2, 0, 330, 124, 124, 744, 124, TEXTURE_SIZE_2048, false, 0.10f, 6);
    ASSETS->getAnimationsMap()["NormalLevelThumbnail_Selecting"] = new Animation(TEX_WORLD_MAP_2, 124, 78, 124, 124, 744, 124, TEXTURE_SIZE_2048, false, 0.10f, 6);
    ASSETS->getAnimationsMap()["NormalLevelThumbnail_Clearing"] = new Animation(TEX_WORLD_MAP_2, 0, 206, 124, 124, 1364, 124, TEXTURE_SIZE_2048, false, 0.10f, 11);
    ASSETS->getAnimationsMap()["GoldenCarrotsMarker_0"] = new Animation(TEX_WORLD_MAP_2, 0, 0, 118, 74, 944, 74, TEXTURE_SIZE_2048, false, 0.10f, 8);
    ASSETS->getAnimationsMap()["GoldenCarrotsMarker_1"] = new Animation(TEX_WORLD_MAP_2, 0, 0, 118, 74, 1062, 74, TEXTURE_SIZE_2048, false, 0.10f, 9);
    ASSETS->getAnimationsMap()["GoldenCarrotsMarker_2"] = new Animation(TEX_WORLD_MAP_2, 0, 0, 118, 74, 1180, 74, TEXTURE_SIZE_2048, false, 0.10f, 10);
    ASSETS->getAnimationsMap()["GoldenCarrotsMarker_3"] = new Animation(TEX_WORLD_MAP_2, 0, 0, 118, 74, 1298, 74, TEXTURE_SIZE_2048, false, 0.10f, 11);
    ASSETS->getAnimationsMap()["GoldenCarrotsMarker_4"] = new Animation(TEX_WORLD_MAP_2, 0, 0, 118, 74, 1416, 74, TEXTURE_SIZE_2048, false, 0.10f, 12);
    ASSETS->getAnimationsMap()["SpendGoldenCarrotsBubble_Has_Enough"] = new Animation(TEX_WORLD_MAP_1, 0, 748, 234, 184, 1872, 552, TEXTURE_SIZE_2048, true, 0.10f, 21, 3);
    ASSETS->getAnimationsMap()["SpendGoldenCarrotsBubble_Not_Enough"] = new Animation(TEX_WORLD_MAP_1, 0, 1304, 234, 184, 1872, 552, TEXTURE_SIZE_2048, true, 0.10f, 21, 3);
    ASSETS->getAnimationsMap()["ExitGroundType_CaveDeepSmallWaterfall"] = new Animation(TEX_WORLD_1_GROUND, 0, 616, 512, 448, 1536, 448, TEXTURE_SIZE_4096, true, 0.10f, 3);
    ASSETS->getAnimationsMap()["ExitGroundCoverType_Grass"] = new Animation(TEX_WORLD_1_GROUND, 1024, 0, 512, 224, 3072, 224, TEXTURE_SIZE_4096, false, 0.08333333333333f, 6);
    ASSETS->getAnimationsMap()["ExitGroundCoverType_Cave"] = new Animation(TEX_WORLD_1_GROUND, 514, 228, 512, 384, 2560, 384, TEXTURE_SIZE_4096, false, 0.10f, 5);
    ASSETS->getAnimationsMap()["HoleCoverType_GrassTileLeft"] = new Animation(TEX_WORLD_1_OBJECTS_2, 256, 1400, 256, 368, 2560, 368, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["HoleCoverType_GrassTileCenter"] = new Animation(TEX_WORLD_1_OBJECTS_2, 256, 1772, 256, 368, 2560, 368, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["HoleCoverType_GrassTileRight"] = new Animation(TEX_WORLD_1_OBJECTS_2, 256, 2144, 256, 368, 2560, 368, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["HoleCoverType_Grass"] = new Animation(TEX_WORLD_1_OBJECTS_2, 256, 2528, 256, 256, 3072, 256, TEXTURE_SIZE_4096, false, 0.04166666666667f, 12);
    ASSETS->getAnimationsMap()["HoleCoverType_Cave"] = new Animation(TEX_WORLD_1_OBJECTS_2, 272, 2788, 272, 384, 2720, 384, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["ForegroundObjectType_RockSmallCracked"] = new Animation(TEX_WORLD_1_OBJECTS_1, 384, 3236, 384, 368, 2304, 368, TEXTURE_SIZE_4096, false, 0.05f, 6);
    ASSETS->getAnimationsMap()["ForegroundObjectType_JumpSpringLightFlush"] = new Animation(TEX_WORLD_1_OBJECTS_1, 2904, 1804, 160, 112, 1120, 112, TEXTURE_SIZE_4096, false, 0.05142857142857f, 7);
    ASSETS->getAnimationsMap()["ForegroundObjectType_JumpSpringLightFlushNew"] = new Animation(TEX_WORLD_1_OBJECTS_1, 2878, 2218, 176, 176, 528, 528, TEXTURE_SIZE_4096, false, 0.05142857142857f, 7);
    ASSETS->getAnimationsMap()["ForegroundObjectType_JumpSpringLight"] = new Animation(TEX_WORLD_1_OBJECTS_1, 2126, 3960, 96, 80, 480, 80, TEXTURE_SIZE_4096, false, 0.09f, 4);
    ASSETS->getAnimationsMap()["ForegroundObjectType_JumpSpringMedium"] = new Animation(TEX_WORLD_1_OBJECTS_1, 0, 3668, 272, 144, 1904, 144, TEXTURE_SIZE_4096, false, 0.05142857142857, 7);
    ASSETS->getAnimationsMap()["ForegroundObjectType_JumpSpringHeavy"] = new Animation(TEX_WORLD_1_OBJECTS_1, 272, 3816, 272, 224, 1904, 224, TEXTURE_SIZE_4096, false, 0.06f, 6);
    ASSETS->getAnimationsMap()["ForegroundObjectType_VerticalSaw"] = new Animation(TEX_WORLD_1_OBJECTS_1, 3590, 2556, 240, 528, 480, 528, TEXTURE_SIZE_4096, true, 0.05f, 2);
    ASSETS->getAnimationsMap()["ForegroundObjectType_GiantShakingTree"] = new Animation(TEX_WORLD_1_OBJECTS_1, 832, 0, 1088, 1040, 3264, 3120, TEXTURE_SIZE_4096, false, 0.025f, 7);
    ASSETS->getAnimationsMap()["ForegroundObjectType_SpikedBallChain"] = new Animation(TEX_WORLD_1_END_BOSS_1, 0, 1472, 1616, 1312, 3232, 2624, TEXTURE_SIZE_4096, false, 0.10f, 3);
    ASSETS->getAnimationsMap()["CountHissWithMina_Left"] = new Animation(TEX_WORLD_1_END_BOSS_1, 2048, 3072, 512, 512, 2048, 1024, TEXTURE_SIZE_4096, true, 0.08f, 6);
    ASSETS->getAnimationsMap()["CountHissWithMina_Right"] = new Animation(TEX_JON, 2048, 3072, 512, 512, 2048, 1024, TEXTURE_SIZE_4096, true, 0.08f, 7);
    ASSETS->getAnimationsMap()["SnakeSpirit"] = new Animation(TEX_WORLD_1_END_BOSS_2, 0, 2188, 820, 360, 3280, 1080, TEXTURE_SIZE_4096, false, 0.10f, 12);
    ASSETS->getAnimationsMap()["SnakeHeadImpact"] = new Animation(TEX_WORLD_1_END_BOSS_2, 0, 3584, 512, 512, 4096, 512, TEXTURE_SIZE_4096, false, 0.10f, 8);
    ASSETS->getAnimationsMap()["SnakeSkin"] = new Animation(TEX_WORLD_1_END_BOSS_2, 0, 548, 864, 544, 3456, 1088, TEXTURE_SIZE_4096, false, 0.10f, 7);
    ASSETS->getAnimationsMap()["SnakeEye"] = new Animation(TEX_WORLD_1_END_BOSS_1, 2756, 304, 118, 118, 354, 118, TEXTURE_SIZE_4096, false, 0.10f, 3);
    ASSETS->getAnimationsMap()["SnakeTonque_Left"] = new Animation(TEX_WORLD_1_END_BOSS_1, 2596, 0, 554, 78, 1108, 234, TEXTURE_SIZE_4096, true, 0.10f, 5, 3);
    ASSETS->getAnimationsMap()["SnakeTonque_Right"] = new Animation(TEX_WORLD_1_END_BOSS_2, 2792, 0, 554, 78, 1108, 234, TEXTURE_SIZE_4096, true, 0.10f, 5, 3);
    ASSETS->getAnimationsMap()["EndBossSnakeState_OpeningMouthLeft"] = new Animation(TEX_WORLD_1_END_BOSS_1, 0, 0, 864, 544, 2592, 544, TEXTURE_SIZE_4096, false, 0.10f, 3);
    ASSETS->getAnimationsMap()["EndBossSnakeState_OpeningMouthRight"] = new Animation(TEX_WORLD_1_END_BOSS_2, 0, 0, 864, 544, 2592, 544, TEXTURE_SIZE_4096, false, 0.10f, 3);
    {
        Animation* anim = new Animation(TEX_WORLD_1_END_BOSS_3, 0, 0, 864, 544, 3456, 3264, TEXTURE_SIZE_4096, false, 24);
        anim->setFrameTimes(24, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
        ASSETS->getAnimationsMap()["EndBossSnakeState_Dying"] = anim;
    }
    ASSETS->getAnimationsMap()["EnemyType_MushroomGround"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 0, 112, 128, 448, 128, TEXTURE_SIZE_4096, false, 0.12f, 4);
    ASSETS->getAnimationsMap()["EnemyType_MushroomCeiling"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 132, 112, 128, 448, 128, TEXTURE_SIZE_4096, false, 0.12f, 4);
    ASSETS->getAnimationsMap()["EnemyType_SnakeGrunt"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 332, 128, 96, 512, 96, TEXTURE_SIZE_4096, true, 0.08f, 4);
    ASSETS->getAnimationsMap()["EnemyType_Sparrow"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 692, 160, 160, 1120, 160, TEXTURE_SIZE_4096, true, 0.08f, 7);
    ASSETS->getAnimationsMap()["EnemyType_Toad_Dead_Part_1_Jon_Is_Vampire"] = new Animation(TEX_WORLD_1_ENEMIES, 1024, 2144, 512, 256, 1024, 256, TEXTURE_SIZE_4096, false, 0.05f, 2);
    ASSETS->getAnimationsMap()["EnemyType_Toad_Dead_Part_1_Jon_Is_Rabbit"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 1888, 512, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.05f, 5);
    ASSETS->getAnimationsMap()["EnemyType_Toad_Dead_Part_2"] = new Animation(TEX_WORLD_1_ENEMIES, 2048, 1888, 512, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.05f, 7);
    ASSETS->getAnimationsMap()["EnemyType_Toad_Eating_Jon_Is_Vampire"] = new Animation(TEX_WORLD_1_ENEMIES, 2048, 1372, 512, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.05f, 8);
    ASSETS->getAnimationsMap()["EnemyType_Toad_Eating_Jon_Is_Rabbit"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 1372, 512, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.05f, 8);
    ASSETS->getAnimationsMap()["EnemyType_Toad"] = new Animation(TEX_WORLD_1_ENEMIES, 492, 0, 512, 256, 3584, 256, TEXTURE_SIZE_4096, true, 0.15f, 7);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Is_Dead"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 2664, 256, 512, 2560, 512, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Is_Hitting_Left"] = new Animation(TEX_WORLD_1_ENEMIES, 2080, 260, 256, 256, 1792, 512, TEXTURE_SIZE_4096, false, 0.05f, 11);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Is_Hitting_Right"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 2404, 256, 256, 2816, 256, TEXTURE_SIZE_4096, false, 0.05f, 11);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Is_Being_Hit"] = new Animation(TEX_WORLD_1_ENEMIES, 3072, 2404, 256, 256, 768, 512, TEXTURE_SIZE_4096, false, 0.05f, 6);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Left"] = new Animation(TEX_WORLD_1_ENEMIES, 3104, 516, 256, 256, 768, 256, TEXTURE_SIZE_4096, false, 0.15f, 3);
    ASSETS->getAnimationsMap()["EnemyType_Fox_Right"] = new Animation(TEX_WORLD_1_ENEMIES, 3104, 772, 256, 256, 768, 256, TEXTURE_SIZE_4096, false, 0.15f, 3);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomGround_Bouncing_Back"] = new Animation(TEX_WORLD_1_ENEMIES, 2560, 3298, 256, 208, 1024, 208, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomGround_Bouncing_On"] = new Animation(TEX_WORLD_1_ENEMIES, 1536, 3298, 256, 208, 1024, 208, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomGround"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 3298, 256, 208, 1536, 208, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomCeiling_Bouncing_Back"] = new Animation(TEX_WORLD_1_ENEMIES, 2560, 3510, 256, 208, 1024, 208, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomCeiling_Bouncing_On"] = new Animation(TEX_WORLD_1_ENEMIES, 1536, 3510, 256, 208, 1024, 208, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["EnemyType_BigMushroomCeiling"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 3510, 256, 208, 1536, 208, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt_Jumping"] = new Animation(TEX_WORLD_1_ENEMIES, 768, 3850, 256, 128, 1024, 128, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt_Falling"] = new Animation(TEX_WORLD_1_ENEMIES, 1792, 3850, 256, 128, 512, 128, TEXTURE_SIZE_4096, false, 0.10f, 2);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt_About_To_Jump"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 3850, 256, 128, 768, 128, TEXTURE_SIZE_4096, false, 0.10f, 3);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt_Landing"] = new Animation(TEX_WORLD_1_ENEMIES, 2304, 3850, 256, 128, 1024, 128, TEXTURE_SIZE_4096, false, 0.10f, 4);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt_Pausing"] = new Animation(TEX_WORLD_1_ENEMIES, 1536, 3722, 256, 128, 1280, 128, TEXTURE_SIZE_4096, false, 0.10f, 5);
    ASSETS->getAnimationsMap()["MovingSnakeGrunt"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 3722, 256, 128, 1536, 128, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["EnemySpiritType_Snake"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 432, 208, 256, 2080, 256, TEXTURE_SIZE_4096, false, 0.05f, 10);
    ASSETS->getAnimationsMap()["EnemySpiritType_Sparrow"] = new Animation(TEX_WORLD_1_ENEMIES, 0, 856, 256, 512, 3072, 512, TEXTURE_SIZE_4096, false, 0.04166666666667f, 12);
    ASSETS->getAnimationsMap()["CollectibleItemType_Carrot_Collected"] = new Animation(TEX_WORLD_1_OBJECTS_1, 0, 3204, 218, 224, 1744, 224, TEXTURE_SIZE_4096, false, 0.05f, 8);
    ASSETS->getAnimationsMap()["CollectibleItemType_GoldenCarrot_Collected"] = new Animation(TEX_WORLD_1_OBJECTS_1, 0, 3432, 254, 224, 2794, 224, TEXTURE_SIZE_4096, false, 0.05f, 11);
    ASSETS->getAnimationsMap()["CollectibleItemType_BigCarrot_Collected"] = new Animation(TEX_WORLD_1_OBJECTS_1, 3028, 248, 432, 432, 864, 1296, TEXTURE_SIZE_4096, false, 0.08f, 6);
    ASSETS->getAnimationsMap()["CollectibleItemType_Vial_Not_Collected"] = new Animation(TEX_WORLD_1_OBJECTS_1, 0, 1406, 320, 336, 2240, 336, TEXTURE_SIZE_4096, true, 0.06f, 7);
    ASSETS->getAnimationsMap()["CollectibleItemType_Vial_Collected"] = new Animation(TEX_WORLD_1_OBJECTS_1, 0, 1742, 320, 336, 2880, 336, TEXTURE_SIZE_4096, false, 0.06f, 9);
    ASSETS->getAnimationsMap()["GoldenCarrotTwinkle"] = new Animation(TEX_WORLD_1_OBJECTS_1, 3004, 2004, 74, 78, 518, 78, TEXTURE_SIZE_4096, true, 0.10f, 7);
    {
        Animation* anim = new Animation(TEX_VAMPIRE, 2048, 2048, 256, 256, 2048, 768, TEXTURE_SIZE_4096, false, 19);
        anim->setFrameTimes(19, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
        ASSETS->getAnimationsMap()["Jon_isTransformingIntoVampire"] = anim;
    }
    {
        Animation* anim = new Animation(TEX_VAMPIRE, 2048, 2816, 256, 256, 2048, 768, TEXTURE_SIZE_4096, false, 19);
        anim->setFrameTimes(19, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
        ASSETS->getAnimationsMap()["Jon_isRevertingToRabbit"] = anim;
    }
    ASSETS->getAnimationsMap()["Jon_Vampire_Death"] = new Animation(TEX_VAMPIRE, 2048, 3584, 256, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.06666666666667f, 15);
    ASSETS->getAnimationsMap()["Jon_Vampire_PushedBack"] = new Animation(TEX_VAMPIRE, 512, 256, 256, 256, 1536, 256, TEXTURE_SIZE_4096, false, 0.06f, 6);
    ASSETS->getAnimationsMap()["Jon_Vampire_Idle"] = new Animation(TEX_VAMPIRE, 0, 1792, 256, 256, 2048, 256, TEXTURE_SIZE_4096, true, 0.125f, 8);
    ASSETS->getAnimationsMap()["Jon_Vampire_Running"] = new Animation(TEX_VAMPIRE, 0, 0, 256, 256, 2048, 512, TEXTURE_SIZE_4096, true, 0.05f, 10);
    ASSETS->getAnimationsMap()["Jon_Vampire_UpwardThrust"] = new Animation(TEX_VAMPIRE, 0, 3072, 256, 512, 1536, 1024, TEXTURE_SIZE_4096, false, 0.031f, 11);
    {
        Animation* anim = new Animation(TEX_VAMPIRE, 768, 512, 768, 256, 3072, 1024, TEXTURE_SIZE_4096, false, 14);
        anim->setFrameTimes(14, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.20f, 0.1f);
        ASSETS->getAnimationsMap()["Jon_Vampire_Dash"] = anim;
    }
    ASSETS->getAnimationsMap()["Jon_Vampire_DoubleJumping"] = new Animation(TEX_VAMPIRE, 0, 512, 256, 256, 768, 512, TEXTURE_SIZE_4096, false, 0.09f, 6);
    ASSETS->getAnimationsMap()["Jon_Vampire_Gliding"] = new Animation(TEX_VAMPIRE, 0, 1024, 256, 256, 512, 256, TEXTURE_SIZE_4096, true, 0.06f, 2);
    ASSETS->getAnimationsMap()["Jon_Vampire_Falling"] = new Animation(TEX_VAMPIRE, 0, 1280, 256, 256, 2048, 256, TEXTURE_SIZE_4096, true, 0.06f, 3);
    ASSETS->getAnimationsMap()["Jon_Vampire_Landing"] = new Animation(TEX_VAMPIRE, 0, 1536, 256, 256, 2048, 256, TEXTURE_SIZE_4096, false, 0.066f, 3);
    ASSETS->getAnimationsMap()["Jon_Vampire_LedgeGrab"] = new Animation(TEX_VAMPIRE, 2048, 0, 256, 256, 1280, 256, TEXTURE_SIZE_4096, false, 0.06f, 5);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Death"] = new Animation(TEX_JON, 0, 3072, 256, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.10f, 10);
    ASSETS->getAnimationsMap()["Jon_Rabbit_WarmUp"] = new Animation(TEX_JON, 0, 2048, 256, 256, 2048, 1024, TEXTURE_SIZE_4096, true, 0.10f, 28);
    ASSETS->getAnimationsMap()["Jon_Rabbit_PushedBack"] = new Animation(TEX_JON, 512, 1024, 256, 256, 1536, 256, TEXTURE_SIZE_4096, false, 0.07f, 6);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Idle"] = new Animation(TEX_JON, 0, 1792, 256, 256, 1536, 256, TEXTURE_SIZE_4096, true, 0.10f, 6, 2);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Running"] = new Animation(TEX_JON, 0, 0, 256, 256, 2048, 512, TEXTURE_SIZE_4096, true, 0.05f, 12);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Jumping"] = new Animation(TEX_JON, 0, 512, 256, 256, 2048, 256, TEXTURE_SIZE_4096, false, 0.09f, 7);
    ASSETS->getAnimationsMap()["Jon_Rabbit_DoubleJumping"] = new Animation(TEX_JON, 0, 768, 256, 256, 2048, 512, TEXTURE_SIZE_4096, false, 0.07f, 9);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Falling"] = new Animation(TEX_JON, 0, 1280, 256, 256, 2048, 256, TEXTURE_SIZE_4096, true, 0.06f, 3);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Landing"] = new Animation(TEX_JON, 0, 1536, 256, 256, 2048, 256, TEXTURE_SIZE_4096, false, 0.05f, 4);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Burrow"] = new Animation(TEX_JON, 1792, 256, 256, 256, 2304, 256, TEXTURE_SIZE_4096, false, 0.06f, 9);
    ASSETS->getAnimationsMap()["Jon_Rabbit_Stomp"] = new Animation(TEX_JON, 2048, 1024, 256, 256, 2048, 512, TEXTURE_SIZE_4096, true, 0.05f, 11, 9);
    ASSETS->getAnimationsMap()["Jon_Rabbit_LandingRoll"] = new Animation(TEX_JON, 2816, 1280, 256, 256, 1280, 256, TEXTURE_SIZE_4096, false, 0.10f, 5);
    ASSETS->getAnimationsMap()["Jon_Rabbit_LedgeGrab"] = new Animation(TEX_JON, 2048, 2048, 256, 512, 2048, 1024, TEXTURE_SIZE_4096, false, 0.07f, 9);
    ASSETS->getAnimationsMap()["DustCloudType_Landing"] = new Animation(TEX_JON, 1100, 1644, 116, 60, 580, 60, TEXTURE_SIZE_4096, false, 0.08f, 5);
    ASSETS->getAnimationsMap()["DustCloudType_Kick_Up"] = new Animation(TEX_JON, 2048, 1648, 96, 32, 576, 32, TEXTURE_SIZE_4096, false, 0.06666666666667f, 6);
    ASSETS->getAnimationsMap()["JonShadowState_Grounded"] = new Animation(TEX_JON, 2048, 1684, 154, 18, 308, 18, TEXTURE_SIZE_4096, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["JonShadowState_Jumping"] = new Animation(TEX_JON, 2356, 1684, 154, 18, 616, 18, TEXTURE_SIZE_4096, false, 0.05f, 4);
    ASSETS->getAnimationsMap()["MidBossOwlState_Sleeping"] = new Animation(TEX_WORLD_1_MID_BOSS_3, 0, 0, 638, 572, 638, 2288, TEXTURE_SIZE_4096, true, 0.15f, 4);
    ASSETS->getAnimationsMap()["MidBossOwlState_Awakening"] = new Animation(TEX_WORLD_1_MID_BOSS_3, 0, 2288, 638, 572, 638, 1144, TEXTURE_SIZE_4096, false, 0.10f, 2);
    ASSETS->getAnimationsMap()["MidBossOwlState_Screeching"] = new Animation(TEX_WORLD_1_MID_BOSS_3, 0, 3432, 638, 572, 1276, 572, TEXTURE_SIZE_4096, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["MidBossOwlState_Pursuing_Damage_2"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 3072, 512, 512, 3072, 512, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["MidBossOwlState_Pursuing_Damage_1"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 1536, 512, 512, 3072, 512, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["MidBossOwlState_Pursuing_Damage_0"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 0, 512, 512, 3072, 512, TEXTURE_SIZE_4096, true, 0.10f, 6);
    ASSETS->getAnimationsMap()["MidBossOwlState_SwoopingDown_Damage_2"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 3072, 3072, 512, 512, 1024, 512, TEXTURE_SIZE_4096, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["MidBossOwlState_SwoopingDown_Damage_1"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 3072, 1536, 512, 512, 1024, 512, TEXTURE_SIZE_4096, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["MidBossOwlState_SwoopingDown_Damage_0"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 3072, 0, 512, 512, 1024, 512, TEXTURE_SIZE_4096, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_2"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 3584, 512, 512, 3584, 512, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    ASSETS->getAnimationsMap()["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_1"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 2048, 512, 512, 3584, 512, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    ASSETS->getAnimationsMap()["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_0"] = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 512, 512, 512, 3584, 512, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    {
        Animation* anim = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 2560, 512, 512, 4096, 1024, TEXTURE_SIZE_4096, false, 8);
        anim->setFrameTimes(8, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f);
        ASSETS->getAnimationsMap()["MidBossOwlState_SlammingIntoTree_Damage_2"] = anim;
    }
    {
        Animation* anim = new Animation(TEX_WORLD_1_MID_BOSS_1, 0, 1024, 512, 512, 4096, 1024, TEXTURE_SIZE_4096, false, 8);
        anim->setFrameTimes(8, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f);
        ASSETS->getAnimationsMap()["MidBossOwlState_SlammingIntoTree_Damage_1"] = anim;
    }
    {
        Animation* anim = new Animation(TEX_WORLD_1_MID_BOSS_2, 0, 0, 720, 800, 3600, 4000, TEXTURE_SIZE_4096, false, 22);
        anim->setFrameTimes(22, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
        ASSETS->getAnimationsMap()["MidBossOwlState_Dying_Dead"] = anim;
    }
    ASSETS->getAnimationsMap()["Bat"] = new Animation(TEX_TUTORIAL, 2048, 898, 164, 158, 1312, 316, TEXTURE_SIZE_4096, true, 0.10f, 15, 8);
    ASSETS->getAnimationsMap()["BatInstruction_Opening"] = new Animation(TEX_TUTORIAL, 0, 792, 498, 394, 996, 394, TEXTURE_SIZE_4096, false, 0.10f, 2);
    ASSETS->getAnimationsMap()["BatInstructionType_Tap"] = new Animation(TEX_TUTORIAL, 1498, 398, 498, 394, 3984, 394, TEXTURE_SIZE_4096, true, 0.10f, 5);
    
    ASSETS->getAnimationsMap()["BatInstructionType_TapHold"] = new Animation(TEX_TUTORIAL, 0, 0, 498, 394, 3984, 788, TEXTURE_SIZE_4096, true, 0.10f, 11, 9);
    
    ASSETS->getAnimationsMap()["BatInstructionType_SwipeDown"] = new Animation(TEX_TUTORIAL, 2048, 2048, 498, 394, 1992, 788, TEXTURE_SIZE_4096, true, 0.10f, 8);
    ASSETS->getAnimationsMap()["BatInstructionType_SwipeRight"] = new Animation(TEX_TUTORIAL, 0, 2048, 498, 394, 1992, 788, TEXTURE_SIZE_4096, true, 0.10f, 8);
    ASSETS->getAnimationsMap()["TitlePanel_Lightning"] = new Animation(TEX_TITLE, 1284, 0, 354, 356, 708, 1068, TEXTURE_SIZE_2048, false, 0.10f, 6);
    ASSETS->getAnimationsMap()["TitlePanel_Castle"] = new Animation(TEX_TITLE, 0, 724, 368, 374, 736, 374, TEXTURE_SIZE_2048, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["TitlePanel_Castle_Light_Effect"] = new Animation(TEX_TITLE, 0, 1098, 368, 374, 736, 374, TEXTURE_SIZE_2048, true, 0.10f, 2);
    ASSETS->getAnimationsMap()["TitlePanel_Logo_Light_Effect"] = new Animation(TEX_TITLE, 0, 1504, 874, 434, 1748, 434, TEXTURE_SIZE_2048, true, 0.10f, 2);
    
    ASSETS->getAnimationsMap()["FloatingPlatformIdlePoof"] = new Animation(TEX_WORLD_1_OBJECTS_1, 2864, 0, 56, 36, 168, 36, TEXTURE_SIZE_4096, true, 0.10f, 3);
    ASSETS->getAnimationsMap()["FloatingPlatformWeightedPoof"] = new Animation(TEX_WORLD_1_OBJECTS_1, 2816, 44, 160, 172, 640, 172, TEXTURE_SIZE_4096, true, 0.10f, 4);
    
    ASSETS->getAnimationsMap()["FinalScoreSparkle"] = new Animation(TEX_WORLD_1_OBJECTS_1, 1680, 2800, 194, 188, 970, 188, TEXTURE_SIZE_4096, false, 0.10f, 5);
    
    ASSETS->getAnimationsMap()["GameButtonContainer"] = new Animation(TEX_WORLD_MAP_1, 1104, 120, 104, 384, 520, 384, TEXTURE_SIZE_2048, false, 0.04f, 5);
}
