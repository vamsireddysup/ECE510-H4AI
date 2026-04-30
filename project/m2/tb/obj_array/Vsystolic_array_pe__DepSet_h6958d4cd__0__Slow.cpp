// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic_array.h for the primary calling header

#include "Vsystolic_array__pch.h"
#include "Vsystolic_array_pe.h"

VL_ATTR_COLD void Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___stl_sequent__TOP__systolic_array__DOT__gen_row__BRA__0__KET____DOT__gen_col__BRA__0__KET____DOT__u_pe__0\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__all_collected = (4U == vlSelfRef.__PVT__prod_count);
    vlSelfRef.__PVT__u_add__DOT__inf_a = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__zero_a = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__acc)));
    vlSelfRef.__PVT__u_add__DOT__b = vlSelfRef.__PVT__prod_buf
        [(3U & vlSelfRef.__PVT__add_idx)];
    vlSelfRef.__PVT__u_add__DOT__inf_b = (IData)((0x7f800000U 
                                                  == 
                                                  (0x7fffffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__zero_b = (IData)((0U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__PVT__u_add__DOT__b)));
    vlSelfRef.__PVT__u_add__DOT__sign_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__sign_s = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_l = 0U;
    vlSelfRef.__PVT__u_add__DOT__exp_diff = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_l_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_ext = 0U;
    vlSelfRef.__PVT__u_add__DOT__sig_s_aligned = 0U;
    vlSelfRef.__PVT__u_add__DOT__sum = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_sign = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_exp = 0U;
    vlSelfRef.__PVT__u_add__DOT__result_man = 0U;
    vlSelfRef.__PVT__u_add__DOT__lz = 0U;
    vlSelfRef.__PVT__u_add__DOT__norm_sig = 0U;
    vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    if (((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__acc)) 
                  & (0U != (0x7fffffU & vlSelfRef.__PVT__acc)))) 
         | ((IData)(((0x7f800000U == (0x7f800000U & vlSelfRef.__PVT__u_add__DOT__b)) 
                     & (0U != (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)))) 
            | ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_a) 
               & ((IData)(vlSelfRef.__PVT__u_add__DOT__inf_b) 
                  & ((vlSelfRef.__PVT__acc >> 0x1fU) 
                     != (vlSelfRef.__PVT__u_add__DOT__b 
                         >> 0x1fU))))))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0x7fc00000U;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else if (vlSelfRef.__PVT__u_add__DOT__inf_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (((IData)(vlSelfRef.__PVT__u_add__DOT__zero_a) 
                & (IData)(vlSelfRef.__PVT__u_add__DOT__zero_b))) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_a) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__u_add__DOT__b;
    } else if (vlSelfRef.__PVT__u_add__DOT__zero_b) {
        vlSelfRef.__PVT__u_add__DOT__add_result_comb 
            = vlSelfRef.__PVT__acc;
    } else {
        if (((0xffU & (vlSelfRef.__PVT__acc >> 0x17U)) 
             >= (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                          >> 0x17U)))) {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__acc 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__acc >> 0x17U) 
                          - (vlSelfRef.__PVT__u_add__DOT__b 
                             >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
        } else {
            vlSelfRef.__PVT__u_add__DOT__sign_l = (vlSelfRef.__PVT__u_add__DOT__b 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__sign_s = (vlSelfRef.__PVT__acc 
                                                   >> 0x1fU);
            vlSelfRef.__PVT__u_add__DOT__exp_l = (0xffU 
                                                  & (vlSelfRef.__PVT__u_add__DOT__b 
                                                     >> 0x17U));
            vlSelfRef.__PVT__u_add__DOT__exp_diff = 
                (0xffU & ((vlSelfRef.__PVT__u_add__DOT__b 
                           >> 0x17U) - (vlSelfRef.__PVT__acc 
                                        >> 0x17U)));
            vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__u_add__DOT__b 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__u_add__DOT__b)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__b)));
            vlSelfRef.__PVT__u_add__DOT__sig_s_ext 
                = ((0U == (0xffU & (vlSelfRef.__PVT__acc 
                                    >> 0x17U))) ? (0x7fffffU 
                                                   & vlSelfRef.__PVT__acc)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__PVT__acc)));
        }
        vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
            = ((0x19U <= (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))
                ? 0U : (0x1ffffffU & VL_SHIFTR_III(25,25,8, vlSelfRef.__PVT__u_add__DOT__sig_s_ext, (IData)(vlSelfRef.__PVT__u_add__DOT__exp_diff))));
        if (((IData)(vlSelfRef.__PVT__u_add__DOT__sign_l) 
             == (IData)(vlSelfRef.__PVT__u_add__DOT__sign_s))) {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                   + vlSelfRef.__PVT__u_add__DOT__sig_s_aligned));
        } else {
            vlSelfRef.__PVT__u_add__DOT__result_sign 
                = vlSelfRef.__PVT__u_add__DOT__sign_l;
            vlSelfRef.__PVT__u_add__DOT__sum = (0x1ffffffU 
                                                & ((vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    >= vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    ? 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_l_ext 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_s_aligned)
                                                    : 
                                                   (vlSelfRef.__PVT__u_add__DOT__sig_s_aligned 
                                                    - vlSelfRef.__PVT__u_add__DOT__sig_l_ext)));
        }
        if ((0U == vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__add_result_comb = 0U;
        } else if ((0x1000000U & vlSelfRef.__PVT__u_add__DOT__sum)) {
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_add__DOT__exp_l)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                                >> 1U));
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        } else {
            vlSelfRef.__PVT__u_add__DOT__lz = 0U;
            if ((1U & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                          >> 0x17U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 1U;
            }
            if (((1U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x16U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 2U;
            }
            if (((2U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x15U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 3U;
            }
            if (((3U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x14U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 4U;
            }
            if (((4U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x13U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 5U;
            }
            if (((5U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x12U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 6U;
            }
            if (((6U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x11U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 7U;
            }
            if (((7U == (IData)(vlSelfRef.__PVT__u_add__DOT__lz)) 
                 & (~ (vlSelfRef.__PVT__u_add__DOT__sum 
                       >> 0x10U)))) {
                vlSelfRef.__PVT__u_add__DOT__lz = 8U;
            }
            vlSelfRef.__PVT__u_add__DOT__norm_sig = 
                (0x1ffffffU & (vlSelfRef.__PVT__u_add__DOT__sum 
                               << (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_exp 
                = (0xffU & ((IData)(vlSelfRef.__PVT__u_add__DOT__exp_l) 
                            - (IData)(vlSelfRef.__PVT__u_add__DOT__lz)));
            vlSelfRef.__PVT__u_add__DOT__result_man 
                = (0x7fffffU & vlSelfRef.__PVT__u_add__DOT__norm_sig);
            vlSelfRef.__PVT__u_add__DOT__add_result_comb 
                = (((IData)(vlSelfRef.__PVT__u_add__DOT__result_sign) 
                    << 0x1fU) | (((IData)(vlSelfRef.__PVT__u_add__DOT__result_exp) 
                                  << 0x17U) | vlSelfRef.__PVT__u_add__DOT__result_man));
        }
    }
}

VL_ATTR_COLD void Vsystolic_array_pe___ctor_var_reset(Vsystolic_array_pe* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsystolic_array_pe___ctor_var_reset\n"); );
    Vsystolic_array__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->a_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13389479046651284173ull);
    vlSelf->b_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13248153975629471093ull);
    vlSelf->valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16540271516330450727ull);
    vlSelf->a_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3703527555082827583ull);
    vlSelf->b_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3498339381559185570ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16664408842984530663ull);
    vlSelf->result_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8916821378957780047ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__PVT__prod_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7437265918903467478ull);
    }
    vlSelf->__PVT__prod_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1723655310159365388ull);
    vlSelf->__PVT__all_collected = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13907442685068186717ull);
    vlSelf->__PVT__acc_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16031154179796196250ull);
    vlSelf->__PVT__add_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12249971608703024571ull);
    vlSelf->__PVT__acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14651699267163694450ull);
    vlSelf->__PVT__acc_valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15058973089119776951ull);
    vlSelf->__PVT__add_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10075498720355937314ull);
    vlSelf->__PVT__add_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3184162356092109851ull);
    vlSelf->__PVT__waiting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3202005946356586242ull);
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
    vlSelf->__PVT__u_mul__DOT__zero_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15440039025514486168ull);
    vlSelf->__PVT__u_mul__DOT__zero_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11813654158400340249ull);
    vlSelf->__PVT__u_mul__DOT__inf_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11509777642216954934ull);
    vlSelf->__PVT__u_mul__DOT__inf_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9374492433462755622ull);
    vlSelf->__PVT__u_mul__DOT__nan_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2913729856429015695ull);
    vlSelf->__PVT__u_mul__DOT__nan_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9187569791085653078ull);
    vlSelf->__PVT__u_mul__DOT__s1_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13266893663309073223ull);
    vlSelf->__PVT__u_mul__DOT__s1_exp = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 1870645930505698159ull);
    vlSelf->__PVT__u_mul__DOT__s1_sig_a = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9457003929490882903ull);
    vlSelf->__PVT__u_mul__DOT__s1_sig_b = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11713414819464383022ull);
    vlSelf->__PVT__u_mul__DOT__s1_is_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10968408309961205943ull);
    vlSelf->__PVT__u_mul__DOT__s1_is_inf = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7435220770441917924ull);
    vlSelf->__PVT__u_mul__DOT__s1_is_nan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8203533939392551923ull);
    vlSelf->__PVT__u_mul__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5850543668368957678ull);
    vlSelf->__PVT__u_mul__DOT__s2_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6347920345402481523ull);
    vlSelf->__PVT__u_mul__DOT__s2_exp = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 11331782912273929246ull);
    vlSelf->__PVT__u_mul__DOT__s2_product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11877438990310641955ull);
    vlSelf->__PVT__u_mul__DOT__s2_is_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10245176441097595598ull);
    vlSelf->__PVT__u_mul__DOT__s2_is_inf = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11893343738890336076ull);
    vlSelf->__PVT__u_mul__DOT__s2_is_nan = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13573478569475460040ull);
    vlSelf->__PVT__u_mul__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15110565959192358616ull);
    vlSelf->__PVT__u_mul__DOT__s3_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12571794926472015018ull);
    vlSelf->__PVT__u_mul__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15424771299583158580ull);
    vlSelf->__PVT__u_add__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1916661694661589187ull);
    vlSelf->__PVT__u_add__DOT__inf_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 489603683990206401ull);
    vlSelf->__PVT__u_add__DOT__inf_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 768751048806490306ull);
    vlSelf->__PVT__u_add__DOT__zero_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5742798517080136811ull);
    vlSelf->__PVT__u_add__DOT__zero_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13767789659884067097ull);
    vlSelf->__PVT__u_add__DOT__sign_l = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16706764334297723366ull);
    vlSelf->__PVT__u_add__DOT__sign_s = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8627019528806724491ull);
    vlSelf->__PVT__u_add__DOT__exp_l = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9216904570565535897ull);
    vlSelf->__PVT__u_add__DOT__exp_diff = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8744924859181335182ull);
    vlSelf->__PVT__u_add__DOT__sig_l_ext = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 16060168697351816638ull);
    vlSelf->__PVT__u_add__DOT__sig_s_ext = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10404926068365851005ull);
    vlSelf->__PVT__u_add__DOT__sig_s_aligned = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 3666756854624794243ull);
    vlSelf->__PVT__u_add__DOT__sum = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8713394044623200347ull);
    vlSelf->__PVT__u_add__DOT__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14678965878584277133ull);
    vlSelf->__PVT__u_add__DOT__result_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 461029855118760126ull);
    vlSelf->__PVT__u_add__DOT__result_man = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 5760115016424522730ull);
    vlSelf->__PVT__u_add__DOT__lz = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7696917633489110771ull);
    vlSelf->__PVT__u_add__DOT__norm_sig = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 529474839437119223ull);
    vlSelf->__PVT__u_add__DOT__add_result_comb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8941405365867999292ull);
}
