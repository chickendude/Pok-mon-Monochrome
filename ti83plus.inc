;ti-83 plus include file
;$05/07/2007
#define _GrBufClr _grbufclr

;system variable equates
;------------------------------
xsclt = $02
ysclt = $03
xmint = $0a
xmaxt = $0b
ymint = $0c
ymaxt = $0d
tmint = $0e
tmaxt = $0f
thetmint = $10
thetmaxt = $11
tblmint = $1a
plotstartt = $1b
nmaxt = $1d
nmint = $1f
tblstept = $21
tstept = $22
thetstept = $23
deltaxt = $26
deltayt = $27
xfactt = $28
yfactt = $29
finnt = $2b
finit = $2c
finpvt = $2d
finpmtt = $2e
finfvt = $2f
finpyt = $30
fincyt = $31
plotstept = $34
xrest = $36

;run indicators
;------------------------------------
busypause = %10101010
busynormal = %11110000

;banked call equates/macros
;-----------------------------------------------
rbr_call = $28
brt_jump0 = $50
#define bcall(xxxx) rst rbr_call\ .dw xxxx
#define bjump(xxxx) call brt_jump0\ .dw xxxx

;common restart routines
;------------------------------
rop1toop2 = $08
rfindsym = $10
rpushrealo1 = $18
rmov9toop1 = $20
rfpadd = $30

;error handler equates/macros
;-------------------------------------------
app_push_errorh = $59
app_pop_errorh = $5c
#define apponerr(xxxx) ld hl,xxxx\ call app_push_error
#define appofferr call app_pop_error

;page $1b rom calls
;--------------------------------
_jerrorno = $4000
_fonthook = $4003
_call_character_hook = $4006 ;calls character(localize) hook
_ldhlind = $4009 ;l=a=(hl),h=(hl+1)
_cphlde = $400c
_divhlby10 = $400f
_divhlbya = $4012
_kdbscan = $4015
_getcsc = $4018 ;key board scan codes
_coormon = $401b ;
_mon = $401e ;system monitor, customized through the context vectors
_monforcekey = $4021 ;
_sendkpress = $4024
_jforcecmdnochar = $4027
_jforcecmd = $402a ;
_syserrhandler = $402d ;loads error context? sp=(onsp)
_newcontext = $4030 ;(kbdkey)=0, loads context, restores page in $4000-$7fff
_newcontext0 = $4033 ;loads context
_cxputaway = $4036 ;
_cxputaway2 = $4039 ;same but also does a b_call canalphins
_cxpputaway = $403c
_cxsizewind = $403f
_cxerrep = $4042
_cxmain = $4045
_monerrhand = $4048 ;installs errorhandler to start of rom call, loads error context, jumps to mon
_appinit = $404b ;loads vector data at hl to cxmain and the rest of the vectors
_resetram = $404e
_lcd_busy = $4051 ;wait till bit 1 of port 2 is set
_min = $4054 ;op1 = lowest number between op1 and op2
_max = $4057 ;op1 = highest number between op1 and op2
_trunc = $4060
_invsub = $4063
_times2 = $4066
_plus1 = $4069 ;op1=op1+1
_minus1 = $406c
_fpsub = $406f
_fpadd = $4072
_dtor = $4075
_rtod = $4078
_cube = $407b
_timespt5 = $407e
_fpsquare = $4081
_fpmult = $4084 ;op1=op1*op2
_ljrnd = $4087 ;adjusts op1 if 0s precede the actual number... rounding? when
_invop1sc = $408a
_invop1s = $408d
_invop2s = $4090
_frac = $4093
_fprecip = $4096
_fpdiv = $4099
_sqroot = $409c
_rndguard = $409f
_rnfx = $40a2
_int = $40a5
_round = $40a8
_lnx = $40ab
_logx = $40ae
_ljnornd = $40b1 ;like _ljrnd but no rounding
_etox = $40b4
_tenx = $40b7
_sincosrad = $40ba
_sin = $40bd
_cos = $40c0
_tan = $40c3
_sinhcosh = $40c6
_tanh = $40c9
_cosh = $40cc
_sinh = $40cf
_acosrad = $40d2
_atanrad = $40d5
_atan2rad = $40d8
_asinrad = $40db
_acos = $40de
_atan = $40e1
_asin = $40e4
_atan2 = $40e7
_atanh = $40ea
_asinh = $40ed
_acosh = $40f0
_ptor = $40f3
_rtop = $40f6
_hltimes9 = $40f9
_ckop1cplx = $40fc
_ckop1real = $40ff
_angle = $4102
_cop1set0 = $4105
_cpop4op3 = $4108
_mov9op2cp = $410b
_abso1o2cp = $410e
_cpop1op2 = $4111
_op3toop4 = $4114
_op1toop4 = $4117
_op2toop4 = $411a
_op4toop2 = $411d
_op1toop3 = $4123
_op5toop2 = $4126
_op5toop6 = $4129
_op5toop4 = $412c
_op1toop2 = $412f
_op6toop2 = $4132
_op6toop1 = $4135
_op4toop1 = $4138
_op5toop1 = $413b
_op3toop1 = $413e
_op6toop5 = $4141
_op4toop5 = $4144
_op3toop5 = $4147
_op2toop5 = $414a
_op2toop6 = $414d
_op1toop6 = $4150
_op1toop5 = $4153
_op2toop1 = $4156
_mov11b = $4159
_mov10b = $415c
_mov9b = $415f
_mov9b2 = $4162 ;points to _mov9b
_mov8b = $4165
_mov7b = $4168
_mov7b2 = $416b ;same pointer as _mov7b
_op2toop3 = $416e
_op4toop3 = $4171
_op5toop3 = $4174
_op4toop6 = $4177
_mov9toop1 = $417a
_mov9op1op2 = $417d
_mov9toop2 = $4180
_movfrop1 = $4183
_op4set1 = $4186
_op3set1 = $4189
_op2set8 = $418c
_op2set5 = $418f
_op2seta = $4192
_op2set4 = $4195
_op2set3 = $4198
_op1set1 = $419b
_op1set4 = $419e
_op1set3 = $41a1
_op3set2 = $41a4
_op1set2 = $41a7
_op2set2 = $41aa
_op2set1 = $41ad
_zero16d = $41b0
_op5set0 = $41b3
_op4set0 = $41b6
_op3set0 = $41b9
_op2set0 = $41bc
_op1set0 = $41bf
_opset0 = $41c2 ;hl = location to write floating point 0
_zeroop1 = $41c5
_zeroop2 = $41c8
_zeroop3 = $41cb
_zeroop = $41ce
_clrlp = $41d1
_shracc = $41d4 ;move high nibble in a to low nibble
_shlacc = $41d7 ;move low nibble in a to high nibble
_shr18 = $41da ;insert a 0 nibble at high nibble of (hl), shift 9 bytes 1 nibble to right
_shr18a = $41dd ;insert low nibble in a at high nibble of (hl), shift 9 bytes 1 nibble to right
_shr16 = $41e0 ;insert a 0 nibble at highnibble of (hl), shift 8 bytes 1 nibble to right
_shr14 = $41e3 ;insert low nibble in a at high nibble of (hl), shift 7 bytes 1 nibble to right
_shl16 = $41e6 ;insert nibble of 0 in low nibble of (hl), shift 8 bytes (before and including (hl)) to the left 1 nibble
_shl14 = $41e9 ;insert low nibble of a in low nibble of (hl), shift 7 bytes (before and including (hl)) to the left 1 nibble
_srdo1 = $41ec
_shrdrnd = $41ef
_mantpa = $41f2 ;adds the value of a to hl which points to the end of the bcd 7 bytes long
_addprop = $41f5 ;adds the value of a to hl which points to the end of the bcd (b bytes long)
_addproplp = $41f8 ;adds the value of a and carry to hl which points to the end of the bcd (b bytes long)
_add16d  = $41fb ;adds the bcd numbers at (hl-7) and (de-7)
_add14d = $41fe ;adds the bcd numbers at (hl-6) and (de-6)
_sub16d = $4201 ;subtracts bcd numbers at (hl-7) and (de-7)
_sub14d = $4204 ;subtracts bcd numbers at (hl-6) and (de-6)
_op2exop6 = $4207
_op5exop6 = $420a
_op1exop5 = $420d
_op1exop6 = $4210
_op2exop4 = $4213
_op2exop5 = $4216
_op1exop3 = $4219
_op1exop4 = $421c
_op1exop2 = $421f
_exlp = $4222
_ckop1c0 = $4225
_ckop1fp0 = $4228
_ckop2fp0 = $422b
_posno0int = $422e
_ckposint = $4231
_ckint = $4234
_ckodd = $4237
_ckop1m = $423a
_getconop1 = $423d	;a=0 opx=57.29577951308232 (1 radian in degrees)
_getconop2 = $4240	;a=1 opx=1.570796326794897 (90 deg = pi/2)
					 ;a=2 opx=.7853981633974483 (45 deg = pi/4)
					 ;a=3 opx=.4342944819032518 (log e)
 					 ;a=4 opx=3.141592653589800 (pi)
 					 ;a=5 opx=.0174532925199433 (pi/180 = 1 degree in radians)
 					 ;a=6 opx=2.302585092994046 (ln 10)
_pidiv2 = $4243 ;not code, but a pointer to: = .db 80,15,70,79,63,26,79,48,97
_pidiv4 = $4246 ; =  =  =  =  =  =  =  = .db 7f,78,53,98,16,33,97,44,83
_pitimes2 = $4249 ;not code, but a pointer to a 2*pi in non-op format (no exponent byte)
_pi = $424c ;not code, but a pointer to a pi in non-op format (no exponent byte)
_exptohex = $424f
_op1exptodec = $4252
_ckop2pos = $4255
_ckop1pos = $4258
_clrop2s = $425b
_clrop1s = $425e
_fdiv100 = $4261 ;op1=op1/100
_fdiv10 = $4264 ;op1=op1/10
_deco1exp = $4267 ;decrease exponent by 1, this can go from $00 to $ff
_inco1exp = $426a ;op1=op1*10
_incexp = $426d ;hl points to the floating point's exponent to be multiplied by 10
_ckvalidnum = $4270
_getexp = $4273 ;a=op1's exponent, carry set if negative exponent, z if e0
_htimesl = $4276
_eop1notreal = $4279
_thetaname = $427c
_rname = $427f
_regeqname = $4282
_recurnname = $4285
_xname = $4288
_yname = $428b
_tname = $428e
_realname = $4291
_setestofps = $4294 ;moves the word at fps to es
_marktabledirty = $4297 ;looks up table variable and marks vat entry as "dirty" or selected
_op1mop2exp = $429a ;op1's exponent = op1's expoent - op2's exponent
_op1expminuse = $429d ;a=(op1+1)-e
_chkerrbreak = $42a0
_isa2bytetok = $42a3
_getlastentry = $42a6
_getlastentryptr = $42a9
_regclrchng = $42ac
_resetwintop = $42af ;takes into account grfsplitoverride and grfsplit flags
_setyup = $42b2 ;loads 7 to port 10... what does this do?
_setxup = $42b5 ;loads 5 to port 10...
_iso1nontlstorprog = $42b8 ;checks if op1 contains a list, program, group, or appvar obj name
_iso1nontemplst = $42bb ;checks if op1 contains a list (why would op1+1 contain 01, or 0d for a var name?)
_is_a_lstorclst = $42be ;checks if a = 1 or 0d
_chk_hl_999 = $42c1 ;returns nc if less than 999, throws invalid dim error if greater than or equal to 999
_equ_or_newequ = $42c4
_errd_op1notpos = $42c7
_errd_op1not_r = $42ca
_errd_op1notposint  = $42cd
_errd_op1_le_0 = $42d0
_errd_op1_0 = $42d3
_findsym_get_size  = $42d6 ;like findsym, but on output hl is the size of the variable
_sto_statvar = $42d9
_rcl_statvar = $42dc
_ckop2real = $42df
_get_x_indirect = $42e2 ;whatever this is, it uses the imathptrx locations
_memchk = $42e5
_cmpprgnamlen1 = $42e8 ;gets variable name length from hl
_cmpprgnamlen = $42eb ;gets variable name length from op1
_findprogsym = $42ee ;find the program whose name is in op1 (see chkfindsym in sdk)
_chkfindsym = $42f1
_findsym = $42f4
_insertmem = $42f7
_insertmema = $42fa ;not sure how this differs from insertmem
_enoughmem = $42fd
_cmpmemneed = $4300
_createpvar4 = $4303
_createpvar3 = $4306
_createvar3 = $4309
_createcplx = $430c
_createreal = $430f
_createtemprlist = $4312
_createrlist = $4315
_createtclist = $4318
_createclist = $431b
_createtemprmat = $431e
_creatermat = $4321
_createtempstring = $4324
_createstrng = $4327
_create0equ = $432a
_createtempequ = $432d
_createequ = $4330
_createpict = $4333
_creategdb = $4336
_createprog = $4339
_chkdel = $433c
_chkdela = $433f
_adjparser = $4342
_adjmath = $4345
_adjm7 = $4348
_delmema = $434b
_get_form_num = $434e
_delvar = $4351
_delvario = $4354
_delmem = $4357
_delvar3d = $435a
_delvar3c = $435d
_delvar3dc = $4360 ;may be incorrect
_isfixedname = $4363
_delvarentry = $4366
_datasizea = $4369
_datasize = $436c
_popmcplxo1 = $436f
_popmcplx = $4372
_movcplx = $4375
_popop5 = $4378
_popop3 = $437b
_popop1 = $437e
_poprealo6 = $4381
_poprealo5 = $4384
_poprealo4 = $4387
_poprealo3 = $438a
_poprealo2 = $438d
_poprealo1 = $4390
_popreal = $4393
_fpopcplx = $4396
_fpopreal = $4399
_fpopfps = $439c
_deallocfps = $439f
_deallocfps1 = $43a2
_allocfps = $43a5
_allocfps1 = $43a8
_pushrealo6 = $43ab
_pushrealo5 = $43ae
_pushrealo4 = $43b1
_pushrealo3 = $43b4
_pushrealo2 = $43b7
_pushrealo1 = $43ba
_pushreal = $43bd
_pushop5 = $43c0
_pushop3 = $43c3
_pushmcplxo3 = $43c6
_pushop1 = $43c9
_pushmcplxo1 = $43cc
_pushmcplx = $43cf
_exmcplxo1 = $43d2
_exch9 = $43d5
_cpyto1fps11 = $43d8
_cpyto2fps5 = $43db
_cpyto1fps5 = $43de
_cpyto2fps6 = $43e1
_cpyto1fps6 = $43e4
_cpyto2fps7 = $43e7
_cpyto1fps7 = $43ea
_cpyto1fps8 = $43ed
_cpyto2fps8 = $43f0
_cpyto1fps10 = $43f3
_cpyto1fps9 = $43f6
_cpyto2fps4 = $43f9
_cpyto6fps3 = $43fc
_cpyto6fps2 = $43ff
_cpyto2fps3 = $4402
_cpycto1fps3 = $4405
_cpyto1fps3 = $4408
_cpyfps3 = $440b
_cpyto1fps4 = $440e
_cpyto3fps2 = $4411
_cpyto5fpst = $4414
_cpyto6fpst = $4417
_cpyto4fpst = $441a
_cpyto3fpst = $441d
_cpyto2fpst = $4420
_cpyto1fpst = $4423
_cpyfpst = $4426
_cpystack = $4429
_cpyto3fps1 = $442c
_cpyto2fps1 = $442f
_cpyto1fps1 = $4432
_cpyfps1 = $4435
_cpyto2fps2 = $4438
_cpyto1fps2 = $443b
_cpyfps2 = $443e
_cpyo3tofpst = $4441
_cpyo2tofpst = $4444
_cpyo6tofpst = $4447
_cpyo1tofpst = $444a
_cpytofpst = $444d
_cpytostack = $4450
_cpyo3tofps1 = $4453
_cpyo5tofps1 = $4456
_cpyo2tofps1 = $4459
_cpyo1tofps1 = $445c
_cpytofps1 = $445f
_cpyo2tofps2 = $4462
_cpyo3tofps2 = $4465
_cpyo6tofps2 = $4468
_cpyo1tofps2 = $446b
_cpytofps2 = $446e
_cpyo5tofps3 = $4471
_cpyo2tofps3 = $4474
_cpyo1tofps3 = $4477
_cpytofps3 = $447a
_cpyo1tofps6 = $447d
_cpyo1tofps7 = $4480
_cpyo1tofps5 = $4483
_cpyo2tofps4 = $4486
_cpyo1tofps4 = $4489
_errnotenoughmem  = $448c ;only if not hl bytes free
_fpsminus9 = $448f
_hlminus9 = $4492
_erroverflow = $4495
_errdivby0 = $4498
_errsingularmat = $449b
_errdomain = $449e
_errincrement = $44a1
_errnon_real = $44a4
_errsyntax = $44a7
_errdatatype = $44aa
_errargument = $44ad
_errdimmismatch = $44b0
_errdimension = $44b3
_errundefined = $44b6
_errmemory = $44b9
_errinvalid = $44bc
_errbreak = $44bf
_errstat = $44c2
_errsignchange = $44c5
_erriterations = $44c8
_errbadguess = $44cb
_errtoltoosmall = $44ce
_errstatplot = $44d1
_errlinkxmit = $44d4
_jerror = $44d7
_noerrorentry = $44da
_pusherrorhandler = $44dd
_poperrorhandler = $44e0
_strcopy = $44e3
_strcat = $44e6
_isinset = $44e9
_sdone = $44ec
_serrort = $44ef
_snameeq = $44f2
_sunderscr = $44f5
_sfail = $44f8
_sname = $44fb
_sok = $44fe
_putmap = $4501
_putc = $4504
_disphl = $4507
_puts = $450a
_putpsb = $450d
_putps = $4510
_wputps = $4513
_putbuf = $4516
_putbuf1 = $4519
_wputc = $451c
_wputs = $451f
_wputseol = $4522 ;displays string in hl in big font, and uses ... if too long
_wdispeol = $4525
_whomeup = $4528
_setnumwindow = $452b ;based on current cursor position, sets winleft and similar (for input prompts)
_newline = $452e
_movedown = $4531
_scrollup = $4534
_shrinkwindow = $4537
_moveup = $453a
_scrolldown = $453d
_clrlcdfull = $4540
_clrlcd = $4543
_clrscrnfull = $4546
_clrscrn = $4549
_clrtxtshd = $454c
_clrwindow = $454f
_eraseeol = $4552
_eraseeow = $4555
_homeup = $4558
_getcurloc = $455b
_vputmap = $455e
_vputs = $4561
_vputsn = $4564
_vputsng = $4567
_vputsnt = $456a
_runindicon = $456d
_runindicoff = $4570
_savecmdshadow = $4573
_saveshadow = $4576
_rstrshadow = $4579
_rstrpartial = $457c
_rstrcurrow = $457f
_rstrundermenu = $4582
_rstrbotrow = $4585
_savetr = $4588 ;save top right corner of lcd so 2nd arrow can be displayed, indicinuse flag must be set
_restoretr = $458b ;restore top right corner of lcd destroyed by an arrow. indicinuse flag must be set
_getkeypress = $458e
_gettoklen = $4591 ;input: hl=pointer to token. output: a=lenght of string, hl=pointer to string on page 1
_get_tok_strng = $4594 ;input: hl=pointer to token. output: op3=string of the token, a=length of string
_gettokstring = $4597 ;input: de=token. output: hl=pointer to the string on page 1
_putbpatbuf2 = $459a
_putbpatbuf = $459d
_putbpat = $45a0
_putccheckscroll = $45a3
_dispeol = $45a6
_fdispeol = $45a9
_makerowcmd = $45ac
_totostrp = $45af
_setvarname = $45b2
_dispdone = $45b5
_finishoutput = $45b8
_curblink = $45bb
_cursoroff = $45be
_hidecursor = $45c1
_cursoron = $45c4
_showcursor = $45c7
_keytostring = $45ca
_pulldownchk = $45cd ;something wrong here
_menucatcommon = $45d0
_zifcatalog = $45d3
_zifmatrixmenu = $45d6 ;_loadcurcat
_loadmenunum = $45d9
_loadmenunuml = $45dc
_mencatret = $45df ;restores display as though a menu were just cleared (restores some flags too)
_menuswitchcontext = $45e2 ;switches to context in a, calls menu hook with a=3, set 5,(iy+$16) for some sort of override to not make switc
_menuedkey = $45e5
;$45e8
_notalphnum = $45eb
_savesavedflags = $45ee
_setmenuflags = $45f1
_rstrsomeflags = $45f4
_rstroscreen = $45f7 ;restores savesscreen to the display
_saveoscreen = $45fa ;stores display in savesscreen
_displistname = $45fd ;_seeiferrorcx
_prevcontext = $4600
_comparecontext = $4603
_adrmrow = $4606
_adrmele = $4609
_getmatop1a = $460c
_getm1toop1 = $460f
_getm1top1a = $4612
_getmtoop1 = $4615
_puttom1a = $4618
_puttoma1 = $461b
_puttomat = $461e
_mat_el_div = $4621
_cmatfun = $4624
_rowech_poly = $4627
_rowechelon = $462a
_adrlele = $462d
_getl1toop1 = $4630
_getl1top1a = $4633
_getltoop1 = $4636
_getl1toop2 = $4639
_getl1top2a = $463c
_getl2top1a = $463f
_puttola1 = $4642
_puttol = $4645
_maxminlst = $4648
_llow = $464b
_lhigh = $464e
_lsum = $4651
cumsum = $4654
_tofrac = $4657
_seqset = $465a
_seqsolve = $465d
_cmp_num_init = $4660
_binopexec = $4663
_exmean1 = $4666
_set2mvlptrs = $4669
_setmat1 = $466c
_createtlist = $466f
_unopexec = $4672
_threeexec = $4675
_restoreerrno = $4678
_fourexec = $467b
_fiveexec = $467e
_cpyto2es1 = $4681
_cpyto6es1 = $4684
_cpyto1es1 = $4687
_cpyto3es1 = $468a
_cpyto3es2 = $468d
_cpyto2es2 = $4690
_cpyto1es2 = $4693
_cpyto2es3 = $4696
_cpyto1es3 = $4699
_cpyto3es4 = $469c
_cpyto6es3 = $469f
_cpyto2es4 = $46a2
_cpyto1es4 = $46a5
_cpyto2es5 = $46a8
_cpyto1es5 = $46ab
_cpyto4est = $46ae
_cpyto2est = $46b1
_cpyto1est = $46b4
_cpyto2es6 = $46b7
_cpyto1es6 = $46ba
_cpyto2es7 = $46bd
_cpyto1es7 = $46c0
_cpyto2es8 = $46c3
_cpyto1es8 = $46c6
_cpyto1es9 = $46c9
_cpyto2es9 = $46cc
_cpyto2es10 = $46cf
_cpyto1es10 = $46d2
_cpyto2es11 = $46d5
_cpyto1es11 = $46d8
_cpyto2es12 = $46db
_cpyto1es12 = $46de
_cpyto2es13 = $46e1
_cpyto1es13 = $46e4
_cpyto1es14 = $46e7
_cpyto1es16 = $46ea
_cpyto1es17 = $46ed
_cpyto1es18 = $46f0
_cpyto1es15 = $46f3
_cpyto2es15 = $46f6
_cpyo1toest = $46f9
_cpyo1toes1 = $46fc
_cpyo6toes1 = $46ff
_cpyo6toes3 = $4702
_cpyo1toes2 = $4705
_cpyo2toes2 = $4708
_cpyo1toes3 = $470b
_cpyo1toes4 = $470e
_cpyo1toes5 = $4711
_cpyo1toes6 = $4714
_cpyo1toes7 = $4717
_cpyo2toes4 = $471a
_cpyo2toes5 = $471d
_cpyo2toes6 = $4720
_cpyo2toes7 = $4723
_cpyo2toes8 = $4726
_cpyo2toes9 = $4729
_cpyo1toes8 = $472c
_cpyo1toes9 = $472f
_cpyo1toes10 = $4732
_cpyo1toes11 = $4735
_cpyo1toes12 = $4738
_cpyo1toes13 = $473b
_cpyo1toes14 = $473e
_cpyo1toes15 = $4741
_evalf3a = $4744
_getk = $4747 ;?
_settitle = $474a
_dispvarval = $474d
_recalled = $4750 ;_setupbuffer
_createnumeditbuf = $4753
_processbufkeys = $4756 ;may be default key processing like [clear], etc. especially for an edit buffer.
_callcommon = $4759
_commonkeys = $475c
_leftmore = $475f
_fdel = $4762
_fclear = $4765
_finsdisp = $4768 ;michael says _finsdisp02 = $4768 (something's not right)
_finsdisp02 = $476b ;_setindicator
_closeeditbufnor = $476e
_releasebuffer = $4771
_varnametoop1l = $4774
_nametoop1 = $4777
_numpputaway = $477a
_numredisp = $477d
_numerror02 = $4780
_load_sfont = $4783
_sfont_len = $4786
_initnumvec = $4789
_setxxop1 = $478c
_setxxop2 = $478f
_setxxxxop2 = $4792
_uclines = $4795
_cline = $4798
_clines = $479b
_xrooty = $479e
_ytox = $47a1
_zmstats = $47a4
_point_stat_hlp = $47a7
_drawsplot = $47aa
_initnewtracep = $47ad
_splotcoord = $47b0
_splotright = $47b3
_splotleft = $47b6
_cmpboxinfo = $47b9
_nextplot = $47bc
_prevplot = $47bf
_clrprevplot = $47c2
_put_index_lst = $47c5
_get_index_lst = $47c8
_heap_sort = $47cb
_stogdb2 = $47ce
_rclgdb2 = $47d1
_circcmd = $47d4
_grphcirc = $47d7
_mov18b = $47da
_darkline = $47dd
_iline = $47e0
_ipoint = $47e3
_xyrndboth = $47e6
_xyrnd = $47e9
_checktop = $47ec
_checkxy = $47ef
_darkpnt = $47f2
_cpoints = $47f5
_wtov = $47f8
_vtowhlde = $47fb
_xitof = $47fe
_yftoi = $4801
_xftoi = $4804
_traceoff = $4807
_grredisp = $480a
_gdisptoken = $480d
_grdecoda = $4810
_labcoor = $4813
_coordisp = $4816 ;draws x & y coordinates (or r and theta if polargc)
_tmpequnosrc = $4819
_grlabels = $481c
_ypixset = $481f
_xpixset = $4822
_copyrng = $4825
_valcur = $4828
_grputaway = $482b
_rstgflags = $482e
_grreset = $4831
_xycent = $4834
_zoomxycmd = $4837
_cptdely = $483a
_cptdelx = $483d
_setfuncm = $4840
_setseqm = $4843
_setpolm = $4846
_setparm = $4849
_zmint = $484c
_zmdecml = $484f
_zmprev = $4852
_zmusr = $4855
_setuzm = $4858
_zmfit = $485b
_zmsquare = $485e
_zmtrig = $4861
_setxminmax = $4864
_zoodefault = $4867
_grbufcpy = $486a
_drawsplitline = $486d
_restoredisp = $4870
_fnddb = $4873
_alleq = $4876
_fndallseleq = $4879
_nexteq = $487c
_preveq = $487f
_blinkgcur = $4882
_nbcursor = $4885
_statmark = $4888
_chktextcurs = $488b
_regraph = $488e
_dorefflags02 = $4891 ;something wrong here
initnseq = $4894
_yres = $4897 ;_plotptxy2
_ceiling = $489a ;ceil(op1)
_putxy = $489d ;draws x & y coordinates (regardless of polargc)
_putequno = $48a0
_pdspgrph = $48a3
_horizcmd = $48a6
_vertcmd = $48a9
_linecmd = $48ac
_unlinecmd = $48af
_pointcmd = $48b2
_pixeltest = $48b5
_pixelcmd   = $48b8
_tanlnf = $48bb
_drawcmd_init = $48be
_drawcmd = $48c1
_shadecmd = $48c4
_invcmd = $48c7
_statshade = $48ca
_dspmattable = $48cd
_dsplsts = $48d0
_closeeditbuf = $48d3
_parseeditbuf = $48d6
_putsm = $48d9
_dspcurtbl = $48dc
_dspgrtbl = $48df
_zerotemplate = $48e2
_settblrefs = $48e5
_disptblbot = $48e8
_disptbltop = $48eb
_disptblbody = $48ee
_vputblank = $48f1
_tbltrace = $48f4
_displistnamey = $48f7
_curnamelength = $48fa
_nametobuf = $48fd
_jpromptcursor = $4900
_bufleft = $4903
_bufright = $4906
_bufinsert = $4909
_bufqueuechar = $490c
_bufreplace = $490f
_bufdelete = $4912
_bufpeek = $4915
_bufpeek1 = $4918
_bufpeek2 = $491b
_bufpeek3 = $491e
_buftobtm = $4921
_setupeditequ = $4924
_buftotop = $4927
_iseditfull = $492a
_iseditempty = $492d
_isattop = $4930
_isatbtm = $4933
_bufclear = $4936
_jcursorfirst = $4939
_jcursorlast = $493c
_cursorleft = $493f
_cursorright = $4942
_cursorup = $4945
_cursordown = $4948
_cursortooffset = $494b
_insdisp = $494e
_fdispbol1 = $4951
_fdispbol = $4954
_dispeow = $4957
_disphead = $495a
_disptail = $495d
_puttokstring = $4960
_setupeditcmd = $4963
_setemptyeditequ = $4966
_setemptyeditptr = $4969
_closeeditequ = $496c
_getprevtok = $496f
_getkey = $4972
_canindic = $4975
_lcd_driveron = $4978
_dfmin2 = $497b
_formdisp = $497e
_formmatrix = $4981
_wscrollleft = $4984
_wscrollup = $4987
_wscrolldown = $498a
_wscrollright = $498d
_formereal = $4990
_formerealtok = $4993
_formdcplx = $4996
_formreal = $4999
_formscrollup = $499c
_setwinabove = $499f
_disarmscroll = $49a2
_op1toedit = $49a5
_mintoedit = $49a8
_rclvartoedit = $49ab
_rclvartoeditptr = $49ae
_rclentrytoedit = $49b1
_rcltoqueue = $49b4 ;recalls bytes at op1 into edit buffer
_formtotok = $49b7
_disp_interval = $49ba
_displstname = $49bd
_dispslstnamehl = $49c0
_editequ = $49c3
_closeequfield = $49c6
_autoselect = $49c9
_dispyeos = $49cc
_dispnumeos = $49cf
_setupdispeq = $49d2
_dispforward = $49d5
_dispyprompt2 = $49d8
_stringwidth = $49db
_disperrorscreen = $49de ;displays top row of error screen (error message)
_popcx = $49e1 ;moves 14 bytes at cxprev to cxmain, 15th byte goes to replace appflags
_loadnoeentry = $49e4
_savescreen = $49e7
_retscreen = $49ea
_retscreenerr = $49ed
_checksplitflag = $49f0
_solveredisp = $49f3
_solvedisp = $49f6
_itemname = $49f9
_setnorm_vals = $49fc
_setyoffset = $49ff ;sets up yoffset and next 4 bytes (possibly specialized for the table editor)
_convkeytotok = $4a02
_convfckeytotok = $4a05
_convfekeytotok = $4a08
_toktokey = $4a0b
_sendskipexitpacket = $4a0e
_getvarcmd = $4a11
_sendvarcmd = $4a14
_sendscreenshot = $4a17
keyscnlnk = $4a1a
_deselectallvars = $4a1d
_delres = $4a20
_convlctolr = $4a23
_redimmat = $4a26
_inclstsize = $4a29
_insertlist = $4a2c
_dellistel = $4a2f
_editprog = $4a32
_closeprog = $4a35
_clrgraphref = $4a38
_fixtempcnt = $4a3b
_savedata = $4a3e
_restoredata = $4a41
_findalphaup = $4a44
_findalphadn = $4a47
_cmpsyms = $4a4a
_createtemp = $4a4d
_cleanall = $4a50
_movetonextsym = $4a53 ;input: hl=pointer to type byte of vat entry. output: hl = pointer to next entry's type byte
_convlrtolc = $4a56
_tblscreendn = $4a59 ;something is not right here
_tblscreenup = $4a5c
_screenup = $4a5f
_screenupdown = $4a62
_zifrclhandler = $4a65
_zifrclkapp = $4a68
_rclkeyrtn = $4a6b
_rclkey = $4a6b
_rclregeq_call = $4a6e
_rclregeq = $4a71
_initnameprompt = $4a74
_nameprompt2 = $4a77
_catalogchk = $4a7a
_clrtr = $4a7d
_quad = $4a80
_graphquad = $4a83
_bc2noreal = $4a86
;$4a89
_errnonreal = $4a8c ;err:data type if top b numers from fps are non-real
_write_text = $4a8f
_forseqinit = $4a92
_grphpars = $4a95
_plotpars = $4a98
_parseinp = $4a9b
_parseoff = $4a9e
_parsescan = $4aa1
_getparse = $4aa4
_saveparse = $4aa7
_initpflgs = $4aaa
_ckendlinerr = $4aad
_op2set60 = $4ab0
_getstatptr = $4ab3
_cmp_statptr = $4ab6
_varsysadr = $4ab9
_stosystok = $4abc
_stoans = $4abf
_stotheta = $4ac2
_stor = $4ac5
_stoy = $4ac8
_ston = $4acb
_stot = $4ace
_stox = $4ad1
_stoother = $4ad4
_rclans = $4ad7
_rcly = $4ada
_rcln = $4add
_rclx = $4ae0
_rclvarsym = $4ae3
_rclsystok = $4ae6
_stmatel = $4ae9
_stlstvecel = $4aec
_convop1 = $4aef
_find_parse_formula = $4af2
_parse_formula = $4af5
_fetchquotedstring = $4af8
_fetchnumline = $4afb
;$4afe
_parseinpgraph = $4b01 ;same as _parseinp except 3,(iy+$1f) is graph/split screen override, or something
_parseinpgraphreset = $4b04 ;_parseinpgraph except zeroes out iy+6/7, resets 3,(iy+$1a) & 0,(iy+$1f), fmtflags->fmtoverride, parse within parseinp?
_parseinplastent = $4b07 ;parseinp on program $05,$23,$00
_erroncertaintypes = $4b0a ;err:data type if a is one of a couple of values...subroutine in parseinp, somehow
_createpair = $4b0d
_pushnum = $4b10
_inccurpcerrend = $4b13
_errend = $4b16
_commaerrf = $4b19
_commaerr = $4b1c
_steqarg2 = $4b1f
_steqarg = $4b22
_inparg = $4b25
_steqarg3 = $4b28
_nxtfetch = $4b2b
_ckfetchvar = $4b2e
_fetchvara = $4b31
_fetchvar = $4b34
_ckendlin = $4b37 ;gets parse byte in a and then _ckendexp
_ckendexp = $4b3a ;checks a for $3e or $3f
_ckparsend = $4b3d
_stotypearg = $4b40
_convdim = $4b43
_convdim00 = $4b46
_aheadequal = $4b49
_parsaheads = $4b4c
_parsahead          = $4b4f
_ansname = $4b52
_stocmpreals = $4b55
_getdeptr = $4b58
_push2boper = $4b5b ;push the value in bc onto the operator stack
_pop2boper = $4b5e ;pop 2 bytes on the operator stack to bc
_pushoper = $4b61 ;push the value in a onto the operator stack
_popoper = $4b64 ;pop 1 byte on the operator stack to a
_find_e_undef = $4b67
_sttmpeq = $4b6a
_findeol = $4b6d
_brkinc = $4b70
_incfetch = $4b73
_curfetch = $4b76
_random = $4b79
_storand = $4b7c
_randinit = $4b7f
_resetstacks = $4b82 ;(onsp)->(errsp), (fpbase)->(fps), (opbase)->(ops)
_factorial = $4b85
_yonoff = $4b88
_eqselunsel = $4b8b
_itsolver = $4b8e
_gritsolver = $4b91
_itsolverb = $4b94
_itsolvernb = $4b97
_extest_int = $4b9a
_dist_fun = $4bad
_loggamma = $4ba0
_onevar = $4ba3
_onevars_0 = $4ba6
_ordstat = $4ba9
_initstatans2 = $4bac
_anova_spec = $4baf
_outputexpr = $4bb2
_centcursor = $4bb5
_text = $4bb8
_finishspec = $4bbb
_trcyfunc = $4bbe
_rcl_seq_x = $4bc1
_rclseq2 = $4bc4
_grpputaway = $4bc7
_ckvaldelx = $4bca
_ckvaldelta = $4bcd
_grbufclr = $4bd0
_grbufcpy_v = $4bd3
_fndseleq = $4bd6
_clrgraphxy = $4bd9
_nedxt_y_style = $4bdc
_plotpt = $4bdf
_newindep = $4be2
_axes = $4be5
_setpenx = $4be8
_setpeny = $4beb
_setpent = $4bee
_tan_equ_disp = $4bf1
_putans = $4bf4
_dispop1a = $4bf7
_mathtanln = $4bfa
_enddraw = $4bfd
_settblgraphdraw = $4c00
_startdialog = $4c03
_dialoginit = $4c06
_getdialognumop1 = $4c09
_setdialognumop1 = $4c0c
_getdialognumhl = $4c0f
_errargumento123 = $4c12 ;err:argument if op2>op1 or op1>op3
_setdialogkeyoverride = $4c15
_resdialogkeyoverride = $4c18
_forcedialogkeypress = $4c1b
_dialogstartgetkey = $4c1e
_startdialog_override = $4c21
_calldialogcallback = $4c24
_setdialogcallback = $4c27
_resdialogcallback = $4c2a
_copydialognum = $4c2d
_memclear = $4c30
_memset = $4c33
_reloadappentryvecs = $4c36
_pointon = $4c39
_executenewprgm = $4c3c
_strlength = $4c3f
_vputmaprec = $4c42
_getrompage = $4c45
_findappup = $4c48
_findappdn = $4c4b
_findapp = $4c4e
_executeapp = $4c51
_monreset = $4c54
;$4c57
;$4c5a
_iscontextkey = $4c5d
_ibounds = $4c60
_ioffset = $4c63
_drawcirc2 = $4c66
_canalphins = $4c69
cxredisp = $4c6c
_getbasever = $4c6f
_opset0de = $4c72 ;loads a floating point 0 to location de
_appgetcbl = $4c75
_appgetcalc = $4c78
_savedisp = $4c7b
_setignorekey   = $4c7e ;set 1,(iy+$28) / ret
_setsendthiskeyback = $4c81 ;set 2,(iy+$28) / ld (kbdkey),a / ret
_disableapd = $4c84
_enableapd = $4c87 ;set apdable,(iy+apdflags)
_jforcecmdnochar2 = $4c8a ;$2.41 at least
_set2iy34 = $4c8d ;set 2,(iy+$34) / ret
_forcecmd = $4c90
_apdsetup = $4c93
_get_numkey = $4c96
_appsetup = $4c99 ;or _appcleanup, or something
_handlelinkkeyactivity = $4c9c
_jforcecmdnochar3 = $4c9f ;2.41 at least
_releasesedit = $4ca2
_initsmalleditline = $4ca5
_startsmalledit = $4ca8
;$4cab
_sgettokstring = $4cae
_loadpattern = $  = $4cb1
_sstringlength = $4cb4
_restorepencol = $4cb7
;$4cba
_donothing = $4cbd
_forcesmalleditreturn = $4cc0
;$4cc3 ;saves context
;$4cc6
;$4cc9
;$4ccc
_veraseeol = $4ccf
;$4cd2
;$4cd5
_gotoerr = $4cd8
_initsmalleditbox = $4cdb
;$4cde
_emptyhook = $4ce1
_forcesmalleditreturn2 = $4ce4
;$4ce7 ;same as $4cc3
;$4cea
_clearrow = $4ced
;$4cf0
;$4cf3
;$4cf6
;$4cf9
;$4cfc
;$4cff
;$4d02
;$4d05
;$4d08
;$4d0b
;$4d0e
;$4d11
;$4d14
;$4d17
;$4d1a
;$4d1d
;$4d20
;$4d23
_appscreenupdown = $4d26 ;shifts screen up/down, a is lcd row, h is number of lines to shift, (op1)-(op1+3) are something
_appscreenupdown1 = $4d29 ;shifts screen up/down, but really no clue what the inputs are (all registers and (op1)-(op1+3))
;$4d2c
_initsmalleditlinevar = $4d2f
_initsmalleditlineop1 = $4d32
_initsmalleditboxvar = $4d35
_initsmalleditboxop1 = $4d38
;$4d3b
_restartdialog = $4d3e
_errcustom1 = $4d41
_errcustom2 = $4d44
_appstartmouse = $4d47
_appstartmousenosetup = $4d4a
_appmousegetkey = $4d4d
_appdispmouse = $4d50
_apperasemouse = $4d53
_appsetupmousemem = $4d56
_getdisprowoffset = $4d59 ;hl=a*12 (intended for a to be row and hl becomes offset into plotsscreen)
_clearrect = $4d5c
_invertrect = $4d5f
_fillrect = $4d62
_appupdatemouse = $4d65
_appdispprevmouse = $4d68 ;might bring previous keypress's movement to current coordinates with flags to not display
;$4d6b ;restores some cursor flags and stuff
_initcellbox = $4d6e
_drawcell = $4d71
;$4d74
_invertcell = $4d77
_setcelloverride = $4d7a
_drawrectborder = $4d7d
_clearcell = $4d80
_covercell = $4d83
_eraserectborder = $4d86
_fillrectpattern = $4d89
_drawrectborderclear = $4d8c
;$4d8f ;mouse subroutine
;$4d92
_verticalline = $4d95
_iboundsfull = $4d98
_displayimage = $4d9b
;$4d9e ;does something dumb with ports 10/11
;$4da1 ;mouse subroutine
_appupdatemousecoords = $4da4
_shiftbitsleft = $4da7 ;mouse subroutine, shifts b bits left from de sprite to hl one
;$4daa ;mouse subroutine
;$4dad ;mouse subroutine
;$4db0 ;mouse subroutine
;$4db3 ;mouse subroutine
;$4db6 ;mouse subroutine
;$4db9 ;mouse subroutine
;$4dbc ;mouse subroutine
_appupdatemouserow = $4dbf
_appdrawmouse = $4dc2 ;set 2,(iy+$2c) for apperasemouse, reset for appdispmouse
_appdrawmousedirect = $4dc5 ;pretty much _appdrawmouse, but you pass lcd column in a
_cpoint = $4dc8
_deleteapp = $4dcb
_appupdatemousexy = $4dce
_setmodecellflag = $4dd1
_resetmodecellflag = $4dd4
_ismodecellset = $4dd7
_getmodecellflag = $4dda
;$4ddd
_cellboxmanager = $4de0
_startnewcell = $4de3
;$4de6
_cellcursorhandle = $4de9
;$4dec
;$4def
_clearcurcell = $4df2
_drawcurcell = $4df5
_invertcurcell = $4df8
_covercurcell = $4dfb
_blinkcell = $4dfe
_blinkcellnolookup = $4e01
_blinkcurcell = $4e04
_blinkcelltoon = $4e07
_blinkcelltoonnolookup = $4e0a
_blinkcurcelltoon = $4e0d
_blinkcelltooff = $4e10
_blinkcelltooffnolookup = $4e13
_blinkcurcelltooff = $4e16
_getcurmodecellflag = $4e19
;$4e1c
_startsmalleditreturn = $4e1f
;$4e22
;$4e25
_cellkhandle = $4e28
_errchkalphabox = $4e2b
;$4e2e
;$4e31
;$4e34
;$4e37
_eraseallcells = $4e3a
_iscurmodecellset = $4e3d
;$4e40
_initalphabox = $4e43
;$4e46
;$4e49
_drawblnkcell = $4e4c
_clearblnkcell = $4e4f
_invertblnkcell = $4e52
_appmouseforcekey = $4e55
_appsetupmousememcoords = $4e58 ;this is _appsetupmousemem except you pass starting coordinates in hl
_appmovemouse = $4e5b ;this is _appmouseforcekey and then updating coordinates
_getstringinput = $4e5e
_getstringinput2 = $4e61
;$4e64
_horizontalline = $4e67
_createappvar = $4e6a
_createprotprog = $4e6d
_createvar = $4e70
_asmcomp = $4e73
_getasmsize = $4e76
_squishprgm = $4e79
_executeprgm = $4e7c
_chkfindsymasm = $4e7f
_parseprgmname = $4e82
_csub = $4e85
_cadd = $4e88
_csqaure = $4e8b
_cmult = $4e8e
_crecip = $4e91
_cdiv = $4e94
_cabs = $4e97
_addsquares = $4e9a
_csqroot = $4e9d
_cln = $4ea0
_clog = $4ea3
_ctenx = $4ea6
_cetox = $4ea9
_cxrooty = $4eac
;$4eaf
_cytox = $4eb2
_invertnonreal = $4eb5
_cplxmult = $4eb8
_cplxdiv = $4ebb
_cplxtrunc = $4ebe
_cplxfrac = $4ec1
_cplxfloor = $4ec4
_sendheaderpacket = $4ec7
_canceltransmission = $4eca
_sendscreencontents = $4ecd
_sendramvardata = $4ed0
_sendramcmd = $4ed3
_sendpacket = $4ed6
_receiveack = $4ed9
_send4bytepacket = $4edc
_senddatabyte = $4edf
_send4bytes = $4ee2
_sendabyte = $4ee5
_sendcbyte = $4ee8
_getsmallpacket = $4eeb
_getdatapacket = $4eee
_sendack = $4ef1
_get4bytes = $4ef4
_get3bytes = $4ef7
_rec1stbyte = $4efa
_rec1stbytenc = $4efd
_continuegetbyte = $4f00
_recabyteio = $4f03
_receivevar = $4f06
_receivevardataexists = $4f09
_receivevardata = $4f0c
_srchvlstup = $4f0f
_srchvlstdn = $4f12
_sendvariable = $4f15
_get4bytescursor = $4f18
_get4bytesnc = $4f1b
_convert85list = $4f1e
_senddirectorycontents = $4f21
_sendreadypacket = $4f24
_convert85real = $4f27
_ret_6 = $4f2a
_sendcertificate = $4f2d ;sends certificate in header/data packets, flash must be unlocked, used with sending an application in link menu
_sendapplication = $4f30
_sendosheader = $4f33
_sendospage = $4f36
_sendos = $4f39
_flashwritedisable = $4f3c
_sendcmd = $4f3f
_sendosvalidationdata = $4f42
_disp = $4f45
_sendgetkeypress = $4f48
_rejectcommand = $4f4b
_checklinklines = $4f4e
_gethookbyte = $4f51
_getbytepaged = $4f54
_cursorhook = $4f57
_call_library_hook = $4f5a
_call_rawkey_hook = $4f5d
_setcursorhook = $4f60 ;enable cursor hook
_enablelibraryhook = $4f63
_setgetkeyhook = $4f66
_clrcursorhook = $4f69
_disablelibraryhook = $4f6c
_clrrawkeyhook   = $4f6f
_resethookbytes = $4f72
_adjustallhooks = $4f75
_getkeyhook = $4f78
_setgetcschook = $4f7b
_clrgetkeyhook = $4f7e
_call_linkactivity_hook = $4f81
_enablelinkactivityhook = $4f84
_disablelinkhook = $4f87
_getsmallpacket2 = $4f8a
_enablecatalog2ook = $4f8d
_disablecatalog2ook = $4f90
_enablelocalizehook = $4f93
_disablelocalizehook = $4f96
_settokenhook = $4f99
_cleartokenhook = $4f9c
;$4f9f ld hl,$92c6 / ld a,($92c5) / res 2,a / cp (hl) / ret
;$4fa2 hl=11*($92fc)+$92c9 / ld a,(hl) / and f / cp 2 / ret
;$4fa5
_bit_vertsplit = $4fa8
_sethomescreenhook = $4fab
_clrhomescreenhook = $4fae
_setwindowhook = $4fb1
_disablewindowhook = $4fb4
_setgraphmodehook = $4fb7
_disablegraphhook = $4fba
;$4fbd
;$4fc0
_jforcewindowsettings = $4fc3
_delvararc = $4fc6
_delvarnoarc = $4fc9
_setallplots = $4fcc
_setyedithook  = $4fcf
_disableyequhook = $4fd2
_jforceyequ = $4fd5
_arc_unarc = $4fd8 ;checks for low battery
_archivevar = $4fdb ;set 0,(iy+$24) to check for low battery first
_unarchivevar = $4fde
_dialogkeyhook = $4fe1 ;rawkey hook used by os for dialog context
_setfonthook = $4fe4
_clrfonthook = $4fe7
_setregraphhook = $4fea
_disableregraphhook = $4fed
_rungraphinghook = $4ff0
_settracehook = $4ff3
_disabletracehook = $4ff6
_runtracehook = $4ff9
_nderiv = $4ffc
;$4fff
_jforcegraphnokey = $5002
_jforcegraphkey = $5005
_poweroff = $5008
_getkeyretoff = $500b ;same as getkey, only returns koff if 2nd+on is pressed
_findgroupsym = $500e
_fillbasepagetable = $5011
_arcchk = $5014
_flashtoram = $5017
_loaddeindpaged = $501a
_loadcindpaged = $501d
_setuppagedptr = $5020
_pagedget = $5023
_setparserhook = $5026
_clearparserhook = $5029
_setappchangehook  = $502c
_clearappchangehook = $502f
_enablegraphicshook = $5032
_disablegraphicshook = $5035
;$5038
_ilinenohook = $503b
;$503e
_deletetempprograms = $5041
_enablecatalog1ook = $5044
_disablecatalog1ook = $5047
_enablehelphook = $504a
_disablehelphook = $504d
_dispcatalogend = $5050
_getmenukeypress = $5053
_getcatalogitem = $5056
_runcatalog2ook = $5059
_runcatalog1ook = $505c
;$505f
;$5062
_dispmenutitle = $5065
;$5068
_enablecxredisphook = $506b
_disablecxredisphook = $506e
_bufcpy = $5071
_bufclr = $5074
_unopexec2 = $5077
_binopexec2 = $507a
_loadmenub = $507d ;clears screen and loads menu from b, plus a couple flag changes
_displayvarinfo = $5080
_setmenuhook = $5083
_clearmenuhook = $5086
_getbcoffsetix = $5089
_getbcoffsetix2 = $508c
_forcefullscreen = $508f
_getvariabledata = $5092
_findswapsector = $5095
_copyflashpage = $5098
_findappnumpages = $509b
_hlminus5 = $509e
_sendarcpacket = $50a1
_forcegraphkeypress = $50a4
_donothing3 = $50a7
_formbase = $50aa
;$50ad
_isfragmented = $50b0
_chk_batt_low = $50b3
_chk_batt_low_2 = $50b6
_arc_unarc2 = $50b9 ;identical to _arc_unarc, except you can choose to res 0,(iy+$24) to skip low battery check
_getappbasepage = $50bc ;input: a=one of an app's pages. output: a=app's first page
_setexspeed = $50bf
_rclexit = $50c2
_groupallvars = $50c5
_ungroupvar = $50c8
_writetoflash = $50cb ;receiveapplication or something like that on oses below 2.40
_setsilentlinkhook = $50ce
_disablesilentlinkhook = $50d1
_twovarset = $50d4
_execclass2token = $50d7
_execclass3token = $50da
_getsysinfo = $50dd
_nzif83plus = $50e0
_linkstatus = $50e3
_donothing2 = $50e6 ;originally for ti-navigator
_keyboardgetkey = $50e9
_runapplib = $50ec
_findspecialappheader = $50ef
_sendusbdata = $50f2
_appgetcblusb = $50f5
_appgetcalcusb = $50f8
_getvarcmdusb = $50fb
;$50fe
_tenx2 = $5101
;$5104
;$5107
_getvarversion = $510a
;$510d
;$5110
_deletetempeditequ = $5113
_jcursorfirst2 = $5116
;$5119
;$511c
_wputseol2 = $511f ;same except res 0,(iy+$0e) first
_inverttextinsmode = $5122
;$5125
_resetdefaults = $5128
_zerofinancevars = $512b
_dispheader = $512e
_jforcegroup = $5131
;$5134
;$5137
_dispcoords = $513a
;$513d
;$5140
;$5143
;$5146
;$5149
;$514c
_getdate = $514f
;$5152
_getdtfmt = $5155
;$5158
_gettime = $515b
;$515e
_gettmfmt = $5161
;$5164
_setzeroone = $5167
;$516a
_isonetwothree = $516d
;$5170
_isop112or24 = $5173
_chktimer0 = $5176
;$5179
;$517c
_clrwindowandflags = $517f
_setmachineid = $5182
_resetlists = $5185
;$5188
;$518b
;$518e
_execlib = $5191
;$5194
_cpop1op2rounded = $5197
_cpop1op2rounded2 = $519a
_openlib = $519d
;$51a0
;$51a3
_resetioprompt = $51a6
;$51a9
_setupeditor = $51ac
_sorta = $51af
_sortd = $51b2
;$51b5
_isop1resid = $51b8
;$51bb
;$51be
;$51c1
_forcemodekeypress = $51c4 ;forces a keypress (and calls help hook) on any of several mode-setting contexts
_dispaboutscreen = $51c7
_chkhelphookver = $51ca
_disp32 = $51cd
;$51d0
;$51d3
;$51d6
;$51d9
_drawtableeditor = $51dc ;draws table editor lines
;$51df
;$51e2
;$51e5
;$51e8
;$51eb
;$51ee
_matrixname = $51f1
;$51f4
;$51f7
;$51fa
;$51fd
;$5200
;$5203
;$5206
;$5209
;$520c
;$520f
_setupemptyedittempequ = $5212
;$5215
;$5218
;$521b
;$521e
_chk_batt_level = $5221
;$5224
;$5227
;$522a
;$522d
;$5230
_gotolastrow = $5233
_rectborder = $5236
;$5239
;$523c
;$523f
_loada5 = $5242
;$5245
_namedlisttoop1 = $5248
;$524b
;$524e
;$5251
_initusbdevicecallback = $5254
_killusbdevice = $5257
_setusbconfiguration = $525a
_requestusbdata = $525d
_stopreceivingusbdata = $5260
_findappheaderbypage = $5263
_findnextheaderbypage = $5266
_ismatchinglaunchapp = $5269
_inittimer = $526c
_killtimer = $526f
_starttimer = $5272
_restarttimer = $5275
_stoptimer = $5278
_waittimer = $527b
_checktimer = $527e
_checktimerrestart = $5281
_setvertgraphactive = $5284
_clearvertgraphactive = $5287
_enableusbhook = $528a
_disableusbhook = $528d
_initusbdevice = $5290
_killusbperipheral = $5293
;$5296
;$5299
_graphline = $529c
;$529f
;$52a2
;$52a5
;$52a8
;$52ab
;$52ae
_ziftableeditor = $52b1
;$52b4
;$52b7
;$52ba
_findappname = $52bd
;$52c0
;$52c3
;$52c6
_grbufcpycustom = $52c9
;$52cc
;$52cf
;$52d2
_vdisprealop1 = $52d5
_dispxequalsnum = $52d8
_resetgraphsettings = $52db
_initializevariables = $52de
;$52e1 ;bit 4,($9c75) (this is definitely returning the status of something when acting as a ti-smartview input pad...this bit is bit 1 of the data byte from a pc hid set report request)
_delvarsym = $52e4
_findappupnocase = $52e7
_findappdnnocase = $52ea
_deleteinvalidapps = $52ed
_deleteapp_link = $52f0
_cmpsymsnocase = $52f3
_setapprestrictions = $52f6
_removeapprestrictions = $52f9
_queryapprestrictions = $52fc
_dispapprestrictions = $52ff
_setuphome = $5302
_grputawayfull = $5305 ;same as _grputaway except it assumes no split screen
_sendsmartpadkeypress = $5308 ;b and a are the inputs
_toggleusbsmartpadinput = $530b ;a is input, 0 or 1 to enable/disable
_isusbdeviceconnected = $530e ;bit 4,($81) \ ret, this is just a guess on its purpose but it seems to work
_clearusbcallback2 = $5311 ;identical to $5257
_polarequtoop1 = $5314
_paramxequtoop1 = $5317
_paramyequtoop1 = $531a
_getrestrictionsoptions = $531d
_dispresetcomplete = $5320
_pttreset = $5323
_findappcustom = $5326
_cleargraphstyles = $5329

;page $1f rom calls
;--------------------------------
bootbtf = $8000
;$400f may point to version string ("1.02 ",0)
_md5final = $8018
_rsavalidate = $801b
_cmpstr = $801e ;bignumcompare
_writeabyte = $8021
_eraseflash = $8024
_findfirstcertfield = $8027
_zerotocertificate = $802a
_getcertificateend = $802d
_findgroupedfield = $8030
_ret_1 = $8033
_ret_2 = $8036
_ret_3 = $8039
_ret_4 = $803c
_ret_5 = $803f
_mult8by8 = $8042
_mult16by8 = $8045
_div16by8 = $8048
_div16by16 = $804b
;$804e ;scary certificate reading and writing, something about calc id and fields $0a10/$0a20
_loadaindpaged = $8051
_flashtoram2 = $8054
_getcertificatestart = $8057
_getfieldsize = $805a
_findsubfield = $805d
_erasecertificatesector = $8060
_checkheaderkey = $8063
;$8066 ;just returns z if specified data in field $0310, subfield $0610 exists, de points to data of that field you want to find
;$8069 ;just returns number of $0810/$0710 fields that exist in certificate or something, in ix
_load_lfontv2 = $806c
_load_lfontv = $806f
_receiveos = $8072
_findosheadersubfield = $8075
_findnextcertfield = $8078
_getbyteorboot = $807b
_getserial = $807e ;getcalcserial
_receivecalcid = $8081 ;receives certificate replacement (including calculator id, fails if already exists) and writes it, requires flash unlocked
_eraseflashpage = $8084
_writeflashunsafe = $8087
_dispbootver = $808a
_md5init = $808d
_md5update = $8090
_markosinvalid = $8093
_findprogramlicense = $8096 ;copies $8010 field to appid and other insane stuff that makes zero sense
_markosvalid = $8099
_checkosvalidated = $809c
_setupapppubkey = $809f
_sigmodr = $80a2
_transformhash = $80a5
_isappfreeware = $80a8
_findappheadersubfield = $80ab
_writevalidationnumber = $80ae ;generates two-byte validation number from calc id and stores to certificate
_div32by16 = $80b1
_findgroup = $80b4 ;searches until field of de-like group is found (de=$0a00, it stops when it finds $0ax0)
_getbootver = $80b7
_gethardwareversion = $80ba
_xora = $80bd ;xor a
_bignumpowermod17 = $80c0
_prodnrpart1 = $80c3
_writeabytesafe = $80c6
_writeflash = $80c9
_setupdatestamppubkey = $80cc
_setflashlowerbound = $80cf
_lowbatteryboot = $80d2
;ti-84 plus/silver edition only entry points
_attemptusbosreceive = $80e4 ;z to wait for usb cable insert & get os, nz and a= contents of port $4d or $56, on to cancel & clear ram
_displaybootmessage = $80e7
_newline2 = $80ea
_displaybooterror10 = $80ed
_chk_batt_low_b = $80f0
_chk_batt_low_b2 = $80f3
_receiveos_usb = $80f6
_displayosprogress = $80f9
_resetcalc = $80fc
_setupospubkey = $80ff
_checkheaderkeyhl = $8102 ;same as _checkheaderkey, only you pass the address of header in hl, not at appdata
_usberrorcleanup = $8105 ;kills some usb stuff (doesn't completely kill periph communication), error handler in boot code
_initusb = $8108 ;initializes usb hardware as peripheral, sets 5,(iy+$1b), c set if problems
;$810b set 1,($81) and wait (has something to do with usb peripheral kill, but it doesn't actually kill it)
_killusb = $810e ;identical to $8105, except in the middle of the outputs, it sends zero to port $4c
_displaybooterror1 = $8111
_displaybooterror2 = $8114
_displaybooterror3 = $8117
_displaybooterror4 = $811a
_displaybooterror5 = $811d
_displaybooterror6 = $8120
_displaybooterror7 = $8123
_displaybooterror8 = $8126
_displaybooterror9 = $8129

;ram equates
;--------------------------------
ramstart = $8000
appdata = $8000
ramcode = $8100
smalleditcolumnleft = $8177
smalleditrow = $8178
smalleditcolumnright = $8179
;pencol left edge? = $817b
biginteger1 = $8182
smalleditcancelparse = $8194
smalleditrowcount = $81b7
biginteger2 = $81c3
smalleditpromptstring = $81cc
ramcodeend = $822f
baseappbrtab = $8230 ;table of base pages for apps on page < 20 (starts with eight zeroes because they're os pages)
clockflag = $8230 ;bit 2 set for 24-hour mode and don't display "am/pm"
clockids = $8231 ;five bytes, numbers 0-4 in memory, that when present, stops displaying clock numbers in time setting context?
boottemp = $8251
md5temp = $8259
md5length = $8269
md5ash = $8292
appsearchpage = $82a3
tempswaparea = $82a5
;something = $837 ;18 bytes, probably indicates something about flash app pages, start out as $ff
appid = $838d
arcpageend = $8392
arcptrend = $8393
;$839f something...field size bytes?
md5buffer = $83a5
abackup = $83eb
ramreturndata = $83ed
arcinfo = $83ee
savedarcinfo = $8406
appinfo = $8432
appbank_jump = $843c
apppage = $843e
kbdscancode = $843f
kbdkey = $8444
kbdgetky = $8445
keyextend = $8446
extecho = keyextend
contrast = $8447
apdsubtimer = $8448
apdtimer = $8449
curtime = $844a
currow = $844b
curcol = $844c
curoffset = $844d
curunder = $844e
cury = $844f
curtype = $8450
curxrow = $8451
prevddata = $8452
lfont_record = $845a
sfont_record = $8462
tokvarptr = $846a
toklen = $846c
indicmem = $846e ;eight bytes used by _savetr and _restoretr to store image in top right corner
indiccounter = $8476
indicbusy = $8477
op1 = $8478
op1m = $847a
op2 = $8483
op2m = $8485
op2ext = $848c
op3 = $848e
op3m = $8490
op4 = $8499
op4m = $849b
op5 = $84a4
op5m = $84a6
op6 = $84af
op6m = $84b1
op6ext = $84b8
progtoedit = $84bf
namebuff = $84c7
equ_edit_save = $84d2
imathptr1 = $84d3
imathptr2 = $84d5
imathptr3 = $84d7
imathptr4 = $84d9
imathptr5 = $84db
chkdelptr1 = $84dd
chkdelptr2 = $84df
insdelptr = $84e1
updownptr = $84e3
foutdat = $84e5
asm_data_ptr1 = $84eb
asm_data_ptr2 = $84ed
asm_sym_ptr1 = $84ef
asm_sym_ptr2 = $84f1
asm_ram = $84f3
asm_ind_call = $8507
textshadow = $8508
textshadcur = $8588
textshadtop = $858a
textshadalph = $858b
textshadins = $858c
cxmain = $858d
cxpputaway = $858f
cxputaway = $8591
cxerrorep = $8595
cxsizewind = $8597
cxpage = $8599
cxcurapp = $859a
cxprev = $859b ;12 bytes are shadows of cxmain through cxcurapp and appflags
monqh = $85aa
monqt = $85ab
monqueue = $85ac
onsp = $85bc
promptrow = $85c0
promptcol = $85c1
promptins = $85c2
promptshift = $85c3
promptret = $85c4
promptvalid = $85c6
prompttop = $85c8
promptcursor = $85ca
prompttail = $85cc
promptbtm = $85ce
vartype = $85d0
varcurrent = $85d1
varclass = $85d9
catalogcurrent = $85da ;word at this location starting with $6007 corresponds to what is highlighted in catalog
menuactive = $85dc
menuappdepth = $85dd
menucurrent = $85de
;$85df ;holds current submenu index
;$85e0 ;holds currently selected item in current submenu
;$85e1 ;holds number of submenus for this menu
;$85e2 ;holds number of items in this submenu
;$85e3 ;iy+appflags backup for menu stuff
;$85e4 ;iy+$0c backup for menu stuff
;$85e5 ;curgstyle backup for menu stuff
;$85e6 ;iy+graphflags backup for menu stuff
progcurrent = $85e8
;something, op1 backup? = $85f2 ;type and name of topmost variable on menu with names
;something = $85fd
usermenusa = $85fe
ioprompt = $865f
dimagewidth = $8660
ioflag = $8670
sndrecstate = $8672
ioerrstate = $8673
header = $8674
iodata = $867d
ionewdata = $8689
bakheader = $868b
;something = $8697 ;app bitmap for selecting stuff from menus
;something = $86b7 ;used in $47 and $74 link packets
pencol = $86d7
penrow = $86d8
rclqueue = $86d9
rclqueueend = $86db
errno = $86dd
errsp = $86de
erroffset = $86e0
savesscreen = $86ec
asm_prgm_size = $89ec
bstcounter = $89ee
flags = $89f0
appflagsaddr = $89fd
;something = $8a36 ;stats-related? this gets stored to (varcurrent) for some reason
statvars = $8a3a
anovaf_vars = $8c17
infvars = $8c4d
infvar1 = $8c56
infvar2 = $8c5f
infvar3 = $8c68
infvar4 = $8c71
infvar5 = $8c7a
infvar6 = $8c83
infvar7 = $8c8c
infvar8 = $8c95
infvar9 = $8c9e
infvar10 = $8ca7
infvar11 = $8cb0
infvar12 = $8cb9
infvar13 = $8cc2
infvar14 = $8ccb
infvar15 = $8cd4
infvar16 = $8cdd
infvar17 = $8ce6
infvar18 = $8cef
infvar19 = $8cf8
infvar20 = $8d01
;something = $8d0b
;list-related stat vars = $8d0d
curgstyle = $8d17
curgy = $8d18
curgx = $8d19
curgy2 = $8d1a
curgx2 = $8d1b ;currently selected equation while graphing
freesavey = $8d1c
freesavex = $8d1d
;100 bytes = $8d2a
xoffset = $8da1
yoffset = $8da2
lcdtallp = $8da3
pixwidep = $8da4
pixwide_m_1 = $8da5
pixwide_m_2 = $8da6
lastentryptr = $8da7 ;pointer to the next available byte in the entry stack
lastentrystk = $8da9 ;the start of entry stack (note last entry is not in the stack, it is in the program '#'.)  this is a stack of strings.  first 2 bytes are length, followed by string. 2nd from last entry is first in this stack.
numlastentries = $8e29 ;number of entries you can back-track through minus one
currlastentry = $8e2a ;counter used by os to keep track of which entry was just displayed by pressing 2nd+enter
;something = $8e65
;something = $8e66
curinc = $8e67
uxmin = $8e7e
uxmax = $8e87
uxscl = $8e90
uymin = $8e99
uymax = $8ea2
uyscl = $8eab
uthetmin = $8eb4
uthetmax = $8ebd
uthetstep = $8ec6
utmin = $8ecf
utmax = $8ed8
utstep = $8ee1
uplotstart = $8eea
unmax = $8ef3
uu0 = $8efc
uv0 = $8f05
unmin = $8f0e
uu02 = $8f17
uv02 = $8f20
uw0 = $8f29
uplotstep = $8f32
uxres = $8f3b
uw02 = $8f44
xmin = $8f50
xmax = $8f59
xscl = $8f62
ymin = $8f6b
ymax = $8f74
yscl = $8f7d
thetamin = $8f86
thetamax = $8f8f
thetastep = $8f98
tminpar = $8fa1
tmaxpar = $8faa
tstep = $8fb3
plotstart = $8fbc
nmax = $8fc5
u0 = $8fce
v0 = $8fd7
nmin = $8fe0
u02 = $8fe9
v02 = $8ff2
w0 = $8ffb
plotstep = $9004
xreso = $900d
w02 = $9016
un1 = $901f
un2 = $9028
vn1 = $9031
vn2 = $903a
wn1 = $9043
wn2 = $904c
fin_n = $9055
fin_i = $905e
fin_pv = $9067
fin_pmt = $9070
fin_fv = $9079
fin_py = $9082
fin_cy = $908b
cal_n = $9094
cal_i = $909d
cal_pv = $90a6
cal_pmt = $90af
cal_fv = $90b8
cal_py = $90c1
smalleditram = $90d3
xfact = $913f
yfact = $9148
xres_int = $9151
deltax = $9152
deltay = $915b
shortx = $9164
shorty = $916d
lower = $9176
upper = $917f
xoutsym = $918c
xoutdat = $918e
youtsym = $9190
youtdat = $9192
inputsym = $9194
inputdat = $9196
prevdata = $9198
;something = $91d9
;something = $91da
curtablerow = $91dc
curtablecol = $91dd
tblmin = $92b3
tblstep = $92bc
;something = $92c5
;something = $92c6
;someplotthing1 = $92d9
;someplotthing2 = $92ea
;someplotthing3 = $92fb
es = $9302 ;bottom of the es
est = $9305 ;current height of the es
;something = $9311 ;this is the pointer to a table of stuff for a basic menu
plotsscreen = $9340
seed1 = $9640
seed2 = $9649
basic_prog = $9652
basic_start = $965b
nextparsebyte = $965d ;basic_pc
basic_end = $965f
numarguments = $9661
;something = $9665 ;parser-related word
;something = $966c
;something = $966d
cmdshadow = $966e
cmdshadcur = $96ee
cmdshadalph = $96f0
cmdshadins = $96f1
cmdcursor = $96f2
edittop = $96f4
editcursor = $96f6
edittail = $96f8
editbtm = $96fa
;something = $9700
editsym = $9706 ;pointer to symbol table entry of variable being edited
editdat = $9708 ;pointer to data of variable being edited
;something = $970e ;stats/list editor related, usually 1
;something = $970f ;stats/list editor related, usually 0
;something = $9710 ;stats/list editor related, usually 0
listname1 = $9711
listname2 = $9716
listname3 = $971b
listname4 = $9720
listname5 = $9725
listname6 = $972a
listname7 = $972f
listname8 = $9734
listname9 = $9739
listname10 = $973e
listname11 = $9743
listname12 = $9748
listname13 = $974d
listname14 = $9752
listname15 = $9757
listname16 = $975c
listname17 = $9761
listname18 = $9766
listname19 = $976b
listname20 = $9770
;something = $9775
y1linetype = $9776 ;these bytes define the line type for functions which are graphed
y2linetype = $9777
y3linetype = $9778
y4linetype = $9779
y5linetype = $977a
y6linetype = $977b
y7linetype = $977c
y8linetype = $977d
y9linetype = $977e
y0linetype = $977f
para1linetype = $9780
para2linetype = $9781
para3linetype = $9782
para4linetype = $9783
para5linetype = $9784
para6linetype = $9785
polar1linetype = $9786
polar2linetype = $9787
polar3linetype = $9788
polar4linetype = $9789
polar5linetype = $978a
polar6linetype = $978b
seculinetype = $978c
secvlinetype = $978d
secwlinetype = $978e
;something = $979f
;something = $97a1
wintop = $97a5
winbtm = $97a6
winleftedge = $97a7
winleft = $97a8
winabove = $97aa
winrow = $97ac
wincol = $97ae
fmtdigits = $97b0
fmtstring = $97b1
fmtconv = $97f2
fmtleft = $9804
fmtindex = $9806
fmtmatsym = $9808
fmtmatmem = $980a
eqs = $980c
;something = $980e
;something = $9810
freeram = $9815 ;pretty sure this is the amount of ram free, valid in mem mgmt/del anyway
;something = $9817
tsymptr1 = $9818
tsymptr2 = $981a
chkdelptr3 = $981c
chkdelptr4 = $981e
tempmem = $9820
fpbase = $9822
fps = $9824
opbase = $9826
ops = $9828
ptempcnt = $982a
cleantmp = $982c
ptemp = $982e ;end of symbol table
progptr = $9830
newdataptr = $9832
pagedcount = $9834
pagedpn = $9835
pagedgetptr = $9836
pagedputptr = $9838
pagedbuf = $983a
;something = $984a ;this is the top lcd row for a menu (usually 1)
apperr1 = $984d
apperr2 = $985a
flashbyte1 = $9867
flashbyte2 = $9868
freearcblock = $9869
arcpage = $986b
arcptr = $986c
apprawkeyhandle = $9870
appbackupscreen = $9872
customheight = $9b72
locallanguage = $9b73
hookexectemp = $9b75
linkactivityhook = $9b78
cursorhookptr = $9b7c
libraryhookptr = $9b80
rawkeyhookptr = $9b84
getkeyhookptr = $9b88
homescreenhookptr = $9b8c
windowhookptr = $9b90
graphhookptr = $9b94
yequalshookptr = $9b98
fonthookptr = $9b9c
regraphhookptr = $9ba0
graphicshook = $9ba4
tracehookptr = $9ba8
parserhookptr = $9bac
appchangehookptr = $9bb0
catalog1ookptr = $9bb4
helphookptr = $9bb8
cxredisphookptr = $9bbc
menuhookptr = $9bc0
catalog2ookptr = $9bc4
tokenhookptr = $9bc8
localizehookptr = $9bcc
silentlinkhookptr = $9bd0 ;restartclr?
usbactivityhookptr = $9bd4
baseappbrtab2 = $9c06 ;table of base pages for apps on page >= 20; first 20 bytes are zeroes.
usbcallbackpage = $9c13
usbcallbackptr = $9c14
vendorid = $9c16
productid = $9c18
devreleasenumber = $9c1a
oldsespeed = $9c21
calcperipheralstate = $9c26
usb_datawaitingcount = $9c27
basepagetable2end = $9c6f ;this is the last page
port91temp = $9c79
usb_dataexpectcount = $9c80
offpagecallpage = $9c83 ;temporarily stores off-page page and address
offpagecalladdress = $9c84
;something = $9c86 ;used with se link activity, values of $00, $0fa, $0ff probably mean something
;something = $9c87 ;zero this to force the apps menu to recache itself (this is always either 0, 1, or last app page, for some reason)
;something = $9c88 ;don't know, but it's 14 bytes and has to do with selecting stuff (if $9c87 is non-zero, this is zeroed out)
;something = $9c9e ;funky, this actually gets written to the certificate on non-83+ (11 bytes)
sespeed = $9cae
;something, table index = $9caf
;something = $9cb0
;something = $9cb1 ;table
;something = $9ccd
localtokstr = $9d65
keyforstr = $9d76
keytostrram = $9d77
sedmonsp = $9d88
bpsave = $9d8a
usermem = $9d95
symtable = $0fe66

;system flags
;----------------------------------------------------------------------
iodelflag = 0
indelete = 0	;1 = delete screen

trigflags = 0	;trigonometry mode settings
trigdeg = 2	;1=degrees, 0=radians

kbdflags = 0	;keyboard scan
kbdscr = 3	;1=scan code ready
kbdkeypress = 4	;1=key has been pressed

doneflags = 0	;display "done"
doneprgm = 5	;1=display "done" after prgm
;----------------------------------------------------------------------
editflags = 1
editopen = 2	;1=edit buffer is open

ansflags = 1
ansscroll = 3	;1=answer can scroll, seems must be reset in order to move about edit buffer

monflags = 1	;monitor flags
monabandon = 4	;1=don't start any long process in put away (#715)
;----------------------------------------------------------------------
plotflags = 2	;plot generation flags
plotloc  = 1	;0=bkup & display, 1=display only
plotdisp = 2	;1=plot is in display, 0=text in display

grfmodeflags = 2	;graph mode settings
grffuncm = 4	;1=function grap
grfpolarm = 5	;1=polar grap
grfparamm = 6	;1=parametric grap
grfrecurm = 7	;1=recursion grap
;----------------------------------------------------------------------
graphflags = 3
graphdraw = 0	;0=graph is valid, 1=redraw graph(dirty)
graphcursor = 2
;----------------------------------------------------------------------
grfdbflags = 4
grfdot = 0	;0=line, 1=dot
grfsimul = 1	;0=sequential, 1=simultaneous
grfgrid  = 2	;0=no grid, 1=grid
grfpolar = 3	;0=rectangular, 1=polar coordinates
grfnocoord = 4	;0=display coordinates, 1=off
grfnoaxis = 5	;0=axis, 1=no axis
grflabel = 6	;0=off, 1=axis label
;----------------------------------------------------------------------
textflags = 5	;text output flags
texterasebelow = 1	;1=erase line below small char
textscrolled = 2	;1=screen scrolled
textinverse = 3	;1=display inverse bit-map
textinsmode = 4	;0=overstrike, 1=insert mode
;----------------------------------------------------------------------
parsflag = 6	;parser flags
;----------------------------------------------------------------------
parsflag2 = 7	;parser flags
numop1 = 0	;1=result in op1, 0=no result
;----------------------------------------------------------------------
newdispf = 8	;derivative mode flags
preclrformode = 0	;1=help blink on mode screen
allowprogtokens = 1	;1=allow programming tokens to be parsed in basic programs

apdflags = 8	;automatic power-down
apdable  = 2	;1=apd enabled
apdrunning = 3	;1=apd clock running
;----------------------------------------------------------------------
web_err_mask = $60
;----------------------------------------------------------------------
onflags  = 9	;on key flags
parseinput = 1	;1=parse input when done
onrunning = 3	;1=calculator is running
oninterrupt = 4	;1=on key interrupt request

statflags = 9	;statistics flags
;unknown = 5	;unknown
statsvalid = 6	;1=stats are valid
;----------------------------------------------------------------------
fmtflags = $0a	;numeric format flags
fmtexponent = 0	;1=show exponent, 0=no exponent
fmteng = 1		;1=engineering notion, 0=scientific
fmthex = 2		;1=hexadecimal
fmtoct = 3		;1=octal
fmtbin = 4		;1=binary

nummode = $0a
fmtreal = 5
fmtrect = 6
fmtpolar = 7

realmode = 5
rectmode = 6
polarmode = 7
; =  = 	;if hex and oct both = 1
; =  = 	; then bin=0 means >frac
; =  = 	; bin=1 means >dms
fmtbasemask =  %00011100	; mask to base flags
fmtbaseshift =  2	; offset to base flags
;
;       check if these are used by numform,
;
;            =  6
;            =  7
;----------------------------------------------------------------------
fmtoverride = $0b	;copy of fmtflags with conversion override
;----------------------------------------------------------------------
fmteditflags = $0c	;numeric editing flags
fmtedit = 0	;1=format number for editing

curflags = $0c	;cursor
curable  = 2	;1=cursor flash is enabled
curon = 3	;1=cursor is showing
curlock  = 4	;1=cursor is locked off

cmdflags = $0c	;command editor flags
cmdvirgin = 5	;1=nothing has been typed in cmd bfr
;----------------------------------------------------------------------
appflags = $0d	;application flags
appwantintrpt = 0	;1=want on key interrupts
apptextsave = 1	;1=save characters in textshadow
appautoscroll = 2	;1=auto-scroll text on last line
appmenus = 3	;1=process keys that bring up menus, 0=check lock menu flag
applockmenus = 4	;1=ignore menu keys, 0=switch to home screen and bring up menu
appcurgraphic = 5	;1=graphic cursor
appcurword = 6	;1=text cursor covers entire word
appexit  = 7	;1=application handles [exit] key itself

appwantintrptf = 1<<appwantintrpt
apptextsavef = 1<<apptextsave
appautoscrollf = 1<<appautoscroll
appmenusf = 1<<appmenus
applockmenusf = 1<<applockmenus
appcurgraphicf = 1<<appcurgraphic
appcurwordf = 1<<appcurword
appexitf = 1<<appexit
;----------------------------------------------------------------------
rclflag = $0e	;os recall queue flags
enablequeue = 7	;1 = enable recall queue
;----------------------------------------------------------------------
seqflags = $0f	;sequential graph flags
webmode = 0	;0 = normal seq mode, 1 = web mode
webvert = 1
sequv = 2	;u vs v
seqvw = 3	;v vs w
sequw = 4	;u vs w
;----------------------------------------------------------------------
promptflags = $11	;prompt line flags
promptedit = 0	;1=editing in prompt buffer
;----------------------------------------------------------------------
indicflags = $12	;indicator flags
indicrun = 0	;1=run indicator on
indicinuse = 1	;indicator save area in use=1, free=0 ;resetting will disable 2nd while in _getkey
indiconly = 2	;interrupt handler only checks run indicator

shiftflags = $12	;[2nd] and [alpha] flags
shift2nd = 3	;1=[2nd] has been pressed
shiftalpha = 4	;1=[alpha] has been pressed
shiftlwralph = 5	;1=lower case, 0=upper case
shiftalock = 6	;1=alpha lock has been pressed
shiftkeepalph = 7	;1=cannot cancel alpha shift
;----------------------------------------------------------------------
tblflags = $13	;table flags.
autofill = 4	;1=prompt, 0=fillauto
autocalc = 5	;1=prompt, 0=calcauto
retable = 6	;0=table is okay, 1=must recompute table.
;----------------------------------------------------------------------
sgrflags = $14
grfsplit = 0	;1=split graph, 0=normal
vertsplit = 1	;1=vertical (left-right) split
grfschanged = 2	;1=graph just changed split <-> normal
grfsplitoverride = 3	;1 = ignore graph split flag if set
write_on_graph = 4	;1 = text or = writing to graph screen
g_style_active = 5	;1 = graph styles are enabled, use them
cmp_mod_box = 6	;1 = doing mod box plot computation
textwrite = 7
;----------------------------------------------------------------------
newindicflags = $15
extraindic = 0
saindic = 1
;----------------------------------------------------------------------
batteryflags = $16
batteriesgood = 2	;1 = batteries good
;----------------------------------------------------------------------
smartflags = $17
smarter_mask = 3
smarter_test = 1
smartgraph = 0
smartgraph_inv = 1
;----------------------------------------------------------------------
traceflags = $18
grfexpr = 0	;set to hide expression while tracing
;----------------------------------------------------------------------
statflags2 = $1a
statdiagnosticson = 0	;1 = stat diagnostics on
;----------------------------------------------------------------------
linkflags = $1b
idis95 = 1	;link routines use machine id 95 (cbl)
idis82 = 2	;link routines use machine id 82 (ti-82)
idis83 = 3	;link routines use machine id 83 (ti-83)
idis03 = 4	;link routines use machine id 03 (pc to ti-83)
usbenabled = 5	;use usb port first, or at least try to
;----------------------------------------------------------------------
;there is a flag $1c (stats-related).
;----------------------------------------------------------------------
;there is a flag $1e.
;----------------------------------------------------------------------
vartypemask = $1f	;is this a flag byte? yes
vargraphref = 6
;----------------------------------------------------------------------
graphflags2 = $1f
splitoverride = 3	;0 = force full screen with parseinp, or something
;----------------------------------------------------------------------
asm_flag1 = $21	;asm coding
asm_flag2 = $22	;asm coding
asm_flag3 = $23	;asm coding
;----------------------------------------------------------------------
arcflag = $24
checkbatterylevelfirst = 0	;1 = check battery levels in arc_unarc first and throw error if low

getsendflg = $24
comfailed = 1	;1 = get/send communication failed

selftestflag = $24
resetonpoweron = 2	;1 = force ram reset when apd disabled on next power on

applwrcaseflag = $24
lwrcaseactive = 3
;----------------------------------------------------------------------
contextflags = $25
nocxputaway = 5	;1 = do not call cxputaway routine
;----------------------------------------------------------------------
groupflags = $26 ;used temporarily in arc_unarc
ingroup = 1	;1 = in group context
nocompletionbyte = 2	;1 = do not write 0fch when calling arc_unarc, leave as 0fe
nodatawrite = 3	;1 = do not write data when calling arc_unarc, nor size bytes
writesizebytesonly = 5	;1 = only write size bytes when calling arc_unarc
;----------------------------------------------------------------------
apiflg = $28
appallowcontext = 0           ;app wants context changes to happen
;1 set to ignore a key after returning from rawkeyhook
;2 set to send this key back?
;3
apprunning = 4	;app is currently running
;5
;6
appretkeyoff = 7	;1 = getkey returns koff when [2nd]+[on] pressed
;----------------------------------------------------------------------
apiflg2 = $29
;----------------------------------------------------------------------
apiflg3 = $2a
;1 set means using small font?
;----------------------------------------------------------------------
apiflg4 = $2b
celloverride = 1	;use cell override
fullscrndraw = 2	;draw into last row/col of screen
;----------------------------------------------------------------------
mouseflag1 = $2c
;----------------------------------------------------------------------
mouseflag2 = $2d ;might want to keep this always reset.
;----------------------------------------------------------------------
xapflag0 = $2e	;external app flags
xapflag1 = $2f
xapflag2 = $30
xapflag3 = $31
;----------------------------------------------------------------------
fontflags = $32
fracdrawlfont = 2
fractalllfont = 3
customfont = 7
;----------------------------------------------------------------------
hookflags1 = $33 ;also scriptflag, rclflag2, backgroundlink
alt_on = 0	;run onscrpt at startup
alt_off = 1	;run offscrpt at shutdown
userclqueueend = 2	;1 = external mode
ignorebplink = 3	;1 = override flag for link activity hook
bplinkon = 4	;1 = link activity hook active
notempdelete = 6	;1 = do not delete temporary programs at homescreen
;----------------------------------------------------------------------
hookflags2 = $34 ;also syshookflg
getcschookactive = 0	;1 = getcsc hook active
libraryhookactive = 1	;1 = library hook active
homescreenhookactive = 4	;1 = homescreen hook active
rawkeyhookactive = 5	;1 = raw key hook active
catalog2ookactive = 6	;1 = catalog 2 hook active
cursorhookactive = 7	;1 = cursor hook active
;----------------------------------------------------------------------
hookflags3 = $35 ;also syshookflg1
tokenhookactive = 0	;1 = token hook active
localizehookactive = 1	;1 = localize hook active
windowhookactive = 2	;1 = window hook active
graphhookactive = 3	;1 = graph hook active
yequhookactive = 4	;1 = y= hook active
fonthookactive = 5	;1 = font hook active
regraphhookactive = 6	;1 = regraph hook active
drawinghookactive = 7	;1 = drawing hook active
;----------------------------------------------------------------------
hookflags4 = $36 ;also syshookflag2
tracehookactive = 0	;1 = trace hook active
parserhookactive = 1	;1 = parser hook active
appchangehookactive = 2	;1 = app change hook active
catalog1ookactive = 3	;1 = catalog 1 hook active
helphookactive = 4	;1 = help hook active
cxredisphookactive = 5	;1 = cxredisp hook active
menuhookactive = 6	;1 = menu hook active
silentlinkhookactive = 7	;1 = silent link hook active
;----------------------------------------------------------------------
;hookflags2override = $37	;set corresponding bit to kill iy+$35 hook when executing app
;----------------------------------------------------------------------
;hookflags3override = $38	;set corresponding bit to kill iy+$36 hook when executing app
;----------------------------------------------------------------------
;hookflags4override = $39	;set corresponding bit to kill iy+$37 hook when executing app
;----------------------------------------------------------------------
plotflag3 = $3c
bufferonly = 0
usefastcirc = 4
;----------------------------------------------------------------------
dbkeyflags = $3d
keydefaultsf = 6	;1 = getkey returns extended keycodes with ti-keyboard
;----------------------------------------------------------------------
clockflags = $3f
notmdymode = 0	;0 = m/d/y format
isymdmode = 1	;1 = y/m/d format
is24our = 2	;1 = clock in 24 hour mode
clockon = 6	;1 = clock on
;----------------------------------------------------------------------
usbflag1 = $40
usbreceivezone1 = 2	;1 = receive to ram pages 3/2 ("zone 1")
;----------------------------------------------------------------------
usbflag2 = $41
;0
;2
nousbhostinit = 3	;1 = _initspecificusbdevice must fail
usbdatawaiting = 5
;6
;7
;----------------------------------------------------------------------
;there is a flag $43.
;----------------------------------------------------------------------

;character font equates
;-------------------------------
lrecurn = $01
lrecuru = $02
lrecurv = $03
lrecurw = $04
lconvert = $05
lsqup = $06
lsqdown = $07
lintegral = $08
lcross = $09
lboxicon  = $0a
lcrossicon  = $0b
ldoticon  = $0c
lsubt    = $0d ;small capital t for parametric mode.
lcuber   = $0e ;slightly different 3 for cubed root.
lhexf = $0f
lroot = $10
linverse = $11
lsquare = $12
langle = $13
ldegree = $14
lradian = $15
ltranspose = $16
lle = $17
lne = $18
lge = $19
lneg = $1a
lexponent = $1b
lstore = $1c
lten = $1d
luparrow = $1e
ldownarrow = $1f
lspace = $20
lexclam = $21
lquote = $22
lpound = $23
lfourth = $24
lpercent = $25
lampersand = $26
lapostrophe = $27
llparen = $28
lrparen = $29
lasterisk = $2a
lplussign = $2b
lcomma = $2c
ldash = $2d
lperiod = $2e
lslash = $2f
l0 = $30
l1 = $31
l2 = $32
l3 = $33
l4 = $34
l5 = $35
l6 = $36
l7 = $37
l8 = $38
l9 = $39
lcolon = $3a
lsemicolon = $3b
llt = $3c
leq = $3d
lgt = $3e
lquestion = $3f
latsign = $40
lcapa = $41
lcapb = $42
lcapc = $43
lcapd = $44
lcape = $45
lcapf = $46
lcapg = $47
lcaph = $48
lcapi = $49
lcapj = $4a
lcapk = $4b
lcapl = $4c
lcapm = $4d
lcapn = $4e
lcapo = $4f
lcapp = $50
lcapq = $51
lcapr = $52
lcaps = $53
lcapt = $54
lcapu = $55
lcapv = $56
lcapw = $57
lcapx = $58
lcapy = $59
lcapz = $5a
ltheta = $5b
lbackslash = $5c
lrbrack = $5d
lcaret = $5e
lunderscore = $5f
lbackquote = $60
la = $61
lb = $62
lc = $63
ld = $64
le = $65
lf = $66
lg = $67
lh = $68
li = $69
lj = $6a
lk = $6b
ll = $6c
lm = $6d
ln = $6e
lo = $6f
lp = $70
lq = $71
lr = $72
ls = $73
lt = $74
lu = $75
lv = $76
lw = $77
lx = $78
ly = $79
lz = $7a
llbrace = $7b
lbar = $7c
lrbrace = $7d
ltilde = $7e
linveq = $7f
lsub0 = $80
lsub1 = $81
lsub2 = $82
lsub3 = $83
lsub4 = $84
lsub5 = $85
lsub6 = $86
lsub7 = $87
lsub8 = $88
lsub9 = $89
lcapaacute = $8a
lcapagrave = $8b
lcapacaret = $8c
lcapadier = $8d
laacute = $8e
lagrave = $8f
lacaret = $90
ladier = $91
lcapeacute = $92
lcapegrave = $93
lcapecaret = $94
lcapedier = $95
leacute = $96
legrave = $97
lecaret = $98
ledier = $99
lcapiacute = $9a
lcapigrave = $9b
lcapicaret = $9c
lcapidier = $9d
liacute = $9e
ligrave = $9f
licaret = $a0
lidier = $a1
lcapoacute = $a2
lcapograve = $a3
lcapocaret = $a4
lcapodier = $a5
loacute = $a6
lograve = $a7
locaret = $a8
lodier = $a9
lcapuacute = $aa
lcapugrave = $ab
lcapucaret = $ac
lcapudier = $ad
luacute = $ae
lugrave = $af
lucaret = $b0
ludier = $b1
lcapcced = $b2
lcced = $b3
lcapntilde = $b4
lntilde = $b5
laccent = $b6
lgrave = $b7
ldieresis = $b8
lquesdown = $b9
lexclamdown = $ba
lalpha = $bb
lbeta = $bc
lgamma = $bd
lcapdelta = $be
ldelta = $bf
lepsilon = $c0
llbrack  = $c1
llambda = $c2
lmu = $c3
lpi = $c4
lrho = $c5
lcapsigma = $c6
lsigma = $c7
ltau = $c8
lphi = $c9
lcapomega = $ca
lxmean = $cb
lymean = $cc
lsupx = $cd
lellipsis = $ce
lleft = $cf
lblock = $d0
lper = $d1
lhyphen = $d2
larea = $d3
ltemp = $d4
lcube = $d5
lenter = $d6
limagi = $d7
lphat = $d8
lchi = $d9
lstatf = $da
llne = $db
llistl = $dc
lfinann  = $dd
l2_r_paren  = $de
lblockarrow  = $df
lcuro    = $e0
lcuro2   = $e1
lcurocapa    = $e2
lcuroa   = $e3
lcuri    = $e4
lcuri2   = $e5
lcuricapa    = $e6
lcuria   = $e7
lgline       = $e8 ; = 0
lgthick      = $e9 ; = 1
lgabove = $ea ; = 2
lgbelow = $eb ; = 3
lgpath = $ec ; = 4
lganimate = $ed ; = 5
lgdot = $ee ; = 6
lupblk = $ef ;up arrow and block in solver
ldnblk = $f0 ;down arrow and block in solver
lcurfull = $f1 ;note: must be last char (putmap checks)

;(menucurrent) values
;--------------------------
mconfirmation = $01
mapps = $02
mprogramhome = $03
mprgm_run = $00
mprgm_edit = $01
mprgm_new = $02
mzoom = $04
mzoom_zoom = $00
mzoom_memory = $01
mdraw = $05
mdraw_draw = $00
mdraw_points = $01
mdraw_store = $02
mstatplots = $06
mstat = $07
mstat_edit = $00
mstat_calc = $01
mstat_tests = $02
mmath = $08
mmath_math = $00
mmath_number = $01
mmath_complex = $02
mmath_prob = $03
mtest = $09
mtest_test = $00
mtest_logic = $01
mvars = $0a
mvars_vars = $00
mvars_yvars = $01
mmemory = $0c
mmatrix = $0d
mmatrix_name = $00
mmatrix_math = $01
mmatrix_edit = $02
mdistr = $0e
mdistr_distr = $00
mdistr_draw = $01
mangle = $0f
mlist = $10
mlist_names = $00
mlist_ops = $01
mlist_math = $02
mcalculate = $11
mvarswin = $14
mvarswin_xy = $00
mvarswin_tth = $01
mvarswin_uvw = $02
mvarszoom = $15
mvarszoom_zxy = $00
mvarszoom_zt = $01
mvarszoom_uvw = $02
mvarsgdb = $16
mvarspics = $17
mvarsstrings = $18
mvarsstat = $19
mvarsstat_xy = $00
mvarsstat_sigma = $01
mvarsstat_eq = $02
mvarsstat_test = $03
mvarsstat_pts = $04
mvarstable = $1a
mvarsyequ = $1b
mvarsparametric = $1c
mvarspolar = $1d
mvarsfnonoff = $1e
mmemreset = $1f
mmemreset_ram = $00
mmemreset_rom = $01
mmemreset_all = $02
mmemmgmtdel = $20
mmemresetdefaults = $21
mmemresetramall = $23
mmemresetromvars = $24
mmemresetromapps = $25
mmemresetromall = $26
mmemresetall = $27
mgroup = $28
mgroup_new = $00
mgroup_ungroup = $01
mgroupvars = $29
mprogramedit = $2a
mprgmed_ctrl = $00
mprgmed_io = $01
mprgmed_exec = $02
mprgmzoom = $2b
mprgmzoom_zoom = $00
mprgmzoom_mem = $01
mprgmdraw = $2c
mprgmdraw_draw = $00
mprgmdraw_pt = $01
mprgmdraw_store = $02
mprgmstatplot = $2d
mprgmsp_plots = $00
mprgmsp_type = $01
mprgmsp_mark = $02
mprgmstat = $2e
mprgmstat_edit = $00
mprgmstat_calc = $01
mprgmstat_tests = $02
mprgmmath = $2f
mprgmmath_math = $00
mprgmmath_num = $01
mprgmmath_cplx = $02
mprgmmath_prob = $03
mlink = $30
mlink_send = $00
mlink_recieve = $01
mlinktrasmit = $31
mlinkxmit_xmit = $01
mgarbagecollect = $3f
mselectgroupvars = $40
mselgrpvars_sel = $00
mselgrpvars_grp = $01
mduplicatename = $42
mcatalog = $45
mfinance = $22
mfinance_calc = $00
mfinance_vars = $01

;keypress equates
;-------------------------------
kright = $01
kleft = $02
kup = $03
kdown = $04
kenter = $05
kalphaenter = $06
kalphaup = $07
kalphadown = $08
kclear = $09
kdel = $0a
kins = $0b
krecall = $0c
klastent = $0d
kbol = $0e
keol = $0f

kselall = $10
kunselall = $11
kltoti82 = $12
kbackup = $13
krecieve = $14
klnkquit = $15
ktrans = $16
krename = $17
koverw = $18
komit = $19
kcont = $1a
ksendid = $1b
ksendsw = $1c
kyes = $1d
knoway = $1e
kvsendtype = $1f
koverwall = $20
kno = $25
kkreset = $26
kapp = $27
kdoug = $28
klistflag = $29
menustart = $2b
kareyousure = $2b
kappsmenu = $2c
kprgm = $2d
kzoom = $2e
kdraw = $2f
ksplot = $30
kstat = $31
kmath = $32
ktest = $33
kchar = $34
kvars = $35
kmem = $36
kmatrix = $37
kdist = $38
kangle = $39
klist = $3a
kcalc = $3b
kfin = $3c
menuend = kfin
kcatalog = $3e
kinputdone = $3f
koff = kinputdone
kquit = $40
appstart = kquit
klinkio = $41
kmatrixed = $42
kstated = $43
kgraph = $44
kmode = $45
kprgmed = $46 ;program edit
kprgmcr = $47 ;program create
kwindow = $48 ;range editor
kyequ = $49 ;equation editor
ktable = $4a ;table editor
ktblset = $4b ;table set
kchkram = $4c ;check ram (about screen)
kdelmem = $4d ;delete mem
kresetmem = $4e ;reset mem
kresetdef = $4f ;reset default
kprgminput = $50 ;program input
kzfacted = $51 ;zoom factor editor
kerror = $52 ;error
ksolvetvm = $53 ;tvm solver
ksolveroot = $54 ;solve editor
kstatp = $55 ;stat plot
kinfstat = $56 ;inferential statistic
kformat = $57 ;format
kextapps = $58 ;external applications.     new
knewapps = $59 ;new apps for cerberus.
append = knewapps
echostart1 = $5a
ktrace = $5a
kzfit = $5b
kzin = $5c
kzout = $5d
kzprev = $5e
kbox = $5f
kdecml = $60
ksetzm = $61
ksquar = $62
kstd = $63
ktrig = $64
kusrzm = $65
kzsto = $66
kzint = $67
kzstat = $68
echostart2 = $69
kselect = $69
kcircl = $6a
kcldrw = $6b
kline = $6c
kpen = $6d
kptchg = $6e
kptoff = $6f
kpton = $70
kvert = $71
khoriz = $72
ktext = $73
ktanln = $74
keval = $75
kinters = $76
kdydx = $77
kfnintg = $78
krootg = $79
kdydt = $7a
kdxdt = $7b
kdrdo = $7c
kgfmin = $7d
kgfmax = $7e
echostart = $7f
klistname = $7f
kadd = $80
ksub = $81
kmul = $82
kdiv = $83
kexpon = $84
klparen = $85
krparen = $86
klbrack = $87
krbrack = $88
kshade = $89
kstore = $8a
kcomma = $8b
kchs = $8c
kdecpnt = $8d
k0 = $8e
k1 = $8f
k2 = $90
k3 = $91
k4 = $92
k5 = $93
k6 = $94
k7 = $95
k8 = $96
k9 = $97
kee = $98
kspace = $99
kcapa = $9a
kcapb = $9b
kcapc = $9c
kcapd = $9d
kcape = $9e
kcapf = $9f
kcapg = $a0
kcaph = $a1
kcapi = $a2
kcapj = $a3
kcapk = $a4
kcapl = $a5
kcapm = $a6
kcapn = $a7
kcapo = $a8
kcapp = $a9
kcapq = $aa
kcapr = $ab
kcaps = $ac
kcapt = $ad
kcapu = $ae
kcapv = $af
kcapw = $b0
kcapx = $b1
kcapy = $b2
kcapz = $b3
kvarx = $b4
kpi = $b5
kinv = $b6
ksin = $b7
kasin = $b8
kcos = $b9
kacos = $ba
ktan = $bb
katan = $bc
ksquare = $bd
ksqrt = $be
kln = $bf
kexp = $c0
klog = $c1
kalog = $c2
ktoabc = $c3
kclrtbl = $c4
kans = $c5
kcolon = $c6
knderiv = $c7
kfnint = $c8
kroot = $c9
kquest = $ca
kquote = $cb
ktheta = $cc
kif = $cd
kthen = $ce
kelse = $cf
kfor = $d0
kwhile = $d1
krepeat = $d2
kend = $d3
kpause = $d4
klbl = $d5
kgoto = $d6
kisg = $d7
kdsl = $d8
kmenu = $d9
kexec = $da
kreturn = $db
kstop = $dc
kinput = $dd
kprompt = $de
kdisp = $df
kdispg = $e0
kdispt = $e1
koutput = $e2
kgetkey = $e3
kclrhome = $e4
kprtscr = $e5
ksinh = $e6
kcosh = $e7
ktanh = $e8
kasinh = $e9
kacosh = $ea
katanh = $eb
klbrace = $ec
krbrace = $ed
ki = $ee
kconstea = $ef
kplot3 = $f0
kfmin = $f1
kfmax = $f2
kl1a = $f3
kl2a = $f4
kl3a = $f5
kl4a = $f6
kl5a = $f7
kl6a = $f8
kuna = $f9
kvna = $fa
kwna = $fb

;this key means that it is a 2 byte keycode
;there are 2 of these keys; be careful with usage
;------------------------------------------------
kextendecho2 = $fc

;this key means that the key press is one that echos
;into a buffer, and it is a 2 byte key code, go look at
;(extecho) for the key value
;------------------------------------------------------
kextendecho = $fe

ke1bt = $00
kdrawinv = ke1bt
kdrawf = ke1bt+1
kpixelon = ke1bt+2
kpixeloff = ke1bt+3
kpxltest = ke1bt+4
krcgdb = ke1bt+5
krcpic = ke1bt+6
kstgdb = ke1bt+7
kstpic = ke1bt+8
kabs = ke1bt+9
ktequ = ke1bt+10 ;==
ktnoteq = ke1bt+11 ;<>
ktgt = ke1bt+12 ;>
ktgte = ke1bt+13 ;>=
ktlt = ke1bt+14 ;<
ktlte = ke1bt+15 ;<=
kand = ke1bt+16
kor = ke1bt+17
kxor = ke1bt+18
knot = ke1bt+19
klr1 = ke1bt+20
kxroot = ke1bt+21
kcube = ke1bt+22
kcbrt = ke1bt+23 ;cube root
ktodec = ke1bt+24
kcubicr = ke1bt+25
kquartr = ke1bt+26
kplot1 = ke1bt+27
kplot2 = ke1bt+28
kround = ke1bt+29
kipart = ke1bt+30
kfpart = ke1bt+31
kint = ke1bt+32
krand = ke1bt+33
knpr = ke1bt+34
kncr = ke1bt+35
kxfactorial = ke1bt+36
krad = ke1bt+37
kdegr = ke1bt+38 ;degrees conv
kapost = ke1bt+39
ktodms = ke1bt+40
krtopo = ke1bt+41 ;r
krtopr = ke1bt+42
kptorx = ke1bt+43
kptory = ke1bt+44
krowswap = ke1bt+45
krowplus = ke1bt+46
ktimrow = ke1bt+47
ktrowp = ke1bt+48
ksorta = ke1bt+49
ksortd = ke1bt+50
kseq = ke1bt+51
kmin = ke1bt+52
kmax = ke1bt+53
kmean = ke1bt+54
kmedian = ke1bt+55
ksum = ke1bt+56
kprod = ke1bt+57
kdet = ke1bt+58
ktransp = ke1bt+59
kdim = ke1bt+60
kfill = ke1bt+61
kident = ke1bt+62
krandm = ke1bt+63
kaug = ke1bt+64
konevar = ke1bt+65
ktwovar = ke1bt+66
klr = ke1bt+67
klrexp = ke1bt+68
klrln = ke1bt+69
klrpwr = ke1bt+70
kmedmed = ke1bt+71
kquad = ke1bt+72
kclrlst = ke1bt+73
khist = ke1bt+74
kxyline = ke1bt+75
kscatter = ke1bt+76
kmrad = ke1bt+77
kmdeg = ke1bt+78
kmnormf = ke1bt+79
kmsci = ke1bt+80
kmeng = ke1bt+81
kmfloat = ke1bt+82
kfix = ke1bt+83
kspliton = ke1bt+84
kfullscreen = ke1bt+85
kstndrd = ke1bt+86
kparam = ke1bt+87
kpolar = ke1bt+88
kseqg = ke1bt+89
kafillon = ke1bt+90
kafilloff = ke1bt+91
kacalcon = ke1bt+92
kacalcoff = ke1bt+93
kfnon = ke1bt+94
kfnoff = ke1bt+95
kplotson = ke1bt+96
kplotsoff = ke1bt+97
kpixelchg = ke1bt+98
ksendmbl = ke1bt+99
krecvmbl = ke1bt+100
kboxplot = ke1bt+101
kboxicon = ke1bt+102
kcrossicon = ke1bt+103
kdoticon = ke1bt+104
ke2bt = ke1bt+105
kseqential = ke2bt
ksimulg = ke2bt+1
kpolarg = ke2bt+2
krectg = ke2bt+3
kcoordon = ke2bt+4
kcoordoff = ke2bt+5
kdrawline = ke2bt+6
kdrawdot = ke2bt+7
kaxison = ke2bt+8
kaxisoff = ke2bt+9
kgridon = ke2bt+10
kgridoff = ke2bt+11
klblon = ke2bt+12
klbloff = ke2bt+13
kl1 = ke2bt+14
kl2 = ke2bt+15
kl3 = ke2bt+16
kl4 = ke2bt+17
kl5 = ke2bt+18
kl6 = ke2bt+19

;these keys are laid on top of existing keys to
;enable localization in the inferential stats editor.
;----------------------------------------------------
kinfdata = kl1
kinfstats = kl1+1
kinfyes = kl1+2
kinfno = kl1+3
kinfcalc = kl1+4
kinfdraw = kl1+5
kinfalt1ne = kl1+6
kinfalt1lt = kl1+7
kinfalt1gt = kl1+8
kinfalt2ne = kl1+9
kinfalt2lt = kl1+10
kinfalt2gt = kl1+11
kinfalt3ne = kl1+12
kinfalt3lt = kl1+13
kinfalt3gt = kl1+14
kinfalt4ne = kl1+15
kinfalt4lt = kl1+16
kinfalt4gt = kl1+17
kinfalt5ne = kl1+18
kinfalt5lt = kl1+19
kinfalt5gt = kl1+20
kinfalt6ne = kl1+21
kinfalt6lt = kl1+22
kinfalt6gt = kl1+23
kmata = ke2bt+20
kmatb = ke2bt+21
kmatc = ke2bt+22
kmatd = ke2bt+23
kmate = ke2bt+24
kxmin = ke2bt+25
kxmax = ke2bt+26
kxscl = ke2bt+27
kymin = ke2bt+28
kymax = ke2bt+29
kyscl = ke2bt+30
ktmin = ke2bt+31
ktmax = ke2bt+32
ktstep = ke2bt+33
komin = ke2bt+34
komax = ke2bt+35
kostep = ke2bt+36
ku0 = ke2bt+37
kv0 = ke2bt+38
knmin = ke2bt+39
knmax = ke2bt+40
kdeltay = ke2bt+41
kdeltax = ke2bt+42
kzxmin = ke2bt+43
kzxmax = ke2bt+44
kzxscl = ke2bt+45
kzymin = ke2bt+46
kzymax = ke2bt+47
kzyscl = ke2bt+48
kztmin = ke2bt+49
kztmax = ke2bt+50
kztstep = ke2bt+51
kzomin = ke2bt+52
kzomax = ke2bt+53
kzostep = ke2bt+54
kzu0 = ke2bt+55
kzv0 = ke2bt+56
kznmin = ke2bt+57
kznmax = ke2bt+58
kdellast = ke2bt+59
ksinreg = ke2bt+60
kconste = ke2bt+61
kpic1 = ke2bt+62
kpic2 = ke2bt+63
kpic3 = ke2bt+64
kdelvar = ke2bt+65
kgetcalc = ke2bt+66
krealm = ke2bt+67
kpolarm = ke2bt+68
krectm = ke2bt+69
kuv = ke2bt+70 ;u vs v
kvw = ke2bt+71 ;v vs w
kuw = ke2bt+72 ;u vs w
kfinpmtend = ke2bt+73
kfinpmtbeg = ke2bt+74
kgraphstyle = ke2bt+75
kexpron = ke2bt+76
kexproff = ke2bt+77
kstata = ke2bt+78
kstatb = ke2bt+79
kstatc = ke2bt+80
kcorr = ke2bt+81
kstatd = ke2bt+82
kstate = ke2bt+83
kregeq = ke2bt+84
kminx = ke2bt+85
kq1 = ke2bt+86
kmd = ke2bt+87
kq3 = ke2bt+88
kmaxx = ke2bt+89
kstatx1 = ke2bt+90
kstaty1 = ke2bt+91
kstatx2 = ke2bt+92
kstaty2 = ke2bt+93
kstatx3 = ke2bt+94
kstaty3 = ke2bt+95
ktblmin = ke2bt+96
ktblstep = ke2bt+97
ksetuplst = ke2bt+98
kclralllst = ke2bt+99
klogistic = ke2bt+100
kztest = ke2bt+101
kttest = ke2bt+102
k2sampztest = ke2bt+103
k2sampttest = ke2bt+104
k1propztest = ke2bt+105
k2propztest = ke2bt+106
kchitest = ke2bt+107
k2sampftest = ke2bt+108
kzintval = ke2bt+109
ktintval = ke2bt+110
k2samptint = ke2bt+111
k2sampzint = ke2bt+112
k1propzint = ke2bt+113
k2propzint = ke2bt+114
kdnormal = ke2bt+115
kinvnorm = ke2bt+116
kdt = ke2bt+117
kchi = ke2bt+118
kdf = ke2bt+119
kbinpdf = ke2bt+120
kbincdf = ke2bt+121
kpoipdf = ke2bt+122
kpoicdf = ke2bt+123
kun = ke2bt+124
kvn = ke2bt+125
kwn = ke2bt+126
krecn = ke2bt+127
kplotstart = ke2bt+128
kzplotstart = ke2bt+129 ;recursion n
kxfact = ke2bt+130 ;plotstart
kyfact = ke2bt+131 ;zplotstart
kanova = ke2bt+132 ;xfact
kmaxy = ke2bt+133 ;yfact
kwebon = ke2bt+134 ;miny
kweboff = ke2bt+135 ;maxy
ktblinput = ke2bt+136 ;web on
kgeopdf = ke2bt+137 ;web off
kgeocdf = ke2bt+138 ;web off
kshadenorm = ke2bt+139
kshadet = ke2bt+140
kshadechi = ke2bt+141
kshadef = ke2bt+142
kplotstep = ke2bt+143
kzplotstep = ke2bt+144
klinregttest = ke2bt+145
kmgt = ke2bt+146 ;vert split
kselecta = ke2bt+147
kzfita = ke2bt+148
ke2bt_end = kzfita

;more 2 byte keys
;------------------------------------
ke2bt2 = $00
kgdb1 = ke2bt2
kgdb2 = ke2bt2+1
kgdb3 = ke2bt2+2
ky1 = ke2bt2+3
ky2 = ke2bt2+4
ky3 = ke2bt2+5
ky4 = ke2bt2+6
ky5 = ke2bt2+7
ky6 = ke2bt2+8
ky7 = ke2bt2+9
ky8 = ke2bt2+10
ky9 = ke2bt2+11
ky0 = ke2bt2+12
kx1t = ke2bt2+13
ky1t = ke2bt2+14
kx2t = ke2bt2+15
ky2t = ke2bt2+16
kx3t = ke2bt2+17
ky3t = ke2bt2+18
kx4t = ke2bt2+19
ky4t = ke2bt2+20
kx5t = ke2bt2+21
ky5t = ke2bt2+22
kx6t = ke2bt2+23
ky6t = ke2bt2+24
kr1 = ke2bt2+25
kr2 = ke2bt2+26
kr3 = ke2bt2+27
kr4 = ke2bt2+28
kr5 = ke2bt2+29
kr6 = ke2bt2+30
kgdb4 = ke2bt2+31
kgdb5 = ke2bt2+32
kgdb6 = ke2bt2+33
kpic4 = ke2bt2+34
kpic5 = ke2bt2+35
kpic6 = ke2bt2+36
kgdb7 = ke2bt2+37
kgdb8 = ke2bt2+38
kgdb9 = ke2bt2+39
kgdb0 = ke2bt2+40
kpic7 = ke2bt2+41
kpic8 = ke2bt2+42
kpic9 = ke2bt2+43
kpic0 = ke2bt2+44
kstatn = ke2bt2+45
kxmean = ke2bt2+46
kconj = ke2bt2+47
kreal = ke2bt2+48
kfangle = ke2bt2+49
klcm = ke2bt2+50
kgcd = ke2bt2+51
krandint = ke2bt2+52
krandnorm = ke2bt2+53
ktopolar = ke2bt2+54
ktorect = ke2bt2+55
kymean = ke2bt2+56
kstdx = ke2bt2+57
kstdx1 = ke2bt2+58
kw0 = ke2bt2+59
kmatf = ke2bt2+60
kmatg = ke2bt2+61
kmatrh = ke2bt2+62
kmati = ke2bt2+63
kmatj = ke2bt2+64
kymean1 = ke2bt2+65
kstdy = ke2bt2+66
kstdy1 = ke2bt2+67
kmattolst = ke2bt2+68
klsttomat = ke2bt2+69
kcumsum = ke2bt2+70
kdeltalst = ke2bt2+71
kstddev = ke2bt2+72
kvariance = ke2bt2+73
klength = ke2bt2+74
kequtostrng = ke2bt2+75
kstrngtoequ = ke2bt2+76
kexpr = ke2bt2+77
ksubstrng = ke2bt2+78
kinstrng = ke2bt2+79
kstr1 = ke2bt2+80
kstr2 = ke2bt2+81
kstr3 = ke2bt2+82
kstr4        = ke2bt2+83
kstr5        = ke2bt2+84
kstr6        = ke2bt2+85
kstr7        = ke2bt2+86
kstr8        = ke2bt2+87
kstr9        = ke2bt2+88
kstr0        = ke2bt2+89
kfinn        = ke2bt2+90
kfini        = ke2bt2+91
kfinpv       = ke2bt2+92
kfinpmt      = ke2bt2+93
kfinfv       = ke2bt2+94
kfinpy       = ke2bt2+95
kfincy       = ke2bt2+96
kfinfpmt     = ke2bt2+97
kfinfi       = ke2bt2+98
kfinfpv      = ke2bt2+99
kfinfn       = ke2bt2+100
kfinffv      = ke2bt2+101
kfinnpv      = ke2bt2+102
kfinirr      = ke2bt2+103
kfinbal      = ke2bt2+104
kfinprn      = ke2bt2+105
kfinint      = ke2bt2+106
ksumx        = ke2bt2+107
ksumx2       = ke2bt2+108
kfintonom    = ke2bt2+109
kfintoeff    = ke2bt2+110
kfindbd      = ke2bt2+111
kstatvp      = ke2bt2+112
kstatz       = ke2bt2+113
kstatt       = ke2bt2+114
kstatchi     = ke2bt2+115
kstatf       = ke2bt2+116
kstatdf      = ke2bt2+117
kstatphat    = ke2bt2+118
kstatphat1   = ke2bt2+119
kstatphat2   = ke2bt2+120
kstatmeanx1  = ke2bt2+121
kstatmeanx2  = ke2bt2+122
kstatstdx1   = ke2bt2+123
kstatstdx2   = ke2bt2+124
kstatstdxp = ke2bt2+125
kstatn1 = ke2bt2+126
kstatn2 = ke2bt2+127
kstatlower = ke2bt2+128
kstatupper = ke2bt2+129
kuw0 = ke2bt2+130
kimag = ke2bt2+131
ksumy = ke2bt2+132
kxres = ke2bt2+133
kstat_s = ke2bt2+134
ksumy2 = ke2bt2+135
ksumxy = ke2bt2+136
kuxres = ke2bt2+137
kmodbox = ke2bt2+138
knormprob = ke2bt2+139
knormalpdf = ke2bt2+140
ktpdf = ke2bt2+141
kchipdf = ke2bt2+142
kfpdf = ke2bt2+143
kminy = ke2bt2+144 ;miny
krandbin = ke2bt2+145
kref = ke2bt2+146
krref = ke2bt2+147
klrsqr = ke2bt2+148
kbrsqr = ke2bt2+149
kdiagon = ke2bt2+150
kdiagoff = ke2bt2+151
kun1 = ke2bt2+152 ;for rcl use when gotten from 82
kvn1 = ke2bt2+153 ;for rcl use when gotten from 82
k83_00end = kvn1 ;end of original keys...
karchive = k83_00end+1
kunarchive = k83_00end+2
kasm = k83_00end+3 ;asm(
kasmprgm = k83_00end+4 ;asmprgm
kasmcomp = k83_00end+5 ;asmcomp(
kcapaacute = k83_00end+6
kcapagrave = k83_00end+7
kcapacaret = k83_00end+8
kcapadier = k83_00end+9
kaacute = k83_00end+10
kagrave = k83_00end+11
kacaret = k83_00end+12
kadier = k83_00end+13
kcapeacute = k83_00end+14
kcapegrave = k83_00end+15
kcapecaret = k83_00end+16
kcapedier = k83_00end+17
keacute = k83_00end+18
kegrave = k83_00end+19
kecaret = k83_00end+20
kedier = k83_00end+21
kcapiacute = k83_00end+22
kcapigrave = k83_00end+23
kcapicaret = k83_00end+24
kcapidier = k83_00end+25
kiacute = k83_00end+26
kigrave = k83_00end+27
kicaret = k83_00end+28
kidier = k83_00end+29
kcapoacute = k83_00end+30
kcapograve = k83_00end+31
kcapocaret = k83_00end+32
kcapodier = k83_00end+33
koacute = k83_00end+34
kograve = k83_00end+35
kocaret = k83_00end+36
kodier = k83_00end+37
kcapuacute = k83_00end+38
kcapugrave = k83_00end+39
kcapucaret = k83_00end+40
kcapudier = k83_00end+41
kuacute = k83_00end+42
kugrave = k83_00end+43
kucaret = k83_00end+44
kudier = k83_00end+45
kcapcced = k83_00end+46
kcced = k83_00end+47
kcapntilde = k83_00end+48
kntilde = k83_00end+49
kaccent = k83_00end+50
kgrave = k83_00end+51
kdieresis = k83_00end+52
kquesdown = k83_00end+53
kexclamdown  = k83_00end+54
kalpha       = k83_00end+55
kbeta        = k83_00end+56
kgamma       = k83_00end+57
kcapdelta = k83_00end+58
kdelta = k83_00end+59
kepsilon = k83_00end+60
klambda = k83_00end+61
kmu = k83_00end+62
kpi2 = k83_00end+63
krho = k83_00end+64
kcapsigma = k83_00end+65
ksigma = k83_00end+66
ktau = k83_00end+67
kphi = k83_00end+68
kcapomega = k83_00end+69
kphat = k83_00end+70
kchi2 = k83_00end+71
kstatf2 = k83_00end+72
kla = k83_00end+73
klb = k83_00end+74
klc = k83_00end+75
kld = k83_00end+76
kle = k83_00end+77
klf = k83_00end+78
klg = k83_00end+79
klh = k83_00end+80
kli = k83_00end+81
klj = k83_00end+82
klk = k83_00end+83
kll = k83_00end+84
klm = k83_00end+85
klsmalln = k83_00end+86
klo = k83_00end+87
klp = k83_00end+88
klq = k83_00end+89
klsmallr = k83_00end+90
kls = k83_00end+91
klt = k83_00end+92
klu = k83_00end+93
klv = k83_00end+94
klw = k83_00end+95
klx = k83_00end+96
kly = k83_00end+97
klz = k83_00end+98
kgarbagec = k83_00end+99 ;garbagecollect
ke2bt2_end = kgarbagec

;ti-83 plus context equates
;---------------------------------------------
cxcmd = kquit ;home screen
cxmatedit = kmatrixed ;matrix editor
cxprgmedit = kprgmed ;program editor
cxequedit = kyequ ;equation editor
cxgrrange = kwindow ;graph range editor
cxgrzfact = kzfacted ;graph zoom factors editor
cxgraph = kgraph ;graph mode
cxstatedit = kstated ;statistics list editor
cxprgminput = kprgminput ;programmed input
cxerror = kerror ;error handler
cxlinkio = klinkio ;link i/o interface
cxmem = kresetmem ;reset memory
cxdefmem = kresetdef ;reset default
cxramapp = kchkram ;ram usage screen
cxmode = kmode ;mode settings screen
cxerase = kdelmem ;memory erase
cxprgmcreate = kprgmcr ;program create
cxtableeditor = ktable ;table editor
cxtableset = ktblset ;table set up
cxstatplot = kstatp ;stat plots
cxinfstat = kinfstat ;inferential statistic
cxformat = kformat ;format context
cxsolvetvm = ksolvetvm ;solve tvm
cxsolveroot = ksolveroot ;solve root
lastoldapp = kextapps ;external applications
cxextapps = kextapps
cxnewapps = knewapps ;new cerberus applications
cxgroup = cxnewapps+0 ;$1st new app.
cxungroup = cxnewapps+1 ;$2nd new app.
lastnewapp = cxungroup ;last new app for this ver

;scan code equates
;-------------------------------
skdown = $01
skleft = $02
skright = $03
skup = $04
skenter = $09
skadd = $0a
sksub = $0b
skmul = $0c
skdiv = $0d
skpower = $0e
skclear = $0f
skchs = $11
sk3 = $12
sk6 = $13
sk9 = $14
skrparen = $15
sktan = $16
skvars = $17
skdecpnt = $19
sk2 = $1a
sk5 = $1b
sk8 = $1c
sklparen = $1d
skcos = $1e
skprgm = $1f
skstat = $20
sk0 = $21
sk1 = $22
sk4 = $23
sk7 = $24
skcomma = $25
sksin = $26
skmatrix = $27
skgraphvar = $28
skstore = $2a
skln = $2b
sklog = $2c
sksquare = $2d
skrecip = $2e
skmath = $2f
skalpha = $30
skgraph = $31
sktrace = $32
skzoom = $33
skwindow = $34
skyequ = $35
sk2nd = $36
skmode = $37
skdel = $38

;tokens
;----------------------------------------------------
eosstart = $00

;display conversions come immediately before 'tstore'
;
dconv = $01
;
ttodms = dconv ;$01
ttodec = dconv+1 ;$02
ttoabc = dconv+2 ;$03 > a b/c
;
tstore = dconv+3 ;$04 lstore 01
;
tboxplot = $05
;
bracks = $06
;
tlbrack = bracks ;$06 '['
trbrack = bracks+1 ;$07 ']'
tlbrace = bracks+2 ;$08 '{'
trbrace = bracks+3 ;$09 '}'
;
tpost1 = bracks+4
;
tfromrad = tpost1 ;$0a lradian
tfromdeg = tpost1+1 ;$0b ldegree
trecip = tpost1+2 ;$0c linverse
tsqr = tpost1+3 ;$0d lsquare
ttrnspos = tpost1+4 ;$0e ltranspose
tcube = tpost1+5 ;$0f '^3'
;
tlparen = $10 ;$10 '('
trparen = $11 ;$11 ')'
;
imun = $12
;
tround = imun ;$12 'round'
tpxtst = imun+1 ;$13 'pxl-test'
taug = imun+2 ;$14 'aug'
trowswap = imun+3 ;$15 'rswap'
trowplus = imun+4 ;$16 'radd'
tmrow = imun+5 ;$17 'multr'
tmrowplus = imun+6 ;$18 'mradd'
tmax = imun+7 ;$19 'max'
tmin = imun+8 ;$1a 'min'
trtopr = imun+9 ;$1b 'r>pr
trtopo = imun+10 ;$1c 'r>po
tptorx = imun+11 ;$1d 'p>rx
tptory = imun+12 ;$1e 'p>ry
tmedian = imun+13 ;$1f 'median
trandm = imun+14 ;$20 'randm'
tmean = imun+15 ;$21
troot = imun+16 ;$22 'root'
tseries = imun+17 ;$23 'seq'
tfnint = imun+18 ;$24 'fnint'
tnderiv = imun+19 ;$25 'fnir'
tevalf = imun+20 ;$26
tfmin = imun+21 ;$27
tfmax = imun+22 ;$28
;
teosel = imun+23
;
tspace = teosel ;$29 ' '
tstring = teosel+1 ;$2a '"'
tcomma = teosel+2 ;$2b ','
;
tii = $2c ;i

;postfix functions
;-----------------------------------------
tpost = $2d
;
tfact = tpost ;$2d '!'
;
tcubicr = $2e
tquartr = $2f

;number tokens
;---------------------------------------
nums = $30
;
t0 = nums ;$30
t1 = nums+1 ;$31
t2 = nums+2 ;$32
t3 = nums+3 ;$33
t4 = nums+4 ;$34
t5 = nums+5 ;$35
t6 = nums+6 ;$36
t7 = nums+7 ;$37
t8 = nums+8 ;$38
t9 = nums+9 ;$39
tdecpt = nums+10 ;$3a
tee = nums+11 ;$3b

;binary op
;-------------------------------------------
tor = $3c ;$3c '_or_'
txor = $3d ;$3d
;
tcolon = $3e ;$3e ':'
tenter = $3f ;$3f lenter
;
tand = $40 ;$40 '_and_'

;letter tokens
;--------------------------------------
let = $41
ta = let ;$41
tb = let+1 ;$42
tc = let+2 ;$43
td = let+3 ;$44
te = let+4 ;$45
tf = let+5 ;$46
tg = let+6 ;$47
th = let+7 ;$48
ti = let+8 ;$49
tj = let+9 ;$4a
tk = let+10 ;$4b
tl = let+11 ;$4c
tm = let+12 ;$4d
tn = let+13 ;$4e
to = let+14 ;$4f
tp = let+15 ;$50
tq = let+16 ;$51
tr = let+17 ;$52
ts = let+18 ;$53
tt = let+19 ;$54
tu = let+20 ;$55
tv = let+21 ;$56
tw = let+22 ;$57
tx = let+23 ;$58
ty = let+24 ;$59
tz = let+25 ;$5a
ttheta = let+26 ;$5b

;these var tokens are 1st of a double token
;------------------------------------------

vtoks = let+27

;user matrix token, 2nd token needed for name
;
tvarmat = vtoks ;$5c
;
;user list token, 2nd token needed for name
;
tvarlst = vtoks+1 ;$5d
;
;user equation token, 2nd token needed for name
;
tvarequ = vtoks+2 ;$5e
tprog = vtoks+3 ;$5f
;
;user pict token, 2nd token needed for name
;
tvarpict = vtoks+4 ;$60
;
;user gdb token, 2nd token needed for name
;
tvargdb = vtoks+5 ;$61
tvarout = vtoks+6 ;$62
tvarsys = vtoks+7 ;$63

;mode setting commands
;-------------------------------------------------
modesa = vtoks+8 ;$64
trad = modesa ;$64 'radian'
tdeg = modesa+1 ;$65 'degree'
tnormf = modesa+2 ;$66 'normal'
tsci = modesa+3 ;$67 'sci'
teng = modesa+4 ;$68 'eng'
tfloat = modesa+5 ;$69 'float'
cmps = $6a
teq = cmps ;$6a '=='
tlt = cmps+1 ;$6b '<'
tgt = cmps+2 ;$6c '>'
tle = cmps+3 ;$6d lle
tge = cmps+4 ;$6e lge
tne = cmps+5 ;$6f lne

;binary op
;---------------------------------------
tadd = $70 ;$70 '+'
tsub = $71 ;$71 '-'
tans = $72 ;$72

;mode setting commands
;-------------------------------------------------------
modes = $73
tfix = modes ;$73 'fix_'
tspliton = modes+1 ;$74
tfullscreen = modes+2 ;$75
tstndrd = modes+3 ;$76 'func'
tparam = modes+4 ;$77 'param'
tpolar = modes+5 ;$78 'pol'
tseqg = modes+6 ;$79
tafillon = modes+7 ;$7a 'auto fill on'
tafilloff = modes+8 ;$7b
tacalcon = modes+9 ;$7c
tacalcoff = modes+10 ;$7d 'autofill off'

;graph format tokens are 2 byte tokens
;----------------------------------------
tgformat = modes+11 ;$7e
tboxicon = $7f
tcrossicon = $80
tdoticon = $81

;(more) binary op
;---------------------------------------
tmul = $82 ;$82 '*'
tdiv = $83 ;$83 '/'

;some graph commands
;------------------------------------------------------
grcmds = $84
ttrace = grcmds ;$84 'trace'
tcldrw = grcmds+1 ;$85 'cldrw'
tzoomstd = grcmds+2 ;$86 'zstd'
tzoomtrg = grcmds+3 ;$87 'ztrg'
tzoombox = grcmds+4 ;$88 'zbox'
tzoomin = grcmds+5 ;$89 'zin'
tzoomout = grcmds+6 ;$8a 'zout'
tzoomsqr = grcmds+7 ;$8b 'zsqr'
tzoomint = grcmds+8 ;$8c 'zint'
tzoomprev = grcmds+9 ;$8d 'zprev'
tzoomdec = grcmds+10 ;$8e 'zdecm'
tzoomstat = grcmds+11 ;$8f 'zstat
tusrzm = grcmds+12 ;$90 'zrcl'
tprtscrn = grcmds+13 ;$91 'prtscrn'
tzoomsto = grcmds+14 ;$92  zoom store
ttext = grcmds+15 ;$93

;binary op (combination & permutation)
;-------------------------------------------------
tnpr = grcmds+16 ;$94 '_npr_'
tncr = grcmds+17 ;$95 '_ncr_'

;more graph commands
;--------------------------------------------------
tyon = grcmds+18 ;$96 'fnon_'
tyoff = grcmds+19 ;$97 'fnoff_'
tstpic = grcmds+20 ;$98 'stpic_'
trcpic = grcmds+21 ;$99 'rcpic_'
tstodb = grcmds+22 ;$9a 'stgdb_'
trcldb = grcmds+23 ;$9b 'rcgdb_'
tline = grcmds+24 ;$9c 'line'
tvert = grcmds+25 ;$9d 'vert_'
tpton = grcmds+26 ;$9e 'pton'
tptoff = grcmds+27 ;$9f 'ptoff'

;token a0 cannot be an eos function since low mult=a0 already
;------------------------------------------------------------
tptchg = grcmds+28 ;$a0 'ptchg'
tpxon = grcmds+29 ;$a1
tpxoff = grcmds+30 ;$a2
tpxchg = grcmds+31 ;$a3
tshade = grcmds+32 ;$a4 'shade'
tcircl = grcmds+33 ;$a5 'circl'
thorz = grcmds+34 ;$a6 'horizontal'
ttanln = grcmds+35 ;$a7 'tanln'
tdrinv = grcmds+36 ;$a8 'drinv_'
tdrawf = grcmds+37 ;$a9 'drawf_'
tvarstrng = $aa

;functions with no arguments
;--------------------------------------------------
noarg = $0ab
trand = noarg ;$ab 'rand'
tpi = noarg+1 ;$ac  lpi
tgetkey = noarg+2 ;$ad 'getky'
tapost = tgetkey+1 ;apostrophy
tquest = tapost+1 ;question mark
unary = tquest+1 ;$b0
tchs = unary ;$b0
tint = unary+1 ;$b1
tabs = unary+2 ;$b2
tdet = unary+3 ;$b3
tident = unary+4 ;$b4
tdim = unary+5 ;$b5
tsum = unary+6 ;$b6
tprod = unary+7 ;$b7
tnot = unary+8 ;$b8
tipart = unary+9 ;$b9
tfpart = unary+10 ;$ba

;new 2 byte tokens
;------------------------------------------
t2bytetok = $bb
unarylr = unary+12
tsqrt = unarylr ;$bc
tcubrt = unarylr+1 ;$bd
tln = unarylr+2 ;$be
texp = unarylr+3 ;$bf
tlog = unarylr+4 ;$c0
talog = unarylr+5 ;$c1
tsin = unarylr+6 ;$c2
tasin = unarylr+7 ;$c3
tcos = unarylr+8 ;$c4
tacos = unarylr+9 ;$c5
ttan = unarylr+10 ;$c6
tatan = unarylr+11 ;$c7
tsinh = unarylr+12 ;$c8
tasinh = unarylr+13 ;$c9
tcoshh = unarylr+14 ;$ca
tacosh = unarylr+15 ;$cb
ttanh = unarylr+16 ;$cc
tatanh = unarylr+17 ;$cd

;some programming commands
;------------------------------------------------------
progtok = unarylr+18
tif = progtok ;$ce
tthen = progtok+1 ;$cf
telse = progtok+2 ;$d0
twhile = progtok+3 ;$d1
trepeat = progtok+4 ;$d2
tfor = progtok+5 ;$d3
tend = progtok+6 ;$d4
treturn = progtok+7 ;$d5
tlbl = progtok+8 ;$d6 'lbl_'
tgoto = progtok+9 ;$d7 'goto_'
tpause = progtok+10 ;$d8 'pause_'
tstop = progtok+11 ;$d9 'stop'
tisg = progtok+12 ;$da 'is>'
tdsl = progtok+13 ;$db 'ds<'
tinput = progtok+14 ;$dc 'input_'
tprompt = progtok+15 ;$dd 'prompt_'
tdisp = progtok+16 ;$de 'disp_'
tdispg = progtok+17 ;$df 'dispg'
toutput = progtok+18 ;$e0 'outpt'
tcllcd = progtok+19 ;$e1 'cllcd'
tconst = progtok+20 ;$e2 'fill'
tsorta = progtok+21 ;$e3 'sorta_'
tsortd = progtok+22 ;$e4 'sortd_'
tdisptab = progtok+23 ;$e5 'disp table
tmenu = progtok+24 ;$e6 'menu'
tsendmbl = progtok+25 ;$e7 'send'
tgetmbl = progtok+26 ;$e8 'get'

;stat plot commands
;------------------------------------------------------
statpcmd = progtok+27
tploton = statpcmd ;$e9 ' plotson'
tplotoff = statpcmd+1 ;$ea ' plotsoff
tlistname = $eb ;list designator
tplot1 = $ec
tplot2 = $ed
tplot3 = $ee
tunused01 = $ef ;available?
tpower = $f0 ;'^'
txroot = $f1 ;lsupx,lroot
statcmd = $f2
tonevar = statcmd ;f2 'onevar_'
ttwovar = statcmd+1 ;f3
tlr = statcmd+2 ;f4 'linr(a+bx
tlrexp = statcmd+3 ;f5 'expr_'
tlrln = statcmd+4 ;f6 'lnr_'
tlrpwr = statcmd+5 ;f7 'pwrr_'
tmedmed = statcmd+6 ;f8
tquad = statcmd+7 ;f9
tclrlst = statcmd+8 ;$fa 'clear list
tclrtbl = statcmd+9 ;$fb clear table
thist = statcmd+10 ;$fc 'hist_'
txyline = statcmd+11 ;$fd 'xyline_'
tscatter = statcmd+12 ;$fe 'scatter_'
tlr1 = statcmd+13 ;$ff 'linr(ax+b

;$2nd half of graph format tokens
;----------------------------------------------
;           format settings commands
;
gfmt = $00
tseq = gfmt ; 'seqg'
tsimulg = gfmt+1 ; 'simulg'
tpolarg = gfmt+2 ; 'polargc'
trectg = gfmt+3 ; 'rectgc'
tcoordon = gfmt+4 ; 'coordon'
tcoordoff = gfmt+5 ; 'coordoff'
tdrawline = gfmt+6 ; 'drawline'
tdrawdot = gfmt+7 ; 'drawdot'
taxison = gfmt+8 ; 'axeson'
taxisoff = gfmt+9 ; 'axesoff'
tgridon = gfmt+10 ; 'gridon'
tgridoff = gfmt+11 ; 'gridoff'
tlblon = gfmt+12 ; 'labelon'
tlbloff = gfmt+13 ; 'labeloff'
twebon = gfmt+14 ; 'webon'
tweboff = gfmt+15 ; 'weboff'
tuv = gfmt+16 ; u vs v
tvw = gfmt+17 ; v vs w
tuw = gfmt+18 ; u vs w

;$2nd half of user matrix tokens
;-------------------------------------
tmata = $00 ;mat a
tmatb = $01 ;mat b
tmatc = $02 ;mat c
tmatd = $03 ;mat d
tmate = $04 ;mat e
tmatf = $05 ;mat f
tmatg = $06 ;mat g
tmath = $07 ;mat
tmati = $08 ;mat i
tmatj = $09 ;mat j

;$2nd half of user list tokens
;--------------------------------------
tl1 = $00 ;list 1
tl2 = $01 ;list 2
tl3 = $02 ;list 3
tl4 = $03 ;list 4
tl5 = $04 ;list 5
tl6 = $05 ;list 6

;$2nd half of user equation tokens
;----------------------------------
;  "y" equations have bit 4 set
;
ty1 = $10 ;y1
ty2 = $11 ;y2
ty3 = $12 ;y3
ty4 = $13 ;y4
ty5 = $14 ;y5
ty6 = $15 ;y6
ty7 = $16 ;y7
ty8 = $17 ;y8
ty9 = $18 ;y9
ty0 = $19 ;y0

;param equations have bit 5 set
;-----------------------------------
tx1t = $20 ;x1t
ty1t = $21 ;y1t
tx2t = $22 ;x2t
ty2t = $23 ;y2t
tx3t = $24 ;x3t
ty3t = $25 ;y3t
tx4t = $26 ;x4t
ty4t = $27 ;y4t
tx5t = $28 ;x5t
ty5t = $29 ;y5t
tx6t = $2a ;x6t
ty6t = $2b ;y6t

;polar equations have bit 6 set
;----------------------------------
tr1 = $40 ;r1
tr2 = $41 ;r2
tr3 = $42 ;r3
tr4 = $43 ;r4
tr5 = $44 ;r5
tr6 = $45 ;r6

;recursion equations have bit 7 set
;----------------------------------
tun = $80 ;un
tvn = $81 ;vn
twn = $82 ;wn

;$2nd half of user picture tokens
;------------------------------------
tpic1 = $00 ;pic1
tpic2 = $01 ;pic2
tpic3 = $02 ;pic3
tpic4 = $03 ;pic4
tpic5 = $04 ;pic5
tpic6 = $05 ;pic6
tpic7 = $06 ;pic7
tpic8 = $07 ;pic8
tpic9 = $08 ;pic9
tpic0 = $09 ;pic0

;$2nd half of user graph database tokens
;--------------------------------------
tgdb1 = $00 ;gdb1
tgdb2 = $01 ;gdb2
tgdb3 = $02 ;gdb3
tgdb4 = $03 ;gdb4
tgdb5 = $04 ;gdb5
tgdb6 = $05 ;gdb6
tgdb7 = $06 ;gdb7
tgdb8 = $07 ;gdb8
tgdb9 = $08 ;gdb9
tgdb0 = $09 ;gdb0

;$2nd half of string vars
;------------------------------
tstr1 = $00
tstr2 = $01
tstr3 = $02
tstr4 = $03
tstr5 = $04
tstr6 = $05
tstr7 = $06
tstr8 = $07
tstr9 = $08
tstr0 = $09

;$2nd half of system output only variables
;-----------------------------------------------------------------
;open = $00
tregeq = $01 ;regression equation
tstatn = $02 ;statistics n
txmean = $03 ;x mean
tsumx = $04 ;sum(x)
tsumxsqr = $05 ;sum(x^2)
tstdx = $06 ;standard dev x
tstdpx = $07 ;standard dev pop x
tminx = $08 ;min x value
tmaxx = $09 ;max x value
tminy = $0a ;min y value
tmaxy = $0b ;max y value
tymean = $0c ;y mean
tsumy = $0d ;sum(y)
tsumysqr = $0e ;sum(y^2)
tstdy = $0f ;standard dev y
tstdpy = $10 ;standard dev pop y
tsumxy = $11 ;sum(xy)
tcorr = $12 ;correlation
tmedx = $13 ;med(x)
tq1 = $14 ;1st quadrant of x
tq3 = $15 ;3rd quadrant of x
tquada = $16 ;1st term of quad poly reg/ y-int
tquadb = $17 ;2nd term of quad poly reg/ slope
tquadc = $18 ;3rd term of quad poly reg
tcubed = $19 ;4th term of cubic poly reg
tquarte = $1a ;5th term of quart poly reg
tmedx1 = $1b ;x1 for med-med
tmedx2 = $1c ;x2 for med-med
tmedx3 = $1d ;x3 for med-med
tmedy1 = $1e ;y1 for med-med
tmedy2 = $1f ;y2 for med-med
tmedy3 = $20 ;y3 for med-med
trecurn = $21	;recursion n
tstatp = $22
tstatz = $23
tstatt = $24
tstatchi = $25
tstatf = $26
tstatdf = $27
tstatphat = $28
tstatphat1 = $29
tstatphat2 = $2a
tstatmeanx1 = $2b
tstatstdx1 = $2c
tstatn1 = $2d
tstatmeanx2 = $2e
tstatstdx2 = $2f
tstatn2 = $30
tstatstdxp = $31
tstatlower = $32
tstatupper = $33
tstat_s = $34
tlrsqr = $35 ;r^2
tbrsqr = $36 ;r^2

;these next tokens are only used to access the data
;they are display only and the user cannot access them at all
;------------------------------------------------------------
tf_df = $37 ;anofav factor df
tf_ss = $38 ;anofav factor ss
tf_ms = $39 ;anofav factor ms
te_df = $3a ;anofav error df
te_ss = $3b ;anofav error ss
te_ms = $3c ;anofav error ms

;$2nd half of system input/output variables
;------------------------------------------------
;      system variable equates
;
tuxscl = $00
tuyscl = $01
txscl = $02
tyscl = $03
trecuru0 = $04 ;u 1st initial cond
trecurv0 = $05 ;v 1st initial cond
tun1 = $06 ;u(n-1); not used
tvn1 = $07 ;v(n-1); not used
turecuru0 = $08 ;
turecurv0 = $09 ;
txmin = $0a
txmax = $0b
tymin = $0c
tymax = $0d
ttmin = $0e
ttmax = $0f
tthetamin = $10
tthetamax = $11
tuxmin = $12
tuxmax = $13
tuymin = $14
tuymax = $15
tuthetmin = $16
tuthetmax = $17
tutmin = $18
tutmax = $19
ttblmin = $1a
tplotstart = $1b
tuplotstart = $1c
tnmax = $1d
tunmax = $1e
tnmin = $1f
tunmin = $20
ttblstep = $21
ttstep = $22
tthetastep = $23
tutstep = $24
tuthetstep = $25
tdeltax = $26
tdeltay = $27
txfact = $28
tyfact = $29
ttblinput = $2a
tfinn = $2b
tfini = $2c
tfinpv = $2d
tfinpmt = $2e
tfinfv = $2f
tfinpy = $30
tfincy = $31
trecurw0 = $32 ;w0(1)
turecurw0 = $33
tplotstep = $34
tuplotstep = $35
txres = $36
tuxres = $37
trecuru02 = $38 ;u0(2)
turecuru02 = $39
trecurv02 = $3c ;v0(2)
turecurv02 = $3d
trecurw02 = $3e ;w0(2)
turecurw02 = $3f

;$2nd byte of t2bytetok tokens
;------------------------------
tfinnpv = $00
tfinirr = $01
tfinbal = $02
tfinprn = $03
tfinint = $04
tfintonom = $05
tfintoeff = $06
tfindbd = $07
tlcm = $08
tgcd = $09
trandint = $0a
trandbin = $0b
tsubstrng = $0c
tstddev = $0d
tvariance = $0e
tinstrng = $0f
tdnormal = $10
tinvnorm = $11
tdt = $12
tchi = $13
tdf = $14
tbinpdf = $15
tbincdf = $16
tpoipdf = $17
tpoicdf = $18
tgeopdf = $19
tgeocdf = $1a
tnormalpdf = $1b
ttpdf = $1c
tchipdf = $1d
tfpdf = $1e
trandnorm = $1f
tfinfpmt = $20
tfinfi = $21
tfinfpv = $22
tfinfn = $23
tfinffv = $24
tconj = $25
treal = $26
timag = $27
tangle = $28
tcumsum = $29
texpr = $2a
tlength = $2b
tdeltalst = $2c
tref = $2d
trref = $2e
ttorect = $2f
ttopolar = $30
tconste = $31
tsinreg = $32
tlogistic = $33
tlinregttest = $34
tshadenorm = $35
tshadet = $36
tshadechi = $37
tshadef = $38
tmattolst = $39
tlsttomat = $3a
tztest = $3b
tttest = $3c
t2sampztest = $3d
t1propztest = $3e
t2propztest = $3f
tchitest = $40
tzintval = $41
t2sampzint = $42
t1propzint = $43
t2propzint = $44
tgraphstyle = $45
t2sampttest = $46
t2sampftest = $47
ttintval = $48
t2samptint = $49
tsetuplst = $4a
tfinpmtend = $4b
tfinpmtbeg = $4c
trealm = $4d
tpolarm = $4e
trectm = $4f
texpron = $50
texproff = $51
tclralllst = $52
tgetcalc = $53
tdelvar = $54
tequtostrng = $55
tstrngtoequ = $56
tdellast = $57
tselect = $58
tanova = $59
tmodbox = $5a
tnormprob = $5b
tmgt = $64 ;vertical split
tzfit = $65 ;zoom fit
tdiag_on = $66 ;dianostic display on
tdiag_off = $67 ;dianostic display off
tokend2v0 = $67 ;end of 2byte tokens for version 0.
tarchive = $68 ;archive
tunarchive = $69 ;unarchive
tasm = $6a
tasmcomp = $6b	;asm compile
tasmprgm = $6c	;signifies a program is asm
tasmcmp = $6d	;asm program is compiled
tlcapaacute = $6e
tlcapagrave = $6f
tlcapacaret = $70
tlcapadier = $71
tlaacute = $72
tlagrave = $73
tlacaret = $74
tladier = $75
tlcapeacute = $76
tlcapegrave = $77
tlcapecaret = $78
tlcapedier = $79
tleacute = $7a
tlegrave = $7b
tlecaret = $7c
tledier = $7d
tlcapigrave = $7f
tlcapicaret = $80
tlcapidier = $81
tliacute = $82
tligrave = $83
tlicaret = $84
tlidier = $85
tlcapoacute = $86
tlcapograve = $87
tlcapocaret = $88
tlcapodier = $89
tloacute = $8a
tlograve = $8b
tlocaret = $8c
tlodier = $8d
tlcapuacute = $8e
tlcapugrave = $8f
tlcapucaret = $90
tlcapudier = $91
tluacute = $92
tlugrave = $93
tlucaret = $94
tludier = $95
tlcapcced = $96
tlcced = $97
tlcapntilde = $98
tlntilde = $99
tlaccent = $9a
tlgrave = $9b
tldieresis = $9c
tlquesdown = $9d
tlexclamdown = $9e
tlalpha = $9f
tlbeta = $a0
tlgamma = $a1
tlcapdelta = $a2
tldelta = $a3
tlepsilon = $a4
tllambda = $a5
tlmu = $a6
tlpi = $a7
tlrho = $a8
tlcapsigma = $a9
tlphi = $ab
tlcapomega = $ac
tlphat = $ad
tlchi = $ae
tlstatf = $af
tla = $b0
tlb = $b1
tlc = $b2
tld = $b3
tlsmalle = $b4
tlf = $b5
tlsmallg = $b6
tlh = $b7
tli = $b8
tlj = $b9
tlk = $ba
tll = $bc
tlm = $bd
tlsmalln = $be
tlo = $bf
tlp = $c0
tlq = $c1
tlsmallr = $c2
tls = $c3
tlsmallt = $c4
tlu = $c5
tlv = $c6
tlw = $c7
tlx = $c8
tly = $c9
tlz = $ca
tlsigma = $cb
tltau = $cc
tlcapiacute = $cd
tgarbagec = $ce
lasttoken = $ce ;tlast token in this version...

;data type equates
;---------------------------------------------------------------------
realobj = $00
listobj = $01
matobj = $02
equobj = $03
strngobj = $04
progobj = $05
protprogobj = $06
pictobj = $07
gdbobj = $08
unknownobj = $09
unknownequobj = $0a
newequobj = $0b
cplxobj = $0c
clistobj = $0d
undefobj = $0e
windowobj = $0f
zstoobj = $10
tblrngobj = $11
lcdobj = $12
backupobj = $13
appobj = $14	;application, only used in menus/link
appvarobj = $15	;application variable
tempprogobj = $16 ;program, home deletes when finished
groupobj = $17 ;group.

;i/o equates
;---------------------------------------------------
d0d1_bits = $03
d0ld1l = $03
d0ld1 = $01
d0d1l = $02
d0d1 = $00
bport = $00 ;$4-bit link port (i/o)

;device codes
;-----------------------------------------------------------------
ti82dev = $82
pc82dev = $02
mac82dev = $12
ti83fdev = $73
link83fdev = $23
ti83dev = $83
pc83dev = $03
mac83dev = $13
ti85dev = $95 ;different than real 85 so me talk
pc85dev = $05
mac85dev = $15
ti73dev = $74 ;device x3 is always an 83
pc73dev = $07
mac73dev = $17
link73fdev = $23
pc83fdev = $23

;system error codes
;-----------------------------------------------------------
e_editf = 7 ;allow re-entering application
e_edit = 1<<e_editf
e_mask = $7f
e_overflow = 1+e_edit
e_divby0 = 2+e_edit
e_singularmat = 3+e_edit
e_domain = 4+e_edit
e_increment = 5+e_edit
e_break = 6+e_edit
e_nonreal = 7+e_edit
e_syntax = 8+e_edit
e_datatype = 9+e_edit
e_argument = 10+e_edit
e_dimmismatch = 11+e_edit
e_dimension = 12+e_edit
e_undefined = 13+e_edit
e_memory = 14+e_edit
e_invalid = 15+e_edit
e_illegalnest = 16+e_edit
e_bound = 17+e_edit
e_graphrange = 18+e_edit
e_zoom = 19+e_edit
e_label = 20
e_stat = 21
e_solver = 22+e_edit
e_singularity = 23+e_edit
e_signchange = 24+e_edit
e_iterations = 25+e_edit
e_badguess = 26+e_edit
e_statplo = 27
e_toltoosmall = 28+e_edit
e_reserved = 29+e_edit
e_mode = 30+e_edit
e_lnkerr = 31+e_edit
e_lnkmemerr = 32+e_edit
e_lnktranserr = 33+e_edit
e_lnkduperr = 34+e_edit
e_lnkmemfull = 35+e_edit
e_unknown = 36+e_edit
e_scale = 37+e_edit
e_idnotfound = 38
e_nomode = 39+e_edit
e_validation = 40
e_length = 41+e_edit
e_application = 42+e_edit
e_apperr1 = 43+e_edit
e_apperr2 = 44+e_edit
e_expiredapp = 45
e_badadd = 46
e_archived = 47+e_edit
e_version = 48
e_archfull = 49
e_variable = 50+e_edit
e_duplicate = 51+e_edit
higerrnum = 51
;obsolete error numbers 34 ;first link error
e_linkiochksum = 34
e_linkiotimeout = 35
e_linkiobusy = 36
e_linkiover = 37

;equates to ram locations for stat vars
;----------------------------------------------------------------
fplen = 9 ;length of a floating-point number.
statn = statvars
xmean = statn+fplen
sumx = xmean+fplen
sumxsqr = sumx+fplen
stdx = sumxsqr+fplen
stdpx = stdx+fplen
minx = stdpx+fplen
maxx = minx+fplen
miny = maxx+fplen
maxy = miny+fplen
ymean = maxy+fplen
sumy = ymean+fplen
sumysqr = sumy+fplen
stdy = sumysqr+fplen
stdpy = stdy+fplen
sumxy = stdpy+fplen
corr = sumxy+fplen
medx = corr+fplen
q1 = medx+fplen
q3 = q1+fplen
quada = q3+fplen
quadb = quada+fplen
quadc = quadb+fplen
cubed = quadc+fplen
quarte = cubed+fplen
medx1 = quarte+fplen
medx2 = medx1+fplen
medx3 = medx2+fplen
medy1 = medx3+fplen
medy2 = medy1+fplen
medy3 = medy2+fplen
pstat = medy3+2*fplen
zstat = pstat+fplen
tstat = zstat+fplen
chistat = tstat+fplen
fstat = chistat+fplen
df = fstat+fplen
phat = df+fplen
phat1 = phat+fplen
phat2 = phat1+fplen
meanx1 = phat2+fplen
stdx1 = meanx1+fplen
statn1 = stdx1+fplen
meanx2 = statn1+fplen
stdx2 = meanx2+fplen
statn2 = stdx2+fplen
stdxp2 = statn2+fplen
slower = stdxp2+fplen
supper = slower+fplen
sstat = supper+fplen
f_df = anovaf_vars
f_ss = f_df+fplen
f_ms = f_ss+fplen
e_df = f_ms+fplen
e_ss = e_df+fplen
e_ms = e_ss+fplen