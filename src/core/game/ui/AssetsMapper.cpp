//
//  AssetsMapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 11/9/16.
//  Copyright © 2016 Noctis Games. All rights reserved.
//

#include "AssetsMapper.h"

void AssetsMapper::initializeAssetsMapper()
{
    /// Texture Regions
    m_textureRegions["CutsceneEffectType_Shadow_One"] = createTextureRegion("world_1_cutscene_2", 0, 0, 966, 504, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutsceneEffectType_Shadow_Two"] = createTextureRegion("world_1_cutscene_2", 0, 508, 1600, 760, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_One"] = createTextureRegion("world_1_cutscene_1", 0, 0, 1600, 1200, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Two"] = createTextureRegion("world_1_cutscene_1", 0, 1204, 1600, 900, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Three"] = createTextureRegion("world_1_cutscene_1", 0, 2108, 1600, 900, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Four"] = createTextureRegion("world_1_cutscene_1", 1604, 0, 1600, 900, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Five"] = createTextureRegion("world_1_cutscene_1", 0, 3012, 1600, 900, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Six"] = createTextureRegion("world_1_cutscene_1", 1604, 904, 1600, 1200, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CutscenePanelType_Opening_Seven"] = createTextureRegion("world_1_cutscene_1", 1604, 2108, 1600, 900, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["WorldMapPanel"] = createTextureRegion("world_map_screen_part_1", 0, 0, 1088, 612, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["AbilitySlot_Locked"] = createTextureRegion("world_map_screen_part_2", 0, 458, 118, 114, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BossLevelThumbnail_Cleared"] = createTextureRegion("world_map_screen_part_2", 0, 1832, 198, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BossLevelThumbnail_Unlocked"] = createTextureRegion("world_map_screen_part_2", 198, 1420, 198, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BossLevelThumbnail_Locked"] = createTextureRegion("world_map_screen_part_2", 990, 1008, 198, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["NormalLevelThumbnail_Cleared"] = createTextureRegion("world_map_screen_part_2", 0, 330, 124, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["NormalLevelThumbnail_Playable"] = createTextureRegion("world_map_screen_part_2", 124, 78, 124, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["NormalLevelThumbnail_Unplayable"] = createTextureRegion("world_map_screen_part_2", 0, 78, 124, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Upper"] = createTextureRegion("world_1_background_upper", 0, 0, PIXEL_WIDTH_FOR_GAME, 1536, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Mid_Hills"] = createTextureRegion("world_1_background_mid", 0, 0, PIXEL_WIDTH_FOR_GAME, 804, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Mid_Trees"] = createTextureRegion("world_1_background_mid", 0, 1312, PIXEL_WIDTH_FOR_GAME, 736, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Lower_Top"] = createTextureRegion("world_1_background_lower_part_1", 0, 96, PIXEL_WIDTH_FOR_GAME, 980, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Lower_Bottom"] = createTextureRegion("world_1_background_lower_part_1", 0, 1524, PIXEL_WIDTH_FOR_GAME, 524, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Lower_Inner"] = createTextureRegion("world_1_background_lower_part_2", 0, 160, PIXEL_WIDTH_FOR_GAME, 944, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_Lower_Innermost"] = createTextureRegion("world_1_background_lower_part_2", 0, 1104, PIXEL_WIDTH_FOR_GAME, 944, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_WaterBack"] = createTextureRegion("world_1_background_lower_part_2", 0, 18, PIXEL_WIDTH_FOR_GAME, 64, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["BackgroundType_WaterFront"] = createTextureRegion("world_1_background_lower_part_2", 0, 98, PIXEL_WIDTH_FOR_GAME, 48, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["MidgroundType_TreeOne"] = createTextureRegion("world_1_objects_part_2", 1664, 0, 992, 864, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_TreeTwo"] = createTextureRegion("world_1_objects_part_2", 2694, 0, 1120, 800, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_TreeThree"] = createTextureRegion("world_1_objects_part_2", 1404, 904, 288, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_DeepCaveColumnSmall"] = createTextureRegion("world_1_objects_part_2", 3136, 1824, 96, 288, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_DeepCaveColumnMedium"] = createTextureRegion("world_1_objects_part_2", 3968, 1280, 128, 832, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_DeepCaveColumnBig"] = createTextureRegion("world_1_objects_part_2", 3394, 1280, 256, 832, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Plant"] = createTextureRegion("world_1_objects_part_2", 1714, 914, 304, 320, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Metal_Tower_Section"] = createTextureRegion("world_1_objects_part_2", 0, 1108, 128, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Billboard_Count_Hiss"] = createTextureRegion("world_1_objects_part_2", 0, 0, 768, 448, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Billboard_Slag_Town"] = createTextureRegion("world_1_objects_part_2", 0, 448, 768, 448, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Billboard_Jon_Wanted"] = createTextureRegion("world_1_objects_part_2", 768, 448, 768, 448, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Hill"] = createTextureRegion("world_1_objects_part_2", 0, 928, 1376, 176, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Train_Car"] = createTextureRegion("world_1_objects_part_2", 528, 2798, 1568, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Short_Stump"] = createTextureRegion("world_1_objects_part_2", 604, 1128, 192, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Tall_Stump"] = createTextureRegion("world_1_objects_part_2", 604, 1278, 128, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Thin_Tall_Tree"] = createTextureRegion("world_1_objects_part_2", 604, 1488, 192, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Thin_Short_Tree"] = createTextureRegion("world_1_objects_part_2", 814, 1128, 256, 320, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Stone_Square"] = createTextureRegion("world_1_objects_part_2", 1294, 3688, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Stone_Diamond"] = createTextureRegion("world_1_objects_part_2", 1694, 3688, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Wall"] = createTextureRegion("world_1_objects_part_2", 1024, 3810, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["MidgroundType_Roof"] = createTextureRegion("world_1_objects_part_2", 1024, 3746, 256, 64, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveExtraDeepEndLeft"] = createTextureRegion("world_1_ground", 0, 1132, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveExtraDeepSmall"] = createTextureRegion("world_1_ground", 128, 1132, 512, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveExtraDeepMedium"] = createTextureRegion("world_1_ground", 640, 1132, 1024, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveExtraDeepLarge"] = createTextureRegion("world_1_ground", 1664, 1132, 2048, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveExtraDeepEndRight"] = createTextureRegion("world_1_ground", 3712, 1132, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveDeepEndLeft"] = createTextureRegion("world_1_ground", 0, 1264, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveDeepSmall"] = createTextureRegion("world_1_ground", 128, 1264, 512, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveDeepMedium"] = createTextureRegion("world_1_ground", 640, 1264, 1024, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveDeepLarge"] = createTextureRegion("world_1_ground", 1664, 1264, 2048, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveDeepEndRight"] = createTextureRegion("world_1_ground", 3712, 1264, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveEndLeft"] = createTextureRegion("world_1_ground", 0, 1912, 128, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveSmall"] = createTextureRegion("world_1_ground", 128, 1912, 512, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveMedium"] = createTextureRegion("world_1_ground", 640, 1912, 1024, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveLarge"] = createTextureRegion("world_1_ground", 1664, 1912, 2048, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveEndRight"] = createTextureRegion("world_1_ground", 3712, 1912, 128, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveRaisedEndLeft"] = createTextureRegion("world_1_ground", 0, 1396, 128, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveRaisedSmall"] = createTextureRegion("world_1_ground", 128, 1396, 512, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveRaisedMedium"] = createTextureRegion("world_1_ground", 640, 1396, 1024, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveRaisedLarge"] = createTextureRegion("world_1_ground", 1664, 1396, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_CaveRaisedEndRight"] = createTextureRegion("world_1_ground", 3712, 1396, 128, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithCaveEndLeft"] = createTextureRegion("world_1_ground", 0, 2300, 128, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithCaveSmall"] = createTextureRegion("world_1_ground", 128, 2300, 512, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithCaveMedium"] = createTextureRegion("world_1_ground", 640, 2300, 1024, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithCaveLarge"] = createTextureRegion("world_1_ground", 1664, 2300, 2048, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithCaveEndRight"] = createTextureRegion("world_1_ground", 3712, 2300, 128, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithoutCaveEndLeft"] = createTextureRegion("world_1_ground", 0, 2496, 128, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithoutCaveSmall"] = createTextureRegion("world_1_ground", 128, 2496, 512, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithoutCaveMedium"] = createTextureRegion("world_1_ground", 640, 2496, 1024, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithoutCaveLarge"] = createTextureRegion("world_1_ground", 1664, 2496, 2048, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassWithoutCaveEndRight"] = createTextureRegion("world_1_ground", 3712, 2496, 128, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassPitSmall"] = createTextureRegion("world_1_special", 2208, 880, 512, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassPitMedium"] = createTextureRegion("world_1_special", 2954, 880, 1024, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassPitLarge"] = createTextureRegion("world_1_special", 0, 880, 2048, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GroundType_GrassPitExtraLarge"] = createTextureRegion("world_1_special", 0, 2496, 4096, 1600, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ExitGroundType_GrassWithCaveSmallExitMid"] = createTextureRegion("world_1_ground", 0, 0, 512, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ExitGroundType_GrassWithCaveSmallExitEnd"] = createTextureRegion("world_1_ground", 3500, 228, 512, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ExitGroundType_CaveSmallExit"] = createTextureRegion("world_1_ground", 0, 228, 512, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["HoleType_GrassTileLeft"] = createTextureRegion("world_1_objects_part_1", 0, 1400, 256, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["HoleType_GrassTileCenter"] = createTextureRegion("world_1_objects_part_1", 0, 1772, 256, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["HoleType_GrassTileRight"] = createTextureRegion("world_1_objects_part_1", 0, 2144, 256, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["HoleType_Grass"] = createTextureRegion("world_1_objects_part_1", 0, 2528, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["HoleType_Cave"] = createTextureRegion("world_1_objects_part_1", 0, 2788, 272, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GrassPlatformLeft"] = createTextureRegion("world_1_objects_part_1", 2000, 600, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GrassPlatformCenter"] = createTextureRegion("world_1_objects_part_1", 2064, 600, 224, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GrassPlatformRight"] = createTextureRegion("world_1_objects_part_1", 2288, 600, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_CavePlatformLeft"] = createTextureRegion("world_1_objects_part_1", 2378, 600, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_CavePlatformCenter"] = createTextureRegion("world_1_objects_part_1", 2442, 600, 224, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_CavePlatformRight"] = createTextureRegion("world_1_objects_part_1", 2666, 600, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_RockLarge"] = createTextureRegion("world_1_objects_part_1", 0, 28, 704, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_RockMedium"] = createTextureRegion("world_1_objects_part_1", 0, 684, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_RockSmall"] = createTextureRegion("world_1_objects_part_1", 3624, 2158, 384, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_StumpBig"] = createTextureRegion("world_1_objects_part_1", 388, 696, 256, 288, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_StumpSmall"] = createTextureRegion("world_1_objects_part_1", 0, 1080, 320, 272, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_EndSign"] = createTextureRegion("world_1_objects_part_1", 704, 688, 112, 160, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_ThornsLeft"] = createTextureRegion("world_1_objects_part_1", 1156, 1196, 80, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_ThornsCenterSmall"] = createTextureRegion("world_1_objects_part_1", 1588, 1196, 176, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_ThornsCenterBig"] = createTextureRegion("world_1_objects_part_1", 1236, 1196, 352, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_ThornsRight"] = createTextureRegion("world_1_objects_part_1", 1764, 1196, 80, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_LogVerticalTall"] = createTextureRegion("world_1_objects_part_1", 452, 1004, 128, 176, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_LogVerticalShort"] = createTextureRegion("world_1_objects_part_1", 452, 1190, 128, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeGrassSingle"] = createTextureRegion("world_1_objects_part_1", 1904, 900, 96, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeGrassFour"] = createTextureRegion("world_1_objects_part_1", 2000, 900, 288, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeGrassEight"] = createTextureRegion("world_1_objects_part_1", 2288, 900, 544, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveSingle"] = createTextureRegion("world_1_objects_part_1", 1904, 1108, 96, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveFour"] = createTextureRegion("world_1_objects_part_1", 2000, 1108, 288, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveEight"] = createTextureRegion("world_1_objects_part_1", 2288, 1108, 544, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveCeilingSingle"] = createTextureRegion("world_1_objects_part_1", 1904, 1004, 96, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveCeilingFour"] = createTextureRegion("world_1_objects_part_1", 2000, 1004, 288, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeCaveCeilingEight"] = createTextureRegion("world_1_objects_part_1", 2288, 1004, 544, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeWallSingle"] = createTextureRegion("world_1_objects_part_1", 4000, 3140, 96, 64, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeWallFour"] = createTextureRegion("world_1_objects_part_1", 4000, 3824, 96, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeWallEight"] = createTextureRegion("world_1_objects_part_1", 4000, 3248, 96, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeStar"] = createTextureRegion("world_1_objects_part_1", 890, 1162, 224, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GiantTree"] = createTextureRegion("world_1_objects_part_1", 832, 0, 1088, 1040, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GiantPerchTree"] = createTextureRegion("world_1_mid_boss_part_3", 3008, 2080, 1088, 1040, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeTower"] = createTextureRegion("world_1_objects_part_2", 2892, 3200, 512, 896, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikeTowerBg"] = createTextureRegion("world_1_objects_part_2", 3408, 3200, 512, 896, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikedBallRolling"] = createTextureRegion("world_1_end_boss_part_1", 3440, 2104, 512, 480, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_SpikedBall"] = createTextureRegion("world_1_end_boss_part_1", 3440, 2588, 512, 480, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["SnakeBody_Left"] = createTextureRegion("world_1_end_boss_part_1", 0, 548, 3488, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["SnakeBody_Right"] = createTextureRegion("world_1_end_boss_part_2", 0, 1640, 3488, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EndBossSnakeState_Sleeping_Awakening"] = createTextureRegion("world_1_end_boss_part_1", 0, 0, 864, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EndBossSnakeState_OpenMouthLeft_ChargingLeft"] = createTextureRegion("world_1_end_boss_part_1", 1728, 0, 864, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EndBossSnakeState_Pursuing_Waiting_Damaged"] = createTextureRegion("world_1_end_boss_part_2", 0, 0, 864, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EndBossSnakeState_OpenMouthRight_ChargingRight"] = createTextureRegion("world_1_end_boss_part_2", 1728, 0, 864, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EndBossSnakeState_DeadSpiritReleasing_Dead"] = createTextureRegion("world_1_end_boss_part_3", 2592, 2720, 864, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CollectibleItemType_Carrot_Not_Collected"] = createTextureRegion("world_1_objects_part_1", 0, 3204, 218, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CollectibleItemType_GoldenCarrot_Previously_Collected"] = createTextureRegion("world_1_objects_part_1", 2286, 3204, 254, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["CollectibleItemType_GoldenCarrot_Not_Collected"] = createTextureRegion("world_1_objects_part_1", 2032, 3204, 254, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GameButtonType_ToggleMusic"] = createTextureRegion("world_map_screen_part_1", 1244, 72, 128, 128, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_ToggleSound"] = createTextureRegion("world_map_screen_part_1", 1244, 204, 128, 128, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_BackToTitle"] = createTextureRegion("world_map_screen_part_1", 1800, 0, 104, 104, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_Leaderboards"] = createTextureRegion("world_map_screen_part_1", 1904, 0, 104, 104, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_ViewOpeningCutscene"] = createTextureRegion("world_map_screen_part_1", 1152, 0, 96, 64, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_BackToLevelSelect"] = createTextureRegion("misc", 0, 0, 104, 104, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["GameButtonType_ContinueToLevelSelect"] = createTextureRegion("misc", 804, 0, 104, 104, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["GameButtonType_LevelEditor"] = createTextureRegion("title_screen", 800, 780, 190, 62, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameButtonType_SpriteTester"] = createTextureRegion("title_screen", 1000, 780, 190, 62, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["GameHudCarrot_Golden"] = createTextureRegion("world_1_objects_part_1", 1904, 1254, 96, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["GameHudCarrot_Normal"] = createTextureRegion("world_1_objects_part_1", 884, 1054, 96, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["EditorEntitiesPanel"] = createTextureRegion("sprite_tester", 0, 46, 592, 1338, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["EditorActionsPanel"] = createTextureRegion("sprite_tester", 840, 46, 592, 1338, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["TrashCan_Highlighted"] = createTextureRegion("sprite_tester", 128, 1454, 128, 128, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["TrashCan_Normal"] = createTextureRegion("sprite_tester", 0, 1454, 128, 128, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["SelectorPanel"] = createTextureRegion("sprite_tester", 1538, 12, 510, 510, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["OffsetPanel"] = createTextureRegion("level_editor", 1538, 542, 510, 510, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["ConfirmResetPanel"] = createTextureRegion("sprite_tester", 938, 1484, 510, 510, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["ConfirmExitPanel"] = createTextureRegion("sprite_tester", 1538, 1072, 510, 510, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["CarrotCountMarker"] = createTextureRegion("misc", 256, 0, 32, 32, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["ClockIcon"] = createTextureRegion("misc", 512, 0, 72, 72, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["ResumeButton"] = createTextureRegion("vampire", 2048, 1792, 192, 192, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ComingSoonScreen"] = createTextureRegion("world_1_special", 0, 0, 1280, 720, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["SpeedBarFrame"] = createTextureRegion("misc", 8, 654, 516, 20, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["SpeedBar"] = createTextureRegion("misc", 8, 678, 516, 20, TEXTURE_SIZE_1024, TEXTURE_SIZE_1024);
    m_textureRegions["TitlePanel_Background"] = createTextureRegion("title_screen", 0, 0, 1280, 720, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["TitlePanel_Logo"] = createTextureRegion("title_screen", 1024, 1070, 874, 434, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["TitlePanel_Small_Cloud"] = createTextureRegion("title_screen", 0, 1940, 634, 94, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["TitlePanel_Big_Cloud"] = createTextureRegion("title_screen", 964, 1940, 1084, 108, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048);
    m_textureRegions["ForegroundCoverObjectType_Tree"] = createTextureRegion("world_1_objects_part_2", 0, 2774, 448, 816, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Plant"] = createTextureRegion("world_1_objects_part_2", 0, 3608, 336, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Bush"] = createTextureRegion("world_1_objects_part_2", 0, 1484, 400, 240, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Ferns"] = createTextureRegion("world_1_objects_part_2", 0, 1308, 528, 176, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Wall"] = createTextureRegion("world_1_objects_part_2", 764, 3554, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Wall_Bottom"] = createTextureRegion("world_1_objects_part_2", 508, 3810, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Wall_Window"] = createTextureRegion("world_1_objects_part_2", 508, 3554, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Wall_Window_Bottom"] = createTextureRegion("world_1_objects_part_2", 764, 3810, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Roof_Side_Left"] = createTextureRegion("world_1_objects_part_2", 2138, 3914, 256, 64, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Roof_Side_Right"] = createTextureRegion("world_1_objects_part_2", 2394, 3914, 256, 64, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Roof_Plain"] = createTextureRegion("world_1_objects_part_2", 2138, 3986, 256, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundCoverObjectType_Roof_Chimney"] = createTextureRegion("world_1_objects_part_2", 2394, 3986, 256, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_MetalGrassPlatform"] = createTextureRegion("world_1_objects_part_1", 2048, 474, 256, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_MetalGrassPlatformLeft"] = createTextureRegion("world_1_objects_part_1", 1984, 368, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_MetalGrassPlatformCenter"] = createTextureRegion("world_1_objects_part_1", 2048, 368, 256, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_MetalGrassPlatformRight"] = createTextureRegion("world_1_objects_part_1", 2304, 368, 64, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_WoodPlatform"] = createTextureRegion("world_1_objects_part_1", 2384, 498, 256, 64, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_WoodBoxTop"] = createTextureRegion("world_1_objects_part_1", 2758, 344, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_WoodBox"] = createTextureRegion("world_1_objects_part_1", 2758, 604, 256, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GreenThornsLeft"] = createTextureRegion("world_1_objects_part_1", 1948, 0, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GreenThornsCenterSmall"] = createTextureRegion("world_1_objects_part_1", 2460, 0, 192, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GreenThornsCenterBig"] = createTextureRegion("world_1_objects_part_1", 2076, 0, 384, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_GreenThornsRight"] = createTextureRegion("world_1_objects_part_1", 2652, 0, 128, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Logs"] = createTextureRegion("world_1_objects_part_1", 2464, 3744, 592, 160, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Stone_Bottom"] = createTextureRegion("world_1_objects_part_1", 3078, 3698, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Stone_Middle"] = createTextureRegion("world_1_objects_part_1", 3484, 3298, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Stone_Top"] = createTextureRegion("world_1_objects_part_1", 3484, 3698, 448, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Stone_Platform"] = createTextureRegion("world_1_objects_part_1", 3484, 3128, 448, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Stone_Square"] = createTextureRegion("world_1_objects_part_1", 3084, 3284, 384, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    m_textureRegions["ForegroundObjectType_Floating_Platform"] = createTextureRegion("world_1_objects_part_1", 2384, 284, 320, 176, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096);
    
    /// Animations
    m_animations["CutsceneEffectType_POW"] = createAnimation("world_1_cutscene_2", 0, 1270, 1952, 1412, 3904, 2824, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.20f, 3);
    m_animations["AbilitySlot_Unlocking"] = createAnimation("world_map_screen_part_2", 0, 458, 118, 114, 1180, 114, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 10);
    m_animations["AbilitySlotType_Drill"] = createAnimation("world_map_screen_part_2", 0, 572, 118, 114, 1298, 114, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 11);
    m_animations["AbilitySlotType_Dash"] = createAnimation("world_map_screen_part_2", 0, 686, 118, 114, 1298, 114, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 11);
    m_animations["BossLevelThumbnail_Unlocking"] = createAnimation("world_map_screen_part_2", 0, 804, 198, 204, 1980, 408, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 13);
    m_animations["BossLevelThumbnail_Selected_Cleared"] = createAnimation("world_map_screen_part_2", 198, 1832, 198, 204, 1782, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 9);
    m_animations["BossLevelThumbnail_Selected"] = createAnimation("world_map_screen_part_2", 0, 1216, 198, 204, 1782, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 9);
    m_animations["BossLevelThumbnail_Selecting_Cleared"] = createAnimation("world_map_screen_part_2", 1386, 1628, 198, 204, 792, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 4);
    m_animations["BossLevelThumbnail_Selecting"] = createAnimation("world_map_screen_part_2", 198, 1420, 198, 204, 594, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 3);
    m_animations["BossLevelThumbnail_Clearing"] = createAnimation("world_map_screen_part_2", 0, 1628, 198, 204, 1386, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 7);
    m_animations["BossLevelThumbnail_Locked_Jaw_Moving"] = createAnimation("world_map_screen_part_2", 990, 1008, 198, 204, 990, 204, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 5, 3);
    m_animations["NormalLevelThumbnail_Selected_Cleared"] = createAnimation("world_map_screen_part_2", 744, 330, 124, 124, 1240, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 10);
    m_animations["NormalLevelThumbnail_Selected"] = createAnimation("world_map_screen_part_2", 868, 78, 124, 124, 1116, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 9);
    m_animations["NormalLevelThumbnail_Selecting_Cleared"] = createAnimation("world_map_screen_part_2", 0, 330, 124, 124, 744, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 6);
    m_animations["NormalLevelThumbnail_Selecting"] = createAnimation("world_map_screen_part_2", 124, 78, 124, 124, 744, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 6);
    m_animations["NormalLevelThumbnail_Clearing"] = createAnimation("world_map_screen_part_2", 0, 206, 124, 124, 1364, 124, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 11);
    m_animations["GoldenCarrotsMarker_0"] = createAnimation("world_map_screen_part_2", 0, 0, 118, 74, 944, 74, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 8);
    m_animations["GoldenCarrotsMarker_1"] = createAnimation("world_map_screen_part_2", 0, 0, 118, 74, 1062, 74, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 9);
    m_animations["GoldenCarrotsMarker_2"] = createAnimation("world_map_screen_part_2", 0, 0, 118, 74, 1180, 74, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 10);
    m_animations["GoldenCarrotsMarker_3"] = createAnimation("world_map_screen_part_2", 0, 0, 118, 74, 1298, 74, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 11);
    m_animations["GoldenCarrotsMarker_4"] = createAnimation("world_map_screen_part_2", 0, 0, 118, 74, 1416, 74, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 12);
    m_animations["SpendGoldenCarrotsBubble_Has_Enough"] = createAnimation("world_map_screen_part_1", 0, 748, 234, 184, 1872, 552, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 21, 3);
    m_animations["SpendGoldenCarrotsBubble_Not_Enough"] = createAnimation("world_map_screen_part_1", 0, 1304, 234, 184, 1872, 552, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 21, 3);
    m_animations["ExitGroundType_CaveDeepSmallWaterfall"] = createAnimation("world_1_ground", 0, 616, 512, 448, 1536, 448, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 3);
    m_animations["ExitGroundCoverType_Grass"] = createAnimation("world_1_ground", 1024, 0, 512, 224, 3072, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.08333333333333f, 6);
    m_animations["ExitGroundCoverType_Cave"] = createAnimation("world_1_ground", 514, 228, 512, 384, 2560, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 5);
    m_animations["HoleCoverType_GrassTileLeft"] = createAnimation("world_1_objects_part_1", 256, 1400, 256, 368, 2560, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["HoleCoverType_GrassTileCenter"] = createAnimation("world_1_objects_part_1", 256, 1772, 256, 368, 2560, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["HoleCoverType_GrassTileRight"] = createAnimation("world_1_objects_part_1", 256, 2144, 256, 368, 2560, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["HoleCoverType_Grass"] = createAnimation("world_1_objects_part_1", 256, 2528, 256, 256, 3072, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.04166666666667f, 12);
    m_animations["HoleCoverType_Cave"] = createAnimation("world_1_objects_part_1", 272, 2788, 272, 384, 2720, 384, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["ForegroundObjectType_RockSmallCracked"] = createAnimation("world_1_objects_part_1", 384, 3236, 384, 368, 2304, 368, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 6);
    m_animations["ForegroundObjectType_JumpSpringLightFlush"] = createAnimation("world_1_objects_part_1", 2904, 1804, 160, 112, 1120, 112, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05142857142857f, 7);
    m_animations["ForegroundObjectType_JumpSpringLight"] = createAnimation("world_1_objects_part_1", 2126, 3960, 96, 80, 480, 80, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.09f, 4);
    m_animations["ForegroundObjectType_JumpSpringMedium"] = createAnimation("world_1_objects_part_1", 0, 3668, 272, 144, 1904, 144, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05142857142857, 7);
    m_animations["ForegroundObjectType_JumpSpringHeavy"] = createAnimation("world_1_objects_part_1", 272, 3816, 272, 224, 1904, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06f, 6);
    m_animations["ForegroundObjectType_VerticalSaw"] = createAnimation("world_1_objects_part_1", 3590, 2556, 240, 528, 480, 528, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.05f, 2);
    m_animations["ForegroundObjectType_GiantShakingTree"] = createAnimation("world_1_objects_part_1", 832, 0, 1088, 1040, 3264, 3120, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.025f, 7);
    m_animations["ForegroundObjectType_SpikedBallChain"] = createAnimation("world_1_end_boss_part_1", 0, 1472, 1616, 1312, 3232, 2624, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    m_animations["CountHissWithMina_Left"] = createAnimation("world_1_end_boss_part_1", 2048, 3072, 512, 512, 2048, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.08f, 6);
    m_animations["CountHissWithMina_Right"] = createAnimation("jon", 2048, 3072, 512, 512, 2048, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.08f, 7);
    m_animations["SnakeSpirit"] = createAnimation("world_1_end_boss_part_2", 0, 2188, 820, 360, 3280, 1080, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 12);
    m_animations["SnakeHeadImpact"] = createAnimation("world_1_end_boss_part_2", 0, 3584, 512, 512, 4096, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 8);
    m_animations["SnakeSkin"] = createAnimation("world_1_end_boss_part_2", 0, 548, 864, 544, 3456, 1088, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 7);
    m_animations["SnakeEye"] = createAnimation("world_1_end_boss_part_1", 2756, 304, 118, 118, 354, 118, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    m_animations["SnakeTonque_Left"] = createAnimation("world_1_end_boss_part_1", 2596, 0, 554, 78, 1108, 234, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 5, 3);
    m_animations["SnakeTonque_Right"] = createAnimation("world_1_end_boss_part_2", 2792, 0, 554, 78, 1108, 234, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 5, 3);
    m_animations["EndBossSnakeState_OpeningMouthLeft"] = createAnimation("world_1_end_boss_part_1", 0, 0, 864, 544, 2592, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    m_animations["EndBossSnakeState_OpeningMouthRight"] = createAnimation("world_1_end_boss_part_2", 0, 0, 864, 544, 2592, 544, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    {
        Animation* anim = createAnimation("world_1_end_boss_part_3", 0, 0, 864, 544, 3456, 3264, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 24);
        anim->setFrameTimes(24, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
        m_animations["EndBossSnakeState_Dying"] = anim;
    }
    m_animations["EnemyType_MushroomGround"] = createAnimation("world_1_enemies", 0, 0, 112, 128, 448, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.12f, 4);
    m_animations["EnemyType_MushroomCeiling"] = createAnimation("world_1_enemies", 0, 132, 112, 128, 448, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.12f, 4);
    m_animations["EnemyType_SnakeGrunt"] = createAnimation("world_1_enemies", 0, 332, 128, 96, 512, 96, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.08f, 4);
    m_animations["EnemyType_Sparrow"] = createAnimation("world_1_enemies", 0, 692, 160, 160, 1120, 160, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.08f, 7);
    m_animations["EnemyType_Toad_Dead_Part_1_Jon_Is_Vampire"] = createAnimation("world_1_enemies", 1024, 2144, 512, 256, 1024, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 2);
    m_animations["EnemyType_Toad_Dead_Part_1_Jon_Is_Rabbit"] = createAnimation("world_1_enemies", 0, 1888, 512, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 5);
    m_animations["EnemyType_Toad_Dead_Part_2"] = createAnimation("world_1_enemies", 2048, 1888, 512, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 7);
    m_animations["EnemyType_Toad_Eating_Jon_Is_Vampire"] = createAnimation("world_1_enemies", 2048, 1372, 512, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 8);
    m_animations["EnemyType_Toad_Eating_Jon_Is_Rabbit"] = createAnimation("world_1_enemies", 0, 1372, 512, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 8);
    m_animations["EnemyType_Toad"] = createAnimation("world_1_enemies", 492, 0, 512, 256, 3584, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.15f, 7);
    m_animations["EnemyType_Fox_Is_Dead"] = createAnimation("world_1_enemies", 0, 2664, 256, 512, 2560, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["EnemyType_Fox_Is_Hitting_Left"] = createAnimation("world_1_enemies", 2080, 260, 256, 256, 1792, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 11);
    m_animations["EnemyType_Fox_Is_Hitting_Right"] = createAnimation("world_1_enemies", 0, 2404, 256, 256, 2816, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 11);
    m_animations["EnemyType_Fox_Is_Being_Hit"] = createAnimation("world_1_enemies", 3072, 2404, 256, 256, 768, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 6);
    m_animations["EnemyType_Fox_Left"] = createAnimation("world_1_enemies", 3104, 516, 256, 256, 768, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.15f, 3);
    m_animations["EnemyType_Fox_Right"] = createAnimation("world_1_enemies", 3104, 772, 256, 256, 768, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.15f, 3);
    m_animations["EnemyType_BigMushroomGround_Bouncing_Back"] = createAnimation("world_1_enemies", 2560, 3298, 256, 208, 1024, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["EnemyType_BigMushroomGround_Bouncing_On"] = createAnimation("world_1_enemies", 1536, 3298, 256, 208, 1024, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["EnemyType_BigMushroomGround"] = createAnimation("world_1_enemies", 0, 3298, 256, 208, 1536, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["EnemyType_BigMushroomCeiling_Bouncing_Back"] = createAnimation("world_1_enemies", 2560, 3510, 256, 208, 1024, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["EnemyType_BigMushroomCeiling_Bouncing_On"] = createAnimation("world_1_enemies", 1536, 3510, 256, 208, 1024, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["EnemyType_BigMushroomCeiling"] = createAnimation("world_1_enemies", 0, 3510, 256, 208, 1536, 208, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["MovingSnakeGrunt_Jumping"] = createAnimation("world_1_enemies", 768, 3850, 256, 128, 1024, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["MovingSnakeGrunt_Falling"] = createAnimation("world_1_enemies", 1792, 3850, 256, 128, 512, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 2);
    m_animations["MovingSnakeGrunt_About_To_Jump"] = createAnimation("world_1_enemies", 0, 3850, 256, 128, 768, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    m_animations["MovingSnakeGrunt_Landing"] = createAnimation("world_1_enemies", 2304, 3850, 256, 128, 1024, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 4);
    m_animations["MovingSnakeGrunt_Pausing"] = createAnimation("world_1_enemies", 1536, 3722, 256, 128, 1280, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 5);
    m_animations["MovingSnakeGrunt"] = createAnimation("world_1_enemies", 0, 3722, 256, 128, 1536, 128, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["EnemySpiritType_Snake"] = createAnimation("world_1_enemies", 0, 432, 208, 256, 2080, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 10);
    m_animations["EnemySpiritType_Sparrow"] = createAnimation("world_1_enemies", 0, 856, 256, 512, 3072, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.04166666666667f, 12);
    m_animations["CollectibleItemType_Carrot_Collected"] = createAnimation("world_1_objects_part_1", 0, 3204, 218, 224, 1744, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 8);
    m_animations["CollectibleItemType_GoldenCarrot_Collected"] = createAnimation("world_1_objects_part_1", 0, 3432, 254, 224, 2794, 224, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 11);
    m_animations["GoldenCarrotTwinkle"] = createAnimation("world_1_objects_part_1", 3004, 2004, 74, 78, 518, 78, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 7);
    {
        Animation* anim = createAnimation("vampire", 2048, 2048, 256, 256, 2048, 768, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 19);
        anim->setFrameTimes(19, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
        m_animations["Jon_isTransformingIntoVampire"] = anim;
    }
    {
        Animation* anim = createAnimation("vampire", 2048, 2816, 256, 256, 2048, 768, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 19);
        anim->setFrameTimes(19, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.0078125f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
        m_animations["Jon_isRevertingToRabbit"] = anim;
    }
    m_animations["Jon_Vampire_Death"] = createAnimation("vampire", 2048, 3584, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06666666666667f, 15);
    m_animations["Jon_Vampire_PushedBack"] = createAnimation("vampire", 512, 256, 256, 256, 1536, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06f, 6);
    m_animations["Jon_Vampire_Idle"] = createAnimation("vampire", 0, 1792, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.125f, 8);
    m_animations["Jon_Vampire_Running"] = createAnimation("vampire", 0, 0, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.05f, 10);
    m_animations["Jon_Vampire_UpwardThrust"] = createAnimation("vampire", 0, 3072, 256, 512, 1536, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.04545454545455f, 11);
    {
        Animation* anim = createAnimation("vampire", 768, 512, 768, 256, 3072, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 14);
        anim->setFrameTimes(14, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.40f, 0.1f);
        m_animations["Jon_Vampire_Dash"] = anim;
    }
    m_animations["Jon_Vampire_DoubleJumping"] = createAnimation("vampire", 0, 512, 256, 256, 768, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.09f, 6);
    m_animations["Jon_Vampire_Gliding"] = createAnimation("vampire", 0, 1024, 256, 256, 512, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.06f, 2);
    m_animations["Jon_Vampire_Falling"] = createAnimation("vampire", 0, 1280, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.06f, 3);
    m_animations["Jon_Vampire_Landing"] = createAnimation("vampire", 0, 1536, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.066f, 3);
    m_animations["Jon_Rabbit_Death"] = createAnimation("jon", 0, 3072, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 10);
    m_animations["Jon_Rabbit_WarmUp"] = createAnimation("jon", 0, 2048, 256, 256, 2048, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 28);
    m_animations["Jon_Rabbit_PushedBack"] = createAnimation("jon", 512, 1024, 256, 256, 1536, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.07f, 6);
    m_animations["Jon_Rabbit_Idle"] = createAnimation("jon", 0, 1792, 256, 256, 1536, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6, 2);
    m_animations["Jon_Rabbit_Running"] = createAnimation("jon", 0, 0, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.05f, 12);
    m_animations["Jon_Rabbit_Jumping"] = createAnimation("jon", 0, 512, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.09f, 7);
    m_animations["Jon_Rabbit_DoubleJumping"] = createAnimation("jon", 0, 768, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.07f, 9);
    m_animations["Jon_Rabbit_Falling"] = createAnimation("jon", 0, 1280, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.06f, 3);
    m_animations["Jon_Rabbit_Landing"] = createAnimation("jon", 0, 1536, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 4);
    m_animations["Jon_Rabbit_SpinningBackFist"] = createAnimation("jon", 2048, 0, 256, 256, 2048, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06f, 7);
    m_animations["Jon_Rabbit_Burrow"] = createAnimation("jon", 1792, 256, 256, 256, 2304, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06f, 9);
    m_animations["Jon_Rabbit_Stomp"] = createAnimation("jon", 2048, 1024, 256, 256, 2048, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.05f, 11, 9);
    m_animations["Jon_Rabbit_LandingRoll"] = createAnimation("jon", 2816, 1280, 256, 256, 1280, 256, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 5);
    m_animations["DustCloudType_Landing"] = createAnimation("jon", 1100, 1644, 116, 60, 580, 60, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.08f, 5);
    m_animations["DustCloudType_Kick_Up"] = createAnimation("jon", 2048, 1648, 96, 32, 576, 32, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.06666666666667f, 6);
    m_animations["JonShadowState_Grounded"] = createAnimation("jon", 2048, 1684, 154, 18, 308, 18, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 2);
    m_animations["JonShadowState_Jumping"] = createAnimation("jon", 2356, 1684, 154, 18, 616, 18, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.05f, 4);
    m_animations["MidBossOwlState_Sleeping"] = createAnimation("world_1_mid_boss_part_3", 0, 0, 638, 572, 638, 2288, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.15f, 4);
    m_animations["MidBossOwlState_Awakening"] = createAnimation("world_1_mid_boss_part_3", 0, 2288, 638, 572, 638, 1144, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 2);
    m_animations["MidBossOwlState_Screeching"] = createAnimation("world_1_mid_boss_part_3", 0, 3432, 638, 572, 1276, 572, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 2);
    m_animations["MidBossOwlState_Pursuing_Damage_2"] = createAnimation("world_1_mid_boss_part_1", 0, 3072, 512, 512, 3072, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["MidBossOwlState_Pursuing_Damage_1"] = createAnimation("world_1_mid_boss_part_1", 0, 1536, 512, 512, 3072, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["MidBossOwlState_Pursuing_Damage_0"] = createAnimation("world_1_mid_boss_part_1", 0, 0, 512, 512, 3072, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 6);
    m_animations["MidBossOwlState_SwoopingDown_Damage_2"] = createAnimation("world_1_mid_boss_part_1", 3072, 3072, 512, 512, 1024, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 2);
    m_animations["MidBossOwlState_SwoopingDown_Damage_1"] = createAnimation("world_1_mid_boss_part_1", 3072, 1536, 512, 512, 1024, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 2);
    m_animations["MidBossOwlState_SwoopingDown_Damage_0"] = createAnimation("world_1_mid_boss_part_1", 3072, 0, 512, 512, 1024, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 2);
    m_animations["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_2"] = createAnimation("world_1_mid_boss_part_1", 0, 3584, 512, 512, 3584, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    m_animations["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_1"] = createAnimation("world_1_mid_boss_part_1", 0, 2048, 512, 512, 3584, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    m_animations["MidBossOwlState_FlyingAwayAfterCatchingJon_Damage_0"] = createAnimation("world_1_mid_boss_part_1", 0, 512, 512, 512, 3584, 512, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 7, 1);
    {
        Animation* anim = createAnimation("world_1_mid_boss_part_1", 0, 2560, 512, 512, 4096, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 8);
        anim->setFrameTimes(8, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f);
        m_animations["MidBossOwlState_SlammingIntoTree_Damage_2"] = anim;
    }
    {
        Animation* anim = createAnimation("world_1_mid_boss_part_1", 0, 1024, 512, 512, 4096, 1024, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 8);
        anim->setFrameTimes(8, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f);
        m_animations["MidBossOwlState_SlammingIntoTree_Damage_1"] = anim;
    }
    {
        Animation* anim = createAnimation("world_1_mid_boss_part_2", 0, 0, 720, 800, 3600, 4000, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 22);
        anim->setFrameTimes(22, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
        m_animations["MidBossOwlState_Dying_Dead"] = anim;
    }
    m_animations["Bat"] = createAnimation("tutorial", 2048, 898, 164, 158, 1312, 316, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 15, 8);
    m_animations["BatInstruction_Opening"] = createAnimation("tutorial", 0, 3588, 498, 394, 1494, 394, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, false, 0.10f, 3);
    m_animations["BatInstructionType_Tap"] = createAnimation("tutorial", 1498, 398, 498, 394, 3984, 394, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 5);
    
    if (ASSETS->isUsingDesktopTextureSet())
    {
        m_animations["BatInstructionType_TapHold"] = createAnimation("tutorial", 0, 0, 498, 394, 3984, 788, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 11);
    }
    else
    {
        m_animations["BatInstructionType_TapHold"] = createAnimation("tutorial", 0, 0, 498, 394, 3984, 788, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 11, 9);
    }
    
    m_animations["BatInstructionType_SwipeDown"] = createAnimation("tutorial", 2048, 2048, 498, 394, 1992, 788, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 8);
    m_animations["BatInstructionType_SwipeRight"] = createAnimation("tutorial", 0, 2048, 498, 394, 1992, 788, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 8);
    m_animations["TitlePanel_Lightning"] = createAnimation("title_screen", 1284, 0, 354, 356, 708, 1068, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, false, 0.10f, 6);
    m_animations["TitlePanel_Castle"] = createAnimation("title_screen", 0, 724, 368, 374, 736, 374, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 2);
    m_animations["TitlePanel_Castle_Light_Effect"] = createAnimation("title_screen", 0, 1098, 368, 374, 736, 374, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 2);
    m_animations["TitlePanel_Logo_Light_Effect"] = createAnimation("title_screen", 0, 1504, 874, 434, 1748, 434, TEXTURE_SIZE_2048, TEXTURE_SIZE_2048, true, 0.10f, 2);
    
    m_animations["FloatingPlatformIdlePoof"] = createAnimation("world_1_objects_part_1", 2864, 0, 56, 36, 168, 36, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 3);
    m_animations["FloatingPlatformWeightedPoof"] = createAnimation("world_1_objects_part_1", 2816, 44, 160, 172, 640, 172, TEXTURE_SIZE_4096, TEXTURE_SIZE_4096, true, 0.10f, 4);
}