#ifndef INC_1OOM_GAME_DESIGN_H
#define INC_1OOM_GAME_DESIGN_H

#include "game_shipdesign.h"
#include "game_shiptech.h"
#include "game_types.h"
#include "types.h"

struct game_design_s {
    shipdesign_t sd;
    char names[SHIP_HULL_NUM][SHIP_NAME_LEN + 1];
    uint8_t percent[TECH_FIELD_NUM];
    player_id_t player_i;
    int lookbase;
    int sd_num;
    uint8_t tbl_shiplook[NUM_SHIPDESIGNS];
    uint8_t tbl_shiplook_hull[SHIP_HULL_NUM];
};

typedef enum {
    DESIGN_SLOT_COMP, /*1*/
    DESIGN_SLOT_SHIELD, /*2*/
    DESIGN_SLOT_JAMMER, /*3*/
    DESIGN_SLOT_ARMOR, /*4*/
    DESIGN_SLOT_ENGINE, /*5*/
    DESIGN_SLOT_MAN, /*6*/
    DESIGN_SLOT_SPECIAL1, /*7*/
    DESIGN_SLOT_SPECIAL2, /*8*/
    DESIGN_SLOT_SPECIAL3, /*14*/
    DESIGN_SLOT_WEAPON1, /*9*/
    DESIGN_SLOT_WEAPON2, /*10*/
    DESIGN_SLOT_WEAPON3, /*11*/
    DESIGN_SLOT_WEAPON4 /*15*/
} design_slot_t;

struct game_s;
struct game_aux_s;

extern void game_design_prepare(struct game_s *g, struct game_design_s *gd, player_id_t player, shipdesign_t *sd);
extern void game_design_prepare_ai(struct game_s *g, struct game_design_s *gd, player_id_t player, ship_hull_t hull, uint8_t look);
extern void game_design_update_engines(shipdesign_t *sd);
extern int game_design_get_hull_space(struct game_design_s *gd);
extern int game_design_calc_space(struct game_design_s *gd);
extern int game_design_calc_space_item(struct game_design_s *gd, design_slot_t slot, int itemi);
extern int game_design_calc_cost(struct game_design_s *gd);
extern int game_design_calc_cost_item(struct game_design_s *gd, design_slot_t slot, int itemi);
extern void game_design_clear(struct game_design_s *gd);
extern void game_design_look_next(struct game_design_s *gd);
extern void game_design_look_prev(struct game_design_s *gd);
extern int game_design_build_tbl_fit_comp(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_shield(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_jammer(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_armor(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_engine(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_man(struct game_s *g, struct game_design_s *gd, int8_t *buf);
extern int game_design_build_tbl_fit_weapon(struct game_s *g, struct game_design_s *gd, int8_t *buf, int wslot);
extern int game_design_build_tbl_fit_special(struct game_s *g, struct game_design_s *gd, int8_t *buf, int sslot);
extern void game_design_compact_slots(shipdesign_t *sd);
extern void game_design_scrap(struct game_s *g, player_id_t player, int shipi, bool flag_hmm);
extern void game_design_set_hp(shipdesign_t *sd);

#endif
