;ti-83 plus include file
;$05/07/2007

#define _GrBufClr _grbufclr

;system variable equates
;------------------------------
#define xsclt	$02
#define ysclt	$03
#define xmint	$0a
#define xmaxt	$0b
#define ymint	$0c
#define ymaxt	$0d
#define tmint	$0e
#define tmaxt	$0f
#define thetmint	$10
#define thetmaxt	$11
#define tblmint	$1a
#define plotstartt	$1b
#define nmaxt	$1d
#define nmint	$1f
#define tblstept	$21
#define tstept	$22
#define thetstept	$23
#define deltaxt	$26
#define deltayt	$27
#define xfactt	$28
#define yfactt	$29
#define finnt	$2b
#define finit	$2c
#define finpvt	$2d
#define finpmtt	$2e
#define finfvt	$2f
#define finpyt	$30
#define fincyt	$31
#define plotstept	$34
#define xrest	$36

;run indicators
;------------------------------------
#define busypause	%10101010
#define busynormal	%11110000

;banked call equates/macros
;-----------------------------------------------
#define rbr_call	$28
#define brt_jump0	$50
#define bcall(xxxx) rst rbr_call\	.dw xxxx
#define bjump(xxxx) call brt_jump0\	.dw xxxx

;common restart routines
;------------------------------
#define rop1toop2	$08
#define rfindsym	$10
#define rpushrealo1	$18
#define rmov9toop1	$20
#define rfpadd	$30

;error handler equates/macros
;-------------------------------------------
#define app_push_errorh	$59
#define app_pop_errorh	$5c
#define apponerr(xxxx) ld hl,xxxx\	call app_push_error
#define appofferr call app_pop_error

;page $1b rom calls
;--------------------------------
#define _jerrorno	$4000
#define _fonthook	$4003
#define _call_character_hook	$4006 ;calls character(localize) hook
#define _ldhlind	$4009 ;l=a=(hl),h=(hl+1)
#define _cphlde	$400c
#define _divhlby10	$400f
#define _divhlbya	$4012
#define _kdbscan	$4015
#define _getcsc	$4018 ;key board scan codes
#define _coormon	$401b ;
#define _mon	$401e ;system monitor, customized through the context vectors
#define _monforcekey	$4021 ;
#define _sendkpress	$4024
#define _jforcecmdnochar	$4027
#define _jforcecmd	$402a ;
#define _syserrhandler	$402d ;loads error context? sp=(onsp)
#define _newcontext	$4030 ;(kbdkey)=0, loads context, restores page in $4000-$7fff
#define _newcontext0	$4033 ;loads context
#define _cxputaway	$4036 ;
#define _cxputaway2	$4039 ;same but also does a b_call canalphins
#define _cxpputaway	$403c
#define _cxsizewind	$403f
#define _cxerrep	$4042
#define _cxmain	$4045
#define _monerrhand	$4048 ;installs errorhandler to start of rom call, loads error context, jumps to mon
#define _appinit	$404b ;loads vector data at hl to cxmain and the rest of the vectors
#define _resetram	$404e
#define _lcd_busy	$4051 ;wait till bit 1 of port 2 is set
#define _min	$4054 ;op1 = lowest number between op1 and op2
#define _max	$4057 ;op1 = highest number between op1 and op2
#define _trunc	$4060
#define _invsub	$4063
#define _times2	$4066
#define _plus1	$4069 ;op1=op1+1
#define _minus1	$406c
#define _fpsub	$406f
#define _fpadd	$4072
#define _dtor	$4075
#define _rtod	$4078
#define _cube	$407b
#define _timespt5	$407e
#define _fpsquare	$4081
#define _fpmult	$4084 ;op1=op1*op2
#define _ljrnd	$4087 ;adjusts op1 if 0s precede the actual number... rounding? when
#define _invop1sc	$408a
#define _invop1s	$408d
#define _invop2s	$4090
#define _frac	$4093
#define _fprecip	$4096
#define _fpdiv	$4099
#define _sqroot	$409c
#define _rndguard	$409f
#define _rnfx	$40a2
#define _int	$40a5
#define _round	$40a8
#define _lnx	$40ab
#define _logx	$40ae
#define _ljnornd	$40b1 ;like _ljrnd but no rounding
#define _etox	$40b4
#define _tenx	$40b7
#define _sincosrad	$40ba
#define _sin	$40bd
#define _cos	$40c0
#define _tan	$40c3
#define _sinhcosh	$40c6
#define _tanh	$40c9
#define _cosh	$40cc
#define _sinh	$40cf
#define _acosrad	$40d2
#define _atanrad	$40d5
#define _atan2rad	$40d8
#define _asinrad	$40db
#define _acos	$40de
#define _atan	$40e1
#define _asin	$40e4
#define _atan2	$40e7
#define _atanh	$40ea
#define _asinh	$40ed
#define _acosh	$40f0
#define _ptor	$40f3
#define _rtop	$40f6
#define _hltimes9	$40f9
#define _ckop1cplx	$40fc
#define _ckop1real	$40ff
#define _angle	$4102
#define _cop1set0	$4105
#define _cpop4op3	$4108
#define _mov9op2cp	$410b
#define _abso1o2cp	$410e
#define _cpop1op2	$4111
#define _op3toop4	$4114
#define _op1toop4	$4117
#define _op2toop4	$411a
#define _op4toop2	$411d
#define _op1toop3	$4123
#define _op5toop2	$4126
#define _op5toop6	$4129
#define _op5toop4	$412c
#define _op1toop2	$412f
#define _op6toop2	$4132
#define _op6toop1	$4135
#define _op4toop1	$4138
#define _op5toop1	$413b
#define _op3toop1	$413e
#define _op6toop5	$4141
#define _op4toop5	$4144
#define _op3toop5	$4147
#define _op2toop5	$414a
#define _op2toop6	$414d
#define _op1toop6	$4150
#define _op1toop5	$4153
#define _op2toop1	$4156
#define _mov11b	$4159
#define _mov10b	$415c
#define _mov9b	$415f
#define _mov9b2	$4162 ;points to _mov9b
#define _mov8b	$4165
#define _mov7b	$4168
#define _mov7b2	$416b ;same pointer as _mov7b
#define _op2toop3	$416e
#define _op4toop3	$4171
#define _op5toop3	$4174
#define _op4toop6	$4177
#define _mov9toop1	$417a
#define _mov9op1op2	$417d
#define _mov9toop2	$4180
#define _movfrop1	$4183
#define _op4set1	$4186
#define _op3set1	$4189
#define _op2set8	$418c
#define _op2set5	$418f
#define _op2seta	$4192
#define _op2set4	$4195
#define _op2set3	$4198
#define _op1set1	$419b
#define _op1set4	$419e
#define _op1set3	$41a1
#define _op3set2	$41a4
#define _op1set2	$41a7
#define _op2set2	$41aa
#define _op2set1	$41ad
#define _zero16d	$41b0
#define _op5set0	$41b3
#define _op4set0	$41b6
#define _op3set0	$41b9
#define _op2set0	$41bc
#define _op1set0	$41bf
#define _opset0	$41c2 ;hl = location to write floating point 0
#define _zeroop1	$41c5
#define _zeroop2	$41c8
#define _zeroop3	$41cb
#define _zeroop	$41ce
#define _clrlp	$41d1
#define _shracc	$41d4 ;move high nibble in a to low nibble
#define _shlacc	$41d7 ;move low nibble in a to high nibble
#define _shr18	$41da ;insert a 0 nibble at high nibble of (hl), shift 9 bytes 1 nibble to right
#define _shr18a	$41dd ;insert low nibble in a at high nibble of (hl), shift 9 bytes 1 nibble to right
#define _shr16	$41e0 ;insert a 0 nibble at highnibble of (hl), shift 8 bytes 1 nibble to right
#define _shr14	$41e3 ;insert low nibble in a at high nibble of (hl), shift 7 bytes 1 nibble to right
#define _shl16	$41e6 ;insert nibble of 0 in low nibble of (hl), shift 8 bytes (before and including (hl)) to the left 1 nibble
#define _shl14	$41e9 ;insert low nibble of a in low nibble of (hl), shift 7 bytes (before and including (hl)) to the left 1 nibble
#define _srdo1	$41ec
#define _shrdrnd	$41ef
#define _mantpa	$41f2 ;adds the value of a to hl which points to the end of the bcd 7 bytes long
#define _addprop	$41f5 ;adds the value of a to hl which points to the end of the bcd (b bytes long)
#define _addproplp	$41f8 ;adds the value of a and carry to hl which points to the end of the bcd (b bytes long)
#define _add16d 	$41fb ;adds the bcd numbers at (hl-7) and (de-7)
#define _add14d	$41fe ;adds the bcd numbers at (hl-6) and (de-6)
#define _sub16d	$4201 ;subtracts bcd numbers at (hl-7) and (de-7)
#define _sub14d	$4204 ;subtracts bcd numbers at (hl-6) and (de-6)
#define _op2exop6	$4207
#define _op5exop6	$420a
#define _op1exop5	$420d
#define _op1exop6	$4210
#define _op2exop4	$4213
#define _op2exop5	$4216
#define _op1exop3	$4219
#define _op1exop4	$421c
#define _op1exop2	$421f
#define _exlp	$4222
#define _ckop1c0	$4225
#define _ckop1fp0	$4228
#define _ckop2fp0	$422b
#define _posno0int	$422e
#define _ckposint	$4231
#define _ckint	$4234
#define _ckodd	$4237
#define _ckop1m	$423a
#define _getconop1	$423d	;a=0 opx=57.29577951308232 (1 radian in degrees)
#define _getconop2	$4240	;a=1 opx=1.570796326794897 (90 deg = pi/2)
							;a=2 opx=.7853981633974483 (45 deg = pi/4)
							;a=3 opx=.4342944819032518 (log e)
							;a=4 opx=3.141592653589800 (pi)
							;a=5 opx=.0174532925199433 (pi/180 = 1 degree in radians)
							;a=6 opx=2.302585092994046 (ln 10)
#define _pidiv2	$4243 ;not code, but a pointer to:	.db 80,15,70,79,63,26,79,48,97
#define _pidiv4	$4246 ;								.db 7f,78,53,98,16,33,97,44,83
#define _pitimes2	$4249 ;not code, but a pointer to a 2*pi in non-op format (no exponent byte)
#define _pi	$424c ;not code, but a pointer to a pi in non-op format (no exponent byte)
#define _exptohex	$424f
#define _op1exptodec	$4252
#define _ckop2pos	$4255
#define _ckop1pos	$4258
#define _clrop2s	$425b
#define _clrop1s	$425e
#define _fdiv100	$4261 ;op1=op1/100
#define _fdiv10	$4264 ;op1=op1/10
#define _deco1exp	$4267 ;decrease exponent by 1, this can go from $00 to $ff
#define _inco1exp	$426a ;op1=op1*10
#define _incexp	$426d ;hl points to the floating point's exponent to be multiplied by 10
#define _ckvalidnum	$4270
#define _getexp	$4273 ;a=op1's exponent, carry set if negative exponent, z if e0
#define _htimesl	$4276
#define _eop1notreal	$4279
#define _thetaname	$427c
#define _rname	$427f
#define _regeqname	$4282
#define _recurnname	$4285
#define _xname	$4288
#define _yname	$428b
#define _tname	$428e
#define _realname	$4291
#define _setestofps	$4294 ;moves the word at fps to es
#define _marktabledirty	$4297 ;looks up table variable and marks vat entry as "dirty" or selected
#define _op1mop2exp	$429a ;op1's exponent = op1's expoent - op2's exponent
#define _op1expminuse	$429d ;a=(op1+1)-e
#define _chkerrbreak	$42a0
#define _isa2bytetok	$42a3
#define _getlastentry	$42a6
#define _getlastentryptr	$42a9
#define _regclrchng	$42ac
#define _resetwintop	$42af ;takes into account grfsplitoverride and grfsplit flags
#define _setyup	$42b2 ;loads 7 to port 10... what does this do?
#define _setxup	$42b5 ;loads 5 to port 10...
#define _iso1nontlstorprog	$42b8 ;checks if op1 contains a list, program, group, or appvar obj name
#define _iso1nontemplst	$42bb ;checks if op1 contains a list (why would op1+1 contain 01, or 0d for a var name?)
#define _is_a_lstorclst	$42be ;checks if a = 1 or 0d
#define _chk_hl_999	$42c1 ;returns nc if less than 999, throws invalid dim error if greater than or equal to 999
#define _equ_or_newequ	$42c4
#define _errd_op1notpos	$42c7
#define _errd_op1not_r	$42ca
#define _errd_op1notposint 	$42cd
#define _errd_op1_le_0	$42d0
#define _errd_op1_0	$42d3
#define _findsym_get_size 	$42d6 ;like findsym, but on output hl is the size of the variable
#define _sto_statvar	$42d9
#define _rcl_statvar	$42dc
#define _ckop2real	$42df
#define _get_x_indirect	$42e2 ;whatever this is, it uses the imathptrx locations
#define _memchk	$42e5
#define _cmpprgnamlen1	$42e8 ;gets variable name length from hl
#define _cmpprgnamlen	$42eb ;gets variable name length from op1
#define _findprogsym	$42ee ;find the program whose name is in op1 (see chkfindsym in sdk)
#define _chkfindsym	$42f1
#define _findsym	$42f4
#define _insertmem	$42f7
#define _insertmema	$42fa ;not sure how this differs from insertmem
#define _enoughmem	$42fd
#define _cmpmemneed	$4300
#define _createpvar4	$4303
#define _createpvar3	$4306
#define _createvar3	$4309
#define _createcplx	$430c
#define _createreal	$430f
#define _createtemprlist	$4312
#define _createrlist	$4315
#define _createtclist	$4318
#define _createclist	$431b
#define _createtemprmat	$431e
#define _creatermat	$4321
#define _createtempstring	$4324
#define _createstrng	$4327
#define _create0equ	$432a
#define _createtempequ	$432d
#define _createequ	$4330
#define _createpict	$4333
#define _creategdb	$4336
#define _createprog	$4339
#define _chkdel	$433c
#define _chkdela	$433f
#define _adjparser	$4342
#define _adjmath	$4345
#define _adjm7	$4348
#define _delmema	$434b
#define _get_form_num	$434e
#define _delvar	$4351
#define _delvario	$4354
#define _delmem	$4357
#define _delvar3d	$435a
#define _delvar3c	$435d
#define _delvar3dc	$4360 ;may be incorrect
#define _isfixedname	$4363
#define _delvarentry	$4366
#define _datasizea	$4369
#define _datasize	$436c
#define _popmcplxo1	$436f
#define _popmcplx	$4372
#define _movcplx	$4375
#define _popop5	$4378
#define _popop3	$437b
#define _popop1	$437e
#define _poprealo6	$4381
#define _poprealo5	$4384
#define _poprealo4	$4387
#define _poprealo3	$438a
#define _poprealo2	$438d
#define _poprealo1	$4390
#define _popreal	$4393
#define _fpopcplx	$4396
#define _fpopreal	$4399
#define _fpopfps	$439c
#define _deallocfps	$439f
#define _deallocfps1	$43a2
#define _allocfps	$43a5
#define _allocfps1	$43a8
#define _pushrealo6	$43ab
#define _pushrealo5	$43ae
#define _pushrealo4	$43b1
#define _pushrealo3	$43b4
#define _pushrealo2	$43b7
#define _pushrealo1	$43ba
#define _pushreal	$43bd
#define _pushop5	$43c0
#define _pushop3	$43c3
#define _pushmcplxo3	$43c6
#define _pushop1	$43c9
#define _pushmcplxo1	$43cc
#define _pushmcplx	$43cf
#define _exmcplxo1	$43d2
#define _exch9	$43d5
#define _cpyto1fps11	$43d8
#define _cpyto2fps5	$43db
#define _cpyto1fps5	$43de
#define _cpyto2fps6	$43e1
#define _cpyto1fps6	$43e4
#define _cpyto2fps7	$43e7
#define _cpyto1fps7	$43ea
#define _cpyto1fps8	$43ed
#define _cpyto2fps8	$43f0
#define _cpyto1fps10	$43f3
#define _cpyto1fps9	$43f6
#define _cpyto2fps4	$43f9
#define _cpyto6fps3	$43fc
#define _cpyto6fps2	$43ff
#define _cpyto2fps3	$4402
#define _cpycto1fps3	$4405
#define _cpyto1fps3	$4408
#define _cpyfps3	$440b
#define _cpyto1fps4	$440e
#define _cpyto3fps2	$4411
#define _cpyto5fpst	$4414
#define _cpyto6fpst	$4417
#define _cpyto4fpst	$441a
#define _cpyto3fpst	$441d
#define _cpyto2fpst	$4420
#define _cpyto1fpst	$4423
#define _cpyfpst	$4426
#define _cpystack	$4429
#define _cpyto3fps1	$442c
#define _cpyto2fps1	$442f
#define _cpyto1fps1	$4432
#define _cpyfps1	$4435
#define _cpyto2fps2	$4438
#define _cpyto1fps2	$443b
#define _cpyfps2	$443e
#define _cpyo3tofpst	$4441
#define _cpyo2tofpst	$4444
#define _cpyo6tofpst	$4447
#define _cpyo1tofpst	$444a
#define _cpytofpst	$444d
#define _cpytostack	$4450
#define _cpyo3tofps1	$4453
#define _cpyo5tofps1	$4456
#define _cpyo2tofps1	$4459
#define _cpyo1tofps1	$445c
#define _cpytofps1	$445f
#define _cpyo2tofps2	$4462
#define _cpyo3tofps2	$4465
#define _cpyo6tofps2	$4468
#define _cpyo1tofps2	$446b
#define _cpytofps2	$446e
#define _cpyo5tofps3	$4471
#define _cpyo2tofps3	$4474
#define _cpyo1tofps3	$4477
#define _cpytofps3	$447a
#define _cpyo1tofps6	$447d
#define _cpyo1tofps7	$4480
#define _cpyo1tofps5	$4483
#define _cpyo2tofps4	$4486
#define _cpyo1tofps4	$4489
#define _errnotenoughmem 	$448c ;only if not hl bytes free
#define _fpsminus9	$448f
#define _hlminus9	$4492
#define _erroverflow	$4495
#define _errdivby0	$4498
#define _errsingularmat	$449b
#define _errdomain	$449e
#define _errincrement	$44a1
#define _errnon_real	$44a4
#define _errsyntax	$44a7
#define _errdatatype	$44aa
#define _errargument	$44ad
#define _errdimmismatch	$44b0
#define _errdimension	$44b3
#define _errundefined	$44b6
#define _errmemory	$44b9
#define _errinvalid	$44bc
#define _errbreak	$44bf
#define _errstat	$44c2
#define _errsignchange	$44c5
#define _erriterations	$44c8
#define _errbadguess	$44cb
#define _errtoltoosmall	$44ce
#define _errstatplot	$44d1
#define _errlinkxmit	$44d4
#define _jerror	$44d7
#define _noerrorentry	$44da
#define _pusherrorhandler	$44dd
#define _poperrorhandler	$44e0
#define _strcopy	$44e3
#define _strcat	$44e6
#define _isinset	$44e9
#define _sdone	$44ec
#define _serrort	$44ef
#define _snameeq	$44f2
#define _sunderscr	$44f5
#define _sfail	$44f8
#define _sname	$44fb
#define _sok	$44fe
#define _putmap	$4501
#define _putc	$4504
#define _disphl	$4507
#define _puts	$450a
#define _putpsb	$450d
#define _putps	$4510
#define _wputps	$4513
#define _putbuf	$4516
#define _putbuf1	$4519
#define _wputc	$451c
#define _wputs	$451f
#define _wputseol	$4522 ;displays string in hl in big font, and uses ... if too long
#define _wdispeol	$4525
#define _whomeup	$4528
#define _setnumwindow	$452b ;based on current cursor position, sets winleft and similar (for input prompts)
#define _newline	$452e
#define _movedown	$4531
#define _scrollup	$4534
#define _shrinkwindow	$4537
#define _moveup	$453a
#define _scrolldown	$453d
#define _clrlcdfull	$4540
#define _clrlcd	$4543
#define _clrscrnfull	$4546
#define _clrscrn	$4549
#define _clrtxtshd	$454c
#define _clrwindow	$454f
#define _eraseeol	$4552
#define _eraseeow	$4555
#define _homeup	$4558
#define _getcurloc	$455b
#define _vputmap	$455e
#define _vputs	$4561
#define _vputsn	$4564
#define _vputsng	$4567
#define _vputsnt	$456a
#define _runindicon	$456d
#define _runindicoff	$4570
#define _savecmdshadow	$4573
#define _saveshadow	$4576
#define _rstrshadow	$4579
#define _rstrpartial	$457c
#define _rstrcurrow	$457f
#define _rstrundermenu	$4582
#define _rstrbotrow	$4585
#define _savetr	$4588 ;save top right corner of lcd so 2nd arrow can be displayed, indicinuse flag must be set
#define _restoretr	$458b ;restore top right corner of lcd destroyed by an arrow. indicinuse flag must be set
#define _getkeypress	$458e
#define _gettoklen	$4591 ;input: hl=pointer to token. output: a=lenght of string, hl=pointer to string on page 1
#define _get_tok_strng	$4594 ;input: hl=pointer to token. output: op3=string of the token, a=length of string
#define _gettokstring	$4597 ;input: de=token. output: hl=pointer to the string on page 1
#define _putbpatbuf2	$459a
#define _putbpatbuf	$459d
#define _putbpat	$45a0
#define _putccheckscroll	$45a3
#define _dispeol	$45a6
#define _fdispeol	$45a9
#define _makerowcmd	$45ac
#define _totostrp	$45af
#define _setvarname	$45b2
#define _dispdone	$45b5
#define _finishoutput	$45b8
#define _curblink	$45bb
#define _cursoroff	$45be
#define _hidecursor	$45c1
#define _cursoron	$45c4
#define _showcursor	$45c7
#define _keytostring	$45ca
#define _pulldownchk	$45cd ;something wrong here
#define _menucatcommon	$45d0
#define _zifcatalog	$45d3
#define _zifmatrixmenu	$45d6 ;_loadcurcat
#define _loadmenunum	$45d9
#define _loadmenunuml	$45dc
#define _mencatret	$45df ;restores display as though a menu were just cleared (restores some flags too)
#define _menuswitchcontext	$45e2 ;switches to context in a, calls menu hook with a=3, set 5,(iy+$16) for some sort of override to not make switc
#define _menuedkey	$45e5
;$45e8
#define _notalphnum	$45eb
#define _savesavedflags	$45ee
#define _setmenuflags	$45f1
#define _rstrsomeflags	$45f4
#define _rstroscreen	$45f7 ;restores savesscreen to the display
#define _saveoscreen	$45fa ;stores display in savesscreen
#define _displistname	$45fd ;_seeiferrorcx
#define _prevcontext	$4600
#define _comparecontext	$4603
#define _adrmrow	$4606
#define _adrmele	$4609
#define _getmatop1a	$460c
#define _getm1toop1	$460f
#define _getm1top1a	$4612
#define _getmtoop1	$4615
#define _puttom1a	$4618
#define _puttoma1	$461b
#define _puttomat	$461e
#define _mat_el_div	$4621
#define _cmatfun	$4624
#define _rowech_poly	$4627
#define _rowechelon	$462a
#define _adrlele	$462d
#define _getl1toop1	$4630
#define _getl1top1a	$4633
#define _getltoop1	$4636
#define _getl1toop2	$4639
#define _getl1top2a	$463c
#define _getl2top1a	$463f
#define _puttola1	$4642
#define _puttol	$4645
#define _maxminlst	$4648
#define _llow	$464b
#define _lhigh	$464e
#define _lsum	$4651
#define cumsum	$4654
#define _tofrac	$4657
#define _seqset	$465a
#define _seqsolve	$465d
#define _cmp_num_init	$4660
#define _binopexec	$4663
#define _exmean1	$4666
#define _set2mvlptrs	$4669
#define _setmat1	$466c
#define _createtlist	$466f
#define _unopexec	$4672
#define _threeexec	$4675
#define _restoreerrno	$4678
#define _fourexec	$467b
#define _fiveexec	$467e
#define _cpyto2es1	$4681
#define _cpyto6es1	$4684
#define _cpyto1es1	$4687
#define _cpyto3es1	$468a
#define _cpyto3es2	$468d
#define _cpyto2es2	$4690
#define _cpyto1es2	$4693
#define _cpyto2es3	$4696
#define _cpyto1es3	$4699
#define _cpyto3es4	$469c
#define _cpyto6es3	$469f
#define _cpyto2es4	$46a2
#define _cpyto1es4	$46a5
#define _cpyto2es5	$46a8
#define _cpyto1es5	$46ab
#define _cpyto4est	$46ae
#define _cpyto2est	$46b1
#define _cpyto1est	$46b4
#define _cpyto2es6	$46b7
#define _cpyto1es6	$46ba
#define _cpyto2es7	$46bd
#define _cpyto1es7	$46c0
#define _cpyto2es8	$46c3
#define _cpyto1es8	$46c6
#define _cpyto1es9	$46c9
#define _cpyto2es9	$46cc
#define _cpyto2es10	$46cf
#define _cpyto1es10	$46d2
#define _cpyto2es11	$46d5
#define _cpyto1es11	$46d8
#define _cpyto2es12	$46db
#define _cpyto1es12	$46de
#define _cpyto2es13	$46e1
#define _cpyto1es13	$46e4
#define _cpyto1es14	$46e7
#define _cpyto1es16	$46ea
#define _cpyto1es17	$46ed
#define _cpyto1es18	$46f0
#define _cpyto1es15	$46f3
#define _cpyto2es15	$46f6
#define _cpyo1toest	$46f9
#define _cpyo1toes1	$46fc
#define _cpyo6toes1	$46ff
#define _cpyo6toes3	$4702
#define _cpyo1toes2	$4705
#define _cpyo2toes2	$4708
#define _cpyo1toes3	$470b
#define _cpyo1toes4	$470e
#define _cpyo1toes5	$4711
#define _cpyo1toes6	$4714
#define _cpyo1toes7	$4717
#define _cpyo2toes4	$471a
#define _cpyo2toes5	$471d
#define _cpyo2toes6	$4720
#define _cpyo2toes7	$4723
#define _cpyo2toes8	$4726
#define _cpyo2toes9	$4729
#define _cpyo1toes8	$472c
#define _cpyo1toes9	$472f
#define _cpyo1toes10	$4732
#define _cpyo1toes11	$4735
#define _cpyo1toes12	$4738
#define _cpyo1toes13	$473b
#define _cpyo1toes14	$473e
#define _cpyo1toes15	$4741
#define _evalf3a	$4744
#define _getk	$4747 ;?
#define _settitle	$474a
#define _dispvarval	$474d
#define _recalled	$4750 ;_setupbuffer
#define _createnumeditbuf	$4753
#define _processbufkeys	$4756 ;may be default key processing like [clear], etc. especially for an edit buffer.
#define _callcommon	$4759
#define _commonkeys	$475c
#define _leftmore	$475f
#define _fdel	$4762
#define _fclear	$4765
#define _finsdisp	$4768 ;michael says #define _finsdisp02	$4768 (something's not right)
#define _finsdisp02	$476b ;_setindicator
#define _closeeditbufnor	$476e
#define _releasebuffer	$4771
#define _varnametoop1l	$4774
#define _nametoop1	$4777
#define _numpputaway	$477a
#define _numredisp	$477d
#define _numerror02	$4780
#define _load_sfont	$4783
#define _sfont_len	$4786
#define _initnumvec	$4789
#define _setxxop1	$478c
#define _setxxop2	$478f
#define _setxxxxop2	$4792
#define _uclines	$4795
#define _cline	$4798
#define _clines	$479b
#define _xrooty	$479e
#define _ytox	$47a1
#define _zmstats	$47a4
#define _point_stat_hlp	$47a7
#define _drawsplot	$47aa
#define _initnewtracep	$47ad
#define _splotcoord	$47b0
#define _splotright	$47b3
#define _splotleft	$47b6
#define _cmpboxinfo	$47b9
#define _nextplot	$47bc
#define _prevplot	$47bf
#define _clrprevplot	$47c2
#define _put_index_lst	$47c5
#define _get_index_lst	$47c8
#define _heap_sort	$47cb
#define _stogdb2	$47ce
#define _rclgdb2	$47d1
#define _circcmd	$47d4
#define _grphcirc	$47d7
#define _mov18b	$47da
#define _darkline	$47dd
#define _iline	$47e0
#define _ipoint	$47e3
#define _xyrndboth	$47e6
#define _xyrnd	$47e9
#define _checktop	$47ec
#define _checkxy	$47ef
#define _darkpnt	$47f2
#define _cpoints	$47f5
#define _wtov	$47f8
#define _vtowhlde	$47fb
#define _xitof	$47fe
#define _yftoi	$4801
#define _xftoi	$4804
#define _traceoff	$4807
#define _grredisp	$480a
#define _gdisptoken	$480d
#define _grdecoda	$4810
#define _labcoor	$4813
#define _coordisp	$4816 ;draws x & y coordinates (or r and theta if polargc)
#define _tmpequnosrc	$4819
#define _grlabels	$481c
#define _ypixset	$481f
#define _xpixset	$4822
#define _copyrng	$4825
#define _valcur	$4828
#define _grputaway	$482b
#define _rstgflags	$482e
#define _grreset	$4831
#define _xycent	$4834
#define _zoomxycmd	$4837
#define _cptdely	$483a
#define _cptdelx	$483d
#define _setfuncm	$4840
#define _setseqm	$4843
#define _setpolm	$4846
#define _setparm	$4849
#define _zmint	$484c
#define _zmdecml	$484f
#define _zmprev	$4852
#define _zmusr	$4855
#define _setuzm	$4858
#define _zmfit	$485b
#define _zmsquare	$485e
#define _zmtrig	$4861
#define _setxminmax	$4864
#define _zoodefault	$4867
#define _grbufcpy	$486a
#define _drawsplitline	$486d
#define _restoredisp	$4870
#define _fnddb	$4873
#define _alleq	$4876
#define _fndallseleq	$4879
#define _nexteq	$487c
#define _preveq	$487f
#define _blinkgcur	$4882
#define _nbcursor	$4885
#define _statmark	$4888
#define _chktextcurs	$488b
#define _regraph	$488e
#define _dorefflags02	$4891 ;something wrong here
#define initnseq	$4894
#define _yres	$4897 ;_plotptxy2
#define _ceiling	$489a ;ceil(op1)
#define _putxy	$489d ;draws x & y coordinates (regardless of polargc)
#define _putequno	$48a0
#define _pdspgrph	$48a3
#define _horizcmd	$48a6
#define _vertcmd	$48a9
#define _linecmd	$48ac
#define _unlinecmd	$48af
#define _pointcmd	$48b2
#define _pixeltest	$48b5
#define _pixelcmd  	$48b8
#define _tanlnf	$48bb
#define _drawcmd_init	$48be
#define _drawcmd	$48c1
#define _shadecmd	$48c4
#define _invcmd	$48c7
#define _statshade	$48ca
#define _dspmattable	$48cd
#define _dsplsts	$48d0
#define _closeeditbuf	$48d3
#define _parseeditbuf	$48d6
#define _putsm	$48d9
#define _dspcurtbl	$48dc
#define _dspgrtbl	$48df
#define _zerotemplate	$48e2
#define _settblrefs	$48e5
#define _disptblbot	$48e8
#define _disptbltop	$48eb
#define _disptblbody	$48ee
#define _vputblank	$48f1
#define _tbltrace	$48f4
#define _displistnamey	$48f7
#define _curnamelength	$48fa
#define _nametobuf	$48fd
#define _jpromptcursor	$4900
#define _bufleft	$4903
#define _bufright	$4906
#define _bufinsert	$4909
#define _bufqueuechar	$490c
#define _bufreplace	$490f
#define _bufdelete	$4912
#define _bufpeek	$4915
#define _bufpeek1	$4918
#define _bufpeek2	$491b
#define _bufpeek3	$491e
#define _buftobtm	$4921
#define _setupeditequ	$4924
#define _buftotop	$4927
#define _iseditfull	$492a
#define _iseditempty	$492d
#define _isattop	$4930
#define _isatbtm	$4933
#define _bufclear	$4936
#define _jcursorfirst	$4939
#define _jcursorlast	$493c
#define _cursorleft	$493f
#define _cursorright	$4942
#define _cursorup	$4945
#define _cursordown	$4948
#define _cursortooffset	$494b
#define _insdisp	$494e
#define _fdispbol1	$4951
#define _fdispbol	$4954
#define _dispeow	$4957
#define _disphead	$495a
#define _disptail	$495d
#define _puttokstring	$4960
#define _setupeditcmd	$4963
#define _setemptyeditequ	$4966
#define _setemptyeditptr	$4969
#define _closeeditequ	$496c
#define _getprevtok	$496f
#define _getkey	$4972
#define _canindic	$4975
#define _lcd_driveron	$4978
#define _dfmin2	$497b
#define _formdisp	$497e
#define _formmatrix	$4981
#define _wscrollleft	$4984
#define _wscrollup	$4987
#define _wscrolldown	$498a
#define _wscrollright	$498d
#define _formereal	$4990
#define _formerealtok	$4993
#define _formdcplx	$4996
#define _formreal	$4999
#define _formscrollup	$499c
#define _setwinabove	$499f
#define _disarmscroll	$49a2
#define _op1toedit	$49a5
#define _mintoedit	$49a8
#define _rclvartoedit	$49ab
#define _rclvartoeditptr	$49ae
#define _rclentrytoedit	$49b1
#define _rcltoqueue	$49b4 ;recalls bytes at op1 into edit buffer
#define _formtotok	$49b7
#define _disp_interval	$49ba
#define _displstname	$49bd
#define _dispslstnamehl	$49c0
#define _editequ	$49c3
#define _closeequfield	$49c6
#define _autoselect	$49c9
#define _dispyeos	$49cc
#define _dispnumeos	$49cf
#define _setupdispeq	$49d2
#define _dispforward	$49d5
#define _dispyprompt2	$49d8
#define _stringwidth	$49db
#define _disperrorscreen	$49de ;displays top row of error screen (error message)
#define _popcx	$49e1 ;moves 14 bytes at cxprev to cxmain, 15th byte goes to replace appflags
#define _loadnoeentry	$49e4
#define _savescreen	$49e7
#define _retscreen	$49ea
#define _retscreenerr	$49ed
#define _checksplitflag	$49f0
#define _solveredisp	$49f3
#define _solvedisp	$49f6
#define _itemname	$49f9
#define _setnorm_vals	$49fc
#define _setyoffset	$49ff ;sets up yoffset and next 4 bytes (possibly specialized for the table editor)
#define _convkeytotok	$4a02
#define _convfckeytotok	$4a05
#define _convfekeytotok	$4a08
#define _toktokey	$4a0b
#define _sendskipexitpacket	$4a0e
#define _getvarcmd	$4a11
#define _sendvarcmd	$4a14
#define _sendscreenshot	$4a17
#define keyscnlnk	$4a1a
#define _deselectallvars	$4a1d
#define _delres	$4a20
#define _convlctolr	$4a23
#define _redimmat	$4a26
#define _inclstsize	$4a29
#define _insertlist	$4a2c
#define _dellistel	$4a2f
#define _editprog	$4a32
#define _closeprog	$4a35
#define _clrgraphref	$4a38
#define _fixtempcnt	$4a3b
#define _savedata	$4a3e
#define _restoredata	$4a41
#define _findalphaup	$4a44
#define _findalphadn	$4a47
#define _cmpsyms	$4a4a
#define _createtemp	$4a4d
#define _cleanall	$4a50
#define _movetonextsym	$4a53 ;input: hl=pointer to type byte of vat entry. output: hl = pointer to next entry's type byte
#define _convlrtolc	$4a56
#define _tblscreendn	$4a59 ;something is not right here
#define _tblscreenup	$4a5c
#define _screenup	$4a5f
#define _screenupdown	$4a62
#define _zifrclhandler	$4a65
#define _zifrclkapp	$4a68
#define _rclkeyrtn	$4a6b
#define _rclkey	$4a6b
#define _rclregeq_call	$4a6e
#define _rclregeq	$4a71
#define _initnameprompt	$4a74
#define _nameprompt2	$4a77
#define _catalogchk	$4a7a
#define _clrtr	$4a7d
#define _quad	$4a80
#define _graphquad	$4a83
#define _bc2noreal	$4a86
;$4a89
#define _errnonreal	$4a8c ;err:data type if top b numers from fps are non-real
#define _write_text	$4a8f
#define _forseqinit	$4a92
#define _grphpars	$4a95
#define _plotpars	$4a98
#define _parseinp	$4a9b
#define _parseoff	$4a9e
#define _parsescan	$4aa1
#define _getparse	$4aa4
#define _saveparse	$4aa7
#define _initpflgs	$4aaa
#define _ckendlinerr	$4aad
#define _op2set60	$4ab0
#define _getstatptr	$4ab3
#define _cmp_statptr	$4ab6
#define _varsysadr	$4ab9
#define _stosystok	$4abc
#define _stoans	$4abf
#define _stotheta	$4ac2
#define _stor	$4ac5
#define _stoy	$4ac8
#define _ston	$4acb
#define _stot	$4ace
#define _stox	$4ad1
#define _stoother	$4ad4
#define _rclans	$4ad7
#define _rcly	$4ada
#define _rcln	$4add
#define _rclx	$4ae0
#define _rclvarsym	$4ae3
#define _rclsystok	$4ae6
#define _stmatel	$4ae9
#define _stlstvecel	$4aec
#define _convop1	$4aef
#define _find_parse_formula	$4af2
#define _parse_formula	$4af5
#define _fetchquotedstring	$4af8
#define _fetchnumline	$4afb
;$4afe
#define _parseinpgraph	$4b01 ;same as _parseinp except 3,(iy+$1f) is graph/split screen override, or something
#define _parseinpgraphreset	$4b04 ;_parseinpgraph except zeroes out iy+6/7, resets 3,(iy+$1a) & 0,(iy+$1f), fmtflags->fmtoverride, parse within parseinp?
#define _parseinplastent	$4b07 ;parseinp on program $05,$23,$00
#define _erroncertaintypes	$4b0a ;err:data type if a is one of a couple of values...subroutine in parseinp, somehow
#define _createpair	$4b0d
#define _pushnum	$4b10
#define _inccurpcerrend	$4b13
#define _errend	$4b16
#define _commaerrf	$4b19
#define _commaerr	$4b1c
#define _steqarg2	$4b1f
#define _steqarg	$4b22
#define _inparg	$4b25
#define _steqarg3	$4b28
#define _nxtfetch	$4b2b
#define _ckfetchvar	$4b2e
#define _fetchvara	$4b31
#define _fetchvar	$4b34
#define _ckendlin	$4b37 ;gets parse byte in a and then _ckendexp
#define _ckendexp	$4b3a ;checks a for $3e or $3f
#define _ckparsend	$4b3d
#define _stotypearg	$4b40
#define _convdim	$4b43
#define _convdim00	$4b46
#define _aheadequal	$4b49
#define _parsaheads	$4b4c
#define _parsahead         	$4b4f
#define _ansname	$4b52
#define _stocmpreals	$4b55
#define _getdeptr	$4b58
#define _push2boper	$4b5b ;push the value in bc onto the operator stack
#define _pop2boper	$4b5e ;pop 2 bytes on the operator stack to bc
#define _pushoper	$4b61 ;push the value in a onto the operator stack
#define _popoper	$4b64 ;pop 1 byte on the operator stack to a
#define _find_e_undef	$4b67
#define _sttmpeq	$4b6a
#define _findeol	$4b6d
#define _brkinc	$4b70
#define _incfetch	$4b73
#define _curfetch	$4b76
#define _random	$4b79
#define _storand	$4b7c
#define _randinit	$4b7f
#define _resetstacks	$4b82 ;(onsp)->(errsp), (fpbase)->(fps), (opbase)->(ops)
#define _factorial	$4b85
#define _yonoff	$4b88
#define _eqselunsel	$4b8b
#define _itsolver	$4b8e
#define _gritsolver	$4b91
#define _itsolverb	$4b94
#define _itsolvernb	$4b97
#define _extest_int	$4b9a
#define _dist_fun	$4bad
#define _loggamma	$4ba0
#define _onevar	$4ba3
#define _onevars_0	$4ba6
#define _ordstat	$4ba9
#define _initstatans2	$4bac
#define _anova_spec	$4baf
#define _outputexpr	$4bb2
#define _centcursor	$4bb5
#define _text	$4bb8
#define _finishspec	$4bbb
#define _trcyfunc	$4bbe
#define _rcl_seq_x	$4bc1
#define _rclseq2	$4bc4
#define _grpputaway	$4bc7
#define _ckvaldelx	$4bca
#define _ckvaldelta	$4bcd
#define _grbufclr	$4bd0
#define _grbufcpy_v	$4bd3
#define _fndseleq	$4bd6
#define _clrgraphxy	$4bd9
#define _nedxt_y_style	$4bdc
#define _plotpt	$4bdf
#define _newindep	$4be2
#define _axes	$4be5
#define _setpenx	$4be8
#define _setpeny	$4beb
#define _setpent	$4bee
#define _tan_equ_disp	$4bf1
#define _putans	$4bf4
#define _dispop1a	$4bf7
#define _mathtanln	$4bfa
#define _enddraw	$4bfd
#define _settblgraphdraw	$4c00
#define _startdialog	$4c03
#define _dialoginit	$4c06
#define _getdialognumop1	$4c09
#define _setdialognumop1	$4c0c
#define _getdialognumhl	$4c0f
#define _errargumento123	$4c12 ;err:argument if op2>op1 or op1>op3
#define _setdialogkeyoverride	$4c15
#define _resdialogkeyoverride	$4c18
#define _forcedialogkeypress	$4c1b
#define _dialogstartgetkey	$4c1e
#define _startdialog_override	$4c21
#define _calldialogcallback	$4c24
#define _setdialogcallback	$4c27
#define _resdialogcallback	$4c2a
#define _copydialognum	$4c2d
#define _memclear	$4c30
#define _memset	$4c33
#define _reloadappentryvecs	$4c36
#define _pointon	$4c39
#define _executenewprgm	$4c3c
#define _strlength	$4c3f
#define _vputmaprec	$4c42
#define _getrompage	$4c45
#define _findappup	$4c48
#define _findappdn	$4c4b
#define _findapp	$4c4e
#define _executeapp	$4c51
#define _monreset	$4c54
;$4c57
;$4c5a
#define _iscontextkey	$4c5d
#define _ibounds	$4c60
#define _ioffset	$4c63
#define _drawcirc2	$4c66
#define _canalphins	$4c69
#define cxredisp	$4c6c
#define _getbasever	$4c6f
#define _opset0de	$4c72 ;loads a floating point 0 to location de
#define _appgetcbl	$4c75
#define _appgetcalc	$4c78
#define _savedisp	$4c7b
#define _setignorekey  	$4c7e ;set 1,(iy+$28) / ret
#define _setsendthiskeyback	$4c81 ;set 2,(iy+$28) / ld (kbdkey),a / ret
#define _disableapd	$4c84
#define _enableapd	$4c87 ;set apdable,(iy+apdflags)
#define _jforcecmdnochar2	$4c8a ;$2.41 at least
#define _set2iy34	$4c8d ;set 2,(iy+$34) / ret
#define _forcecmd	$4c90
#define _apdsetup	$4c93
#define _get_numkey	$4c96
#define _appsetup	$4c99 ;or _appcleanup, or something
#define _handlelinkkeyactivity	$4c9c
#define _jforcecmdnochar3	$4c9f ;2.41 at least
#define _releasesedit	$4ca2
#define _initsmalleditline	$4ca5
#define _startsmalledit	$4ca8
;$4cab
#define _sgettokstring	$4cae
#define _loadpattern	$ 	$4cb1
#define _sstringlength	$4cb4
#define _restorepencol	$4cb7
;$4cba
#define _donothing	$4cbd
#define _forcesmalleditreturn	$4cc0
;$4cc3 ;saves context
;$4cc6
;$4cc9
;$4ccc
#define _veraseeol	$4ccf
;$4cd2
;$4cd5
#define _gotoerr	$4cd8
#define _initsmalleditbox	$4cdb
;$4cde
#define _emptyhook	$4ce1
#define _forcesmalleditreturn2	$4ce4
;$4ce7 ;same as $4cc3
;$4cea
#define _clearrow	$4ced
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
#define _appscreenupdown	$4d26 ;shifts screen up/down, a is lcd row, h is number of lines to shift, (op1)-(op1+3) are something
#define _appscreenupdown1	$4d29 ;shifts screen up/down, but really no clue what the inputs are (all registers and (op1)-(op1+3))
;$4d2c
#define _initsmalleditlinevar	$4d2f
#define _initsmalleditlineop1	$4d32
#define _initsmalleditboxvar	$4d35
#define _initsmalleditboxop1	$4d38
;$4d3b
#define _restartdialog	$4d3e
#define _errcustom1	$4d41
#define _errcustom2	$4d44
#define _appstartmouse	$4d47
#define _appstartmousenosetup	$4d4a
#define _appmousegetkey	$4d4d
#define _appdispmouse	$4d50
#define _apperasemouse	$4d53
#define _appsetupmousemem	$4d56
#define _getdisprowoffset	$4d59 ;hl=a*12 (intended for a to be row and hl becomes offset into plotsscreen)
#define _clearrect	$4d5c
#define _invertrect	$4d5f
#define _fillrect	$4d62
#define _appupdatemouse	$4d65
#define _appdispprevmouse	$4d68 ;might bring previous keypress's movement to current coordinates with flags to not display
;$4d6b ;restores some cursor flags and stuff
#define _initcellbox	$4d6e
#define _drawcell	$4d71
;$4d74
#define _invertcell	$4d77
#define _setcelloverride	$4d7a
#define _drawrectborder	$4d7d
#define _clearcell	$4d80
#define _covercell	$4d83
#define _eraserectborder	$4d86
#define _fillrectpattern	$4d89
#define _drawrectborderclear	$4d8c
;$4d8f ;mouse subroutine
;$4d92
#define _verticalline	$4d95
#define _iboundsfull	$4d98
#define _displayimage	$4d9b
;$4d9e ;does something dumb with ports 10/11
;$4da1 ;mouse subroutine
#define _appupdatemousecoords	$4da4
#define _shiftbitsleft	$4da7 ;mouse subroutine, shifts b bits left from de sprite to hl one
;$4daa ;mouse subroutine
;$4dad ;mouse subroutine
;$4db0 ;mouse subroutine
;$4db3 ;mouse subroutine
;$4db6 ;mouse subroutine
;$4db9 ;mouse subroutine
;$4dbc ;mouse subroutine
#define _appupdatemouserow	$4dbf
#define _appdrawmouse	$4dc2 ;set 2,(iy+$2c) for apperasemouse, reset for appdispmouse
#define _appdrawmousedirect	$4dc5 ;pretty much _appdrawmouse, but you pass lcd column in a
#define _cpoint	$4dc8
#define _deleteapp	$4dcb
#define _appupdatemousexy	$4dce
#define _setmodecellflag	$4dd1
#define _resetmodecellflag	$4dd4
#define _ismodecellset	$4dd7
#define _getmodecellflag	$4dda
;$4ddd
#define _cellboxmanager	$4de0
#define _startnewcell	$4de3
;$4de6
#define _cellcursorhandle	$4de9
;$4dec
;$4def
#define _clearcurcell	$4df2
#define _drawcurcell	$4df5
#define _invertcurcell	$4df8
#define _covercurcell	$4dfb
#define _blinkcell	$4dfe
#define _blinkcellnolookup	$4e01
#define _blinkcurcell	$4e04
#define _blinkcelltoon	$4e07
#define _blinkcelltoonnolookup	$4e0a
#define _blinkcurcelltoon	$4e0d
#define _blinkcelltooff	$4e10
#define _blinkcelltooffnolookup	$4e13
#define _blinkcurcelltooff	$4e16
#define _getcurmodecellflag	$4e19
;$4e1c
#define _startsmalleditreturn	$4e1f
;$4e22
;$4e25
#define _cellkhandle	$4e28
#define _errchkalphabox	$4e2b
;$4e2e
;$4e31
;$4e34
;$4e37
#define _eraseallcells	$4e3a
#define _iscurmodecellset	$4e3d
;$4e40
#define _initalphabox	$4e43
;$4e46
;$4e49
#define _drawblnkcell	$4e4c
#define _clearblnkcell	$4e4f
#define _invertblnkcell	$4e52
#define _appmouseforcekey	$4e55
#define _appsetupmousememcoords	$4e58 ;this is _appsetupmousemem except you pass starting coordinates in hl
#define _appmovemouse	$4e5b ;this is _appmouseforcekey and then updating coordinates
#define _getstringinput	$4e5e
#define _getstringinput2	$4e61
;$4e64
#define _horizontalline	$4e67
#define _createappvar	$4e6a
#define _createprotprog	$4e6d
#define _createvar	$4e70
#define _asmcomp	$4e73
#define _getasmsize	$4e76
#define _squishprgm	$4e79
#define _executeprgm	$4e7c
#define _chkfindsymasm	$4e7f
#define _parseprgmname	$4e82
#define _csub	$4e85
#define _cadd	$4e88
#define _csqaure	$4e8b
#define _cmult	$4e8e
#define _crecip	$4e91
#define _cdiv	$4e94
#define _cabs	$4e97
#define _addsquares	$4e9a
#define _csqroot	$4e9d
#define _cln	$4ea0
#define _clog	$4ea3
#define _ctenx	$4ea6
#define _cetox	$4ea9
#define _cxrooty	$4eac
;$4eaf
#define _cytox	$4eb2
#define _invertnonreal	$4eb5
#define _cplxmult	$4eb8
#define _cplxdiv	$4ebb
#define _cplxtrunc	$4ebe
#define _cplxfrac	$4ec1
#define _cplxfloor	$4ec4
#define _sendheaderpacket	$4ec7
#define _canceltransmission	$4eca
#define _sendscreencontents	$4ecd
#define _sendramvardata	$4ed0
#define _sendramcmd	$4ed3
#define _sendpacket	$4ed6
#define _receiveack	$4ed9
#define _send4bytepacket	$4edc
#define _senddatabyte	$4edf
#define _send4bytes	$4ee2
#define _sendabyte	$4ee5
#define _sendcbyte	$4ee8
#define _getsmallpacket	$4eeb
#define _getdatapacket	$4eee
#define _sendack	$4ef1
#define _get4bytes	$4ef4
#define _get3bytes	$4ef7
#define _rec1stbyte	$4efa
#define _rec1stbytenc	$4efd
#define _continuegetbyte	$4f00
#define _recabyteio	$4f03
#define _receivevar	$4f06
#define _receivevardataexists	$4f09
#define _receivevardata	$4f0c
#define _srchvlstup	$4f0f
#define _srchvlstdn	$4f12
#define _sendvariable	$4f15
#define _get4bytescursor	$4f18
#define _get4bytesnc	$4f1b
#define _convert85list	$4f1e
#define _senddirectorycontents	$4f21
#define _sendreadypacket	$4f24
#define _convert85real	$4f27
#define _ret_6	$4f2a
#define _sendcertificate	$4f2d ;sends certificate in header/data packets, flash must be unlocked, used with sending an application in link menu
#define _sendapplication	$4f30
#define _sendosheader	$4f33
#define _sendospage	$4f36
#define _sendos	$4f39
#define _flashwritedisable	$4f3c
#define _sendcmd	$4f3f
#define _sendosvalidationdata	$4f42
#define _disp	$4f45
#define _sendgetkeypress	$4f48
#define _rejectcommand	$4f4b
#define _checklinklines	$4f4e
#define _gethookbyte	$4f51
#define _getbytepaged	$4f54
#define _cursorhook	$4f57
#define _call_library_hook	$4f5a
#define _call_rawkey_hook	$4f5d
#define _setcursorhook	$4f60 ;enable cursor hook
#define _enablelibraryhook	$4f63
#define _setgetkeyhook	$4f66
#define _clrcursorhook	$4f69
#define _disablelibraryhook	$4f6c
#define _clrrawkeyhook  	$4f6f
#define _resethookbytes	$4f72
#define _adjustallhooks	$4f75
#define _getkeyhook	$4f78
#define _setgetcschook	$4f7b
#define _clrgetkeyhook	$4f7e
#define _call_linkactivity_hook	$4f81
#define _enablelinkactivityhook	$4f84
#define _disablelinkhook	$4f87
#define _getsmallpacket2	$4f8a
#define _enablecatalog2ook	$4f8d
#define _disablecatalog2ook	$4f90
#define _enablelocalizehook	$4f93
#define _disablelocalizehook	$4f96
#define _settokenhook	$4f99
#define _cleartokenhook	$4f9c
;$4f9f ld hl,$92c6 / ld a,($92c5) / res 2,a / cp (hl) / ret
;$4fa2 hl=11*($92fc)+$92c9 / ld a,(hl) / and f / cp 2 / ret
;$4fa5
#define _bit_vertsplit	$4fa8
#define _sethomescreenhook	$4fab
#define _clrhomescreenhook	$4fae
#define _setwindowhook	$4fb1
#define _disablewindowhook	$4fb4
#define _setgraphmodehook	$4fb7
#define _disablegraphhook	$4fba
;$4fbd
;$4fc0
#define _jforcewindowsettings	$4fc3
#define _delvararc	$4fc6
#define _delvarnoarc	$4fc9
#define _setallplots	$4fcc
#define _setyedithook 	$4fcf
#define _disableyequhook	$4fd2
#define _jforceyequ	$4fd5
#define _arc_unarc	$4fd8 ;checks for low battery
#define _archivevar	$4fdb ;set 0,(iy+$24) to check for low battery first
#define _unarchivevar	$4fde
#define _dialogkeyhook	$4fe1 ;rawkey hook used by os for dialog context
#define _setfonthook	$4fe4
#define _clrfonthook	$4fe7
#define _setregraphhook	$4fea
#define _disableregraphhook	$4fed
#define _rungraphinghook	$4ff0
#define _settracehook	$4ff3
#define _disabletracehook	$4ff6
#define _runtracehook	$4ff9
#define _nderiv	$4ffc
;$4fff
#define _jforcegraphnokey	$5002
#define _jforcegraphkey	$5005
#define _poweroff	$5008
#define _getkeyretoff	$500b ;same as getkey, only returns koff if 2nd+on is pressed
#define _findgroupsym	$500e
#define _fillbasepagetable	$5011
#define _arcchk	$5014
#define _flashtoram	$5017
#define _loaddeindpaged	$501a
#define _loadcindpaged	$501d
#define _setuppagedptr	$5020
#define _pagedget	$5023
#define _setparserhook	$5026
#define _clearparserhook	$5029
#define _setappchangehook 	$502c
#define _clearappchangehook	$502f
#define _enablegraphicshook	$5032
#define _disablegraphicshook	$5035
;$5038
#define _ilinenohook	$503b
;$503e
#define _deletetempprograms	$5041
#define _enablecatalog1ook	$5044
#define _disablecatalog1ook	$5047
#define _enablehelphook	$504a
#define _disablehelphook	$504d
#define _dispcatalogend	$5050
#define _getmenukeypress	$5053
#define _getcatalogitem	$5056
#define _runcatalog2ook	$5059
#define _runcatalog1ook	$505c
;$505f
;$5062
#define _dispmenutitle	$5065
;$5068
#define _enablecxredisphook	$506b
#define _disablecxredisphook	$506e
#define _bufcpy	$5071
#define _bufclr	$5074
#define _unopexec2	$5077
#define _binopexec2	$507a
#define _loadmenub	$507d ;clears screen and loads menu from b, plus a couple flag changes
#define _displayvarinfo	$5080
#define _setmenuhook	$5083
#define _clearmenuhook	$5086
#define _getbcoffsetix	$5089
#define _getbcoffsetix2	$508c
#define _forcefullscreen	$508f
#define _getvariabledata	$5092
#define _findswapsector	$5095
#define _copyflashpage	$5098
#define _findappnumpages	$509b
#define _hlminus5	$509e
#define _sendarcpacket	$50a1
#define _forcegraphkeypress	$50a4
#define _donothing3	$50a7
#define _formbase	$50aa
;$50ad
#define _isfragmented	$50b0
#define _chk_batt_low	$50b3
#define _chk_batt_low_2	$50b6
#define _arc_unarc2	$50b9 ;identical to _arc_unarc, except you can choose to res 0,(iy+$24) to skip low battery check
#define _getappbasepage	$50bc ;input: a=one of an app's pages. output: a=app's first page
#define _setexspeed	$50bf
#define _rclexit	$50c2
#define _groupallvars	$50c5
#define _ungroupvar	$50c8
#define _writetoflash	$50cb ;receiveapplication or something like that on oses below 2.40
#define _setsilentlinkhook	$50ce
#define _disablesilentlinkhook	$50d1
#define _twovarset	$50d4
#define _execclass2token	$50d7
#define _execclass3token	$50da
#define _getsysinfo	$50dd
#define _nzif83plus	$50e0
#define _linkstatus	$50e3
#define _donothing2	$50e6 ;originally for ti-navigator
#define _keyboardgetkey	$50e9
#define _runapplib	$50ec
#define _findspecialappheader	$50ef
#define _sendusbdata	$50f2
#define _appgetcblusb	$50f5
#define _appgetcalcusb	$50f8
#define _getvarcmdusb	$50fb
;$50fe
#define _tenx2	$5101
;$5104
;$5107
#define _getvarversion	$510a
;$510d
;$5110
#define _deletetempeditequ	$5113
#define _jcursorfirst2	$5116
;$5119
;$511c
#define _wputseol2	$511f ;same except res 0,(iy+$0e) first
#define _inverttextinsmode	$5122
;$5125
#define _resetdefaults	$5128
#define _zerofinancevars	$512b
#define _dispheader	$512e
#define _jforcegroup	$5131
;$5134
;$5137
#define _dispcoords	$513a
;$513d
;$5140
;$5143
;$5146
;$5149
;$514c
#define _getdate	$514f
;$5152
#define _getdtfmt	$5155
;$5158
#define _gettime	$515b
;$515e
#define _gettmfmt	$5161
;$5164
#define _setzeroone	$5167
;$516a
#define _isonetwothree	$516d
;$5170
#define _isop112or24	$5173
#define _chktimer0	$5176
;$5179
;$517c
#define _clrwindowandflags	$517f
#define _setmachineid	$5182
#define _resetlists	$5185
;$5188
;$518b
;$518e
#define _execlib	$5191
;$5194
#define _cpop1op2rounded	$5197
#define _cpop1op2rounded2	$519a
#define _openlib	$519d
;$51a0
;$51a3
#define _resetioprompt	$51a6
;$51a9
#define _setupeditor	$51ac
#define _sorta	$51af
#define _sortd	$51b2
;$51b5
#define _isop1resid	$51b8
;$51bb
;$51be
;$51c1
#define _forcemodekeypress	$51c4 ;forces a keypress (and calls help hook) on any of several mode-setting contexts
#define _dispaboutscreen	$51c7
#define _chkhelphookver	$51ca
#define _disp32	$51cd
;$51d0
;$51d3
;$51d6
;$51d9
#define _drawtableeditor	$51dc ;draws table editor lines
;$51df
;$51e2
;$51e5
;$51e8
;$51eb
;$51ee
#define _matrixname	$51f1
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
#define _setupemptyedittempequ	$5212
;$5215
;$5218
;$521b
;$521e
#define _chk_batt_level	$5221
;$5224
;$5227
;$522a
;$522d
;$5230
#define _gotolastrow	$5233
#define _rectborder	$5236
;$5239
;$523c
;$523f
#define _loada5	$5242
;$5245
#define _namedlisttoop1	$5248
;$524b
;$524e
;$5251
#define _initusbdevicecallback	$5254
#define _killusbdevice	$5257
#define _setusbconfiguration	$525a
#define _requestusbdata	$525d
#define _stopreceivingusbdata	$5260
#define _findappheaderbypage	$5263
#define _findnextheaderbypage	$5266
#define _ismatchinglaunchapp	$5269
#define _inittimer	$526c
#define _killtimer	$526f
#define _starttimer	$5272
#define _restarttimer	$5275
#define _stoptimer	$5278
#define _waittimer	$527b
#define _checktimer	$527e
#define _checktimerrestart	$5281
#define _setvertgraphactive	$5284
#define _clearvertgraphactive	$5287
#define _enableusbhook	$528a
#define _disableusbhook	$528d
#define _initusbdevice	$5290
#define _killusbperipheral	$5293
;$5296
;$5299
#define _graphline	$529c
;$529f
;$52a2
;$52a5
;$52a8
;$52ab
;$52ae
#define _ziftableeditor	$52b1
;$52b4
;$52b7
;$52ba
#define _findappname	$52bd
;$52c0
;$52c3
;$52c6
#define _grbufcpycustom	$52c9
;$52cc
;$52cf
;$52d2
#define _vdisprealop1	$52d5
#define _dispxequalsnum	$52d8
#define _resetgraphsettings	$52db
#define _initializevariables	$52de
;$52e1 ;bit 4,($9c75) (this is definitely returning the status of something when acting as a ti-smartview input pad...this bit is bit 1 of the data byte from a pc hid set report request)
#define _delvarsym	$52e4
#define _findappupnocase	$52e7
#define _findappdnnocase	$52ea
#define _deleteinvalidapps	$52ed
#define _deleteapp_link	$52f0
#define _cmpsymsnocase	$52f3
#define _setapprestrictions	$52f6
#define _removeapprestrictions	$52f9
#define _queryapprestrictions	$52fc
#define _dispapprestrictions	$52ff
#define _setuphome	$5302
#define _grputawayfull	$5305 ;same as _grputaway except it assumes no split screen
#define _sendsmartpadkeypress	$5308 ;b and a are the inputs
#define _toggleusbsmartpadinput	$530b ;a is input, 0 or 1 to enable/disable
#define _isusbdeviceconnected	$530e ;bit 4,($81) \ ret, this is just a guess on its purpose but it seems to work
#define _clearusbcallback2	$5311 ;identical to $5257
#define _polarequtoop1	$5314
#define _paramxequtoop1	$5317
#define _paramyequtoop1	$531a
#define _getrestrictionsoptions	$531d
#define _dispresetcomplete	$5320
#define _pttreset	$5323
#define _findappcustom	$5326
#define _cleargraphstyles	$5329

;page $1f rom calls
;--------------------------------
#define bootbtf	$8000
;$400f may point to version string ("1.02 ",0)
#define _md5final	$8018
#define _rsavalidate	$801b
#define _cmpstr	$801e ;bignumcompare
#define _writeabyte	$8021
#define _eraseflash	$8024
#define _findfirstcertfield	$8027
#define _zerotocertificate	$802a
#define _getcertificateend	$802d
#define _findgroupedfield	$8030
#define _ret_1	$8033
#define _ret_2	$8036
#define _ret_3	$8039
#define _ret_4	$803c
#define _ret_5	$803f
#define _mult8by8	$8042
#define _mult16by8	$8045
#define _div16by8	$8048
#define _div16by16	$804b
;$804e ;scary certificate reading and writing, something about calc id and fields $0a10/$0a20
#define _loadaindpaged	$8051
#define _flashtoram2	$8054
#define _getcertificatestart	$8057
#define _getfieldsize	$805a
#define _findsubfield	$805d
#define _erasecertificatesector	$8060
#define _checkheaderkey	$8063
;$8066 ;just returns z if specified data in field $0310, subfield $0610 exists, de points to data of that field you want to find
;$8069 ;just returns number of $0810/$0710 fields that exist in certificate or something, in ix
#define _load_lfontv2	$806c
#define _load_lfontv	$806f
#define _receiveos	$8072
#define _findosheadersubfield	$8075
#define _findnextcertfield	$8078
#define _getbyteorboot	$807b
#define _getserial	$807e ;getcalcserial
#define _receivecalcid	$8081 ;receives certificate replacement (including calculator id, fails if already exists) and writes it, requires flash unlocked
#define _eraseflashpage	$8084
#define _writeflashunsafe	$8087
#define _dispbootver	$808a
#define _md5init	$808d
#define _md5update	$8090
#define _markosinvalid	$8093
#define _findprogramlicense	$8096 ;copies $8010 field to appid and other insane stuff that makes zero sense
#define _markosvalid	$8099
#define _checkosvalidated	$809c
#define _setupapppubkey	$809f
#define _sigmodr	$80a2
#define _transformhash	$80a5
#define _isappfreeware	$80a8
#define _findappheadersubfield	$80ab
#define _writevalidationnumber	$80ae ;generates two-byte validation number from calc id and stores to certificate
#define _div32by16	$80b1
#define _findgroup	$80b4 ;searches until field of de-like group is found (de=$0a00, it stops when it finds $0ax0)
#define _getbootver	$80b7
#define _gethardwareversion	$80ba
#define _xora	$80bd ;xor a
#define _bignumpowermod17	$80c0
#define _prodnrpart1	$80c3
#define _writeabytesafe	$80c6
#define _writeflash	$80c9
#define _setupdatestamppubkey	$80cc
#define _setflashlowerbound	$80cf
#define _lowbatteryboot	$80d2
;ti-84 plus/silver edition only entry points
#define _attemptusbosreceive	$80e4 ;z to wait for usb cable insert & get os, nz and a= contents of port $4d or $56, on to cancel & clear ram
#define _displaybootmessage	$80e7
#define _newline2	$80ea
#define _displaybooterror10	$80ed
#define _chk_batt_low_b	$80f0
#define _chk_batt_low_b2	$80f3
#define _receiveos_usb	$80f6
#define _displayosprogress	$80f9
#define _resetcalc	$80fc
#define _setupospubkey	$80ff
#define _checkheaderkeyhl	$8102 ;same as _checkheaderkey, only you pass the address of header in hl, not at appdata
#define _usberrorcleanup	$8105 ;kills some usb stuff (doesn't completely kill periph communication), error handler in boot code
#define _initusb	$8108 ;initializes usb hardware as peripheral, sets 5,(iy+$1b), c set if problems
;$810b set 1,($81) and wait (has something to do with usb peripheral kill, but it doesn't actually kill it)
#define _killusb	$810e ;identical to $8105, except in the middle of the outputs, it sends zero to port $4c
#define _displaybooterror1	$8111
#define _displaybooterror2	$8114
#define _displaybooterror3	$8117
#define _displaybooterror4	$811a
#define _displaybooterror5	$811d
#define _displaybooterror6	$8120
#define _displaybooterror7	$8123
#define _displaybooterror8	$8126
#define _displaybooterror9	$8129

;ram equates
;--------------------------------
#define ramstart	$8000
#define appdata	$8000
#define ramcode	$8100
#define smalleditcolumnleft	$8177
#define smalleditrow	$8178
#define smalleditcolumnright	$8179
;pencol left edge?	$817b
#define biginteger1	$8182
#define smalleditcancelparse	$8194
#define smalleditrowcount	$81b7
#define biginteger2	$81c3
#define smalleditpromptstring	$81cc
#define ramcodeend	$822f
#define baseappbrtab	$8230 ;table of base pages for apps on page < 20 (starts with eight zeroes because they're os pages)
#define clockflag	$8230 ;bit 2 set for 24-hour mode and don't display "am/pm"
#define clockids	$8231 ;five bytes, numbers 0-4 in memory, that when present, stops displaying clock numbers in time setting context?
#define boottemp	$8251
#define md5temp	$8259
#define md5length	$8269
#define md5ash	$8292
#define appsearchpage	$82a3
#define tempswaparea	$82a5
;something	$837 ;18 bytes, probably indicates something about flash app pages, start out as $ff
#define appid	$838d
#define arcpageend	$8392
#define arcptrend	$8393
;$839f something...field size bytes?
#define md5buffer	$83a5
#define abackup	$83eb
#define ramreturndata	$83ed
#define arcinfo	$83ee
#define savedarcinfo	$8406
#define appinfo	$8432
#define appbank_jump	$843c
#define apppage	$843e
#define kbdscancode	$843f
#define kbdkey	$8444
#define kbdgetky	$8445
#define keyextend	$8446
#define extecho	$keyextend
#define contrast	$8447
#define apdsubtimer	$8448
#define apdtimer	$8449
#define curtime	$844a
#define currow	$844b
#define curcol	$844c
#define curoffset	$844d
#define curunder	$844e
#define cury	$844f
#define curtype	$8450
#define curxrow	$8451
#define prevddata	$8452
#define lfont_record	$845a
#define sfont_record	$8462
#define tokvarptr	$846a
#define toklen	$846c
#define indicmem	$846e ;eight bytes used by _savetr and _restoretr to store image in top right corner
#define indiccounter	$8476
#define indicbusy	$8477
#define op1	$8478
#define op1m	$847a
#define op2	$8483
#define op2m	$8485
#define op2ext	$848c
#define op3	$848e
#define op3m	$8490
#define op4	$8499
#define op4m	$849b
#define op5	$84a4
#define op5m	$84a6
#define op6	$84af
#define op6m	$84b1
#define op6ext	$84b8
#define progtoedit	$84bf
#define namebuff	$84c7
#define equ_edit_save	$84d2
#define imathptr1	$84d3
#define imathptr2	$84d5
#define imathptr3	$84d7
#define imathptr4	$84d9
#define imathptr5	$84db
#define chkdelptr1	$84dd
#define chkdelptr2	$84df
#define insdelptr	$84e1
#define updownptr	$84e3
#define foutdat	$84e5
#define asm_data_ptr1	$84eb
#define asm_data_ptr2	$84ed
#define asm_sym_ptr1	$84ef
#define asm_sym_ptr2	$84f1
#define asm_ram	$84f3
#define asm_ind_call	$8507
#define textshadow	$8508
#define textshadcur	$8588
#define textshadtop	$858a
#define textshadalph	$858b
#define textshadins	$858c
#define cxmain	$858d
#define cxpputaway	$858f
#define cxputaway	$8591
#define cxerrorep	$8595
#define cxsizewind	$8597
#define cxpage	$8599
#define cxcurapp	$859a
#define cxprev	$859b ;12 bytes are shadows of cxmain through cxcurapp and appflags
#define monqh	$85aa
#define monqt	$85ab
#define monqueue	$85ac
#define onsp	$85bc
#define promptrow	$85c0
#define promptcol	$85c1
#define promptins	$85c2
#define promptshift	$85c3
#define promptret	$85c4
#define promptvalid	$85c6
#define prompttop	$85c8
#define promptcursor	$85ca
#define prompttail	$85cc
#define promptbtm	$85ce
#define vartype	$85d0
#define varcurrent	$85d1
#define varclass	$85d9
#define catalogcurrent	$85da ;word at this location starting with $6007 corresponds to what is highlighted in catalog
#define menuactive	$85dc
#define menuappdepth	$85dd
#define menucurrent	$85de
;$85df ;holds current submenu index
;$85e0 ;holds currently selected item in current submenu
;$85e1 ;holds number of submenus for this menu
;$85e2 ;holds number of items in this submenu
;$85e3 ;iy+appflags backup for menu stuff
;$85e4 ;iy+$0c backup for menu stuff
;$85e5 ;curgstyle backup for menu stuff
;$85e6 ;iy+graphflags backup for menu stuff
#define progcurrent	$85e8
;something, op1 backup?	$85f2 ;type and name of topmost variable on menu with names
;something	$85fd
#define usermenusa	$85fe
#define ioprompt	$865f
#define dimagewidth	$8660
#define ioflag	$8670
#define sndrecstate	$8672
#define ioerrstate	$8673
#define header	$8674
#define iodata	$867d
#define ionewdata	$8689
#define bakheader	$868b
;something	$8697 ;app bitmap for selecting stuff from menus
;something	$86b7 ;used in $47 and $74 link packets
#define pencol	$86d7
#define penrow	$86d8
#define rclqueue	$86d9
#define rclqueueend	$86db
#define errno	$86dd
#define errsp	$86de
#define erroffset	$86e0
#define savesscreen	$86ec
#define asm_prgm_size	$89ec
#define bstcounter	$89ee
#define flags	$89f0
#define appflagsaddr	$89fd
;something	$8a36 ;stats-related? this gets stored to (varcurrent) for some reason
#define statvars	$8a3a
#define anovaf_vars	$8c17
#define infvars	$8c4d
#define infvar1	$8c56
#define infvar2	$8c5f
#define infvar3	$8c68
#define infvar4	$8c71
#define infvar5	$8c7a
#define infvar6	$8c83
#define infvar7	$8c8c
#define infvar8	$8c95
#define infvar9	$8c9e
#define infvar10	$8ca7
#define infvar11	$8cb0
#define infvar12	$8cb9
#define infvar13	$8cc2
#define infvar14	$8ccb
#define infvar15	$8cd4
#define infvar16	$8cdd
#define infvar17	$8ce6
#define infvar18	$8cef
#define infvar19	$8cf8
#define infvar20	$8d01
;something	$8d0b
;list-related stat vars	$8d0d
#define curgstyle	$8d17
#define curgy	$8d18
#define curgx	$8d19
#define curgy2	$8d1a
#define curgx2	$8d1b ;currently selected equation while graphing
#define freesavey	$8d1c
#define freesavex	$8d1d
;100 bytes	$8d2a
#define xoffset	$8da1
#define yoffset	$8da2
#define lcdtallp	$8da3
#define pixwidep	$8da4
#define pixwide_m_1	$8da5
#define pixwide_m_2	$8da6
#define lastentryptr	$8da7 ;pointer to the next available byte in the entry stack
#define lastentrystk	$8da9 ;the start of entry stack (note last entry is not in the stack, it is in the program '#'.)  this is a stack of strings.  first 2 bytes are length, followed by string. 2nd from last entry is first in this stack.
#define numlastentries	$8e29 ;number of entries you can back-track through minus one
#define currlastentry	$8e2a ;counter used by os to keep track of which entry was just displayed by pressing 2nd+enter
;something	$8e65
;something	$8e66
#define curinc	$8e67
#define uxmin	$8e7e
#define uxmax	$8e87
#define uxscl	$8e90
#define uymin	$8e99
#define uymax	$8ea2
#define uyscl	$8eab
#define uthetmin	$8eb4
#define uthetmax	$8ebd
#define uthetstep	$8ec6
#define utmin	$8ecf
#define utmax	$8ed8
#define utstep	$8ee1
#define uplotstart	$8eea
#define unmax	$8ef3
#define uu0	$8efc
#define uv0	$8f05
#define unmin	$8f0e
#define uu02	$8f17
#define uv02	$8f20
#define uw0	$8f29
#define uplotstep	$8f32
#define uxres	$8f3b
#define uw02	$8f44
#define xmin	$8f50
#define xmax	$8f59
#define xscl	$8f62
#define ymin	$8f6b
#define ymax	$8f74
#define yscl	$8f7d
#define thetamin	$8f86
#define thetamax	$8f8f
#define thetastep	$8f98
#define tminpar	$8fa1
#define tmaxpar	$8faa
#define tstep	$8fb3
#define plotstart	$8fbc
#define nmax	$8fc5
#define u0	$8fce
#define v0	$8fd7
#define nmin	$8fe0
#define u02	$8fe9
#define v02	$8ff2
#define w0	$8ffb
#define plotstep	$9004
#define xreso	$900d
#define w02	$9016
#define un1	$901f
#define un2	$9028
#define vn1	$9031
#define vn2	$903a
#define wn1	$9043
#define wn2	$904c
#define fin_n	$9055
#define fin_i	$905e
#define fin_pv	$9067
#define fin_pmt	$9070
#define fin_fv	$9079
#define fin_py	$9082
#define fin_cy	$908b
#define cal_n	$9094
#define cal_i	$909d
#define cal_pv	$90a6
#define cal_pmt	$90af
#define cal_fv	$90b8
#define cal_py	$90c1
#define smalleditram	$90d3
#define xfact	$913f
#define yfact	$9148
#define xres_int	$9151
#define deltax	$9152
#define deltay	$915b
#define shortx	$9164
#define shorty	$916d
#define lower	$9176
#define upper	$917f
#define xoutsym	$918c
#define xoutdat	$918e
#define youtsym	$9190
#define youtdat	$9192
#define inputsym	$9194
#define inputdat	$9196
#define prevdata	$9198
;something	$91d9
;something	$91da
#define curtablerow	$91dc
#define curtablecol	$91dd
#define tblmin	$92b3
#define tblstep	$92bc
;something	$92c5
;something	$92c6
;someplotthing1	$92d9
;someplotthing2	$92ea
;someplotthing3	$92fb
#define es	$9302 ;bottom of the es
#define est	$9305 ;current height of the es
;something	$9311 ;this is the pointer to a table of stuff for a basic menu
#define plotsscreen	$9340
#define seed1	$9640
#define seed2	$9649
#define basic_prog	$9652
#define basic_start	$965b
#define nextparsebyte	$965d ;basic_pc
#define basic_end	$965f
#define numarguments	$9661
;something	$9665 ;parser-related word
;something	$966c
;something	$966d
#define cmdshadow	$966e
#define cmdshadcur	$96ee
#define cmdshadalph	$96f0
#define cmdshadins	$96f1
#define cmdcursor	$96f2
#define edittop	$96f4
#define editcursor	$96f6
#define edittail	$96f8
#define editbtm	$96fa
;something	$9700
#define editsym	$9706 ;pointer to symbol table entry of variable being edited
#define editdat	$9708 ;pointer to data of variable being edited
;something	$970e ;stats/list editor related, usually 1
;something	$970f ;stats/list editor related, usually 0
;something	$9710 ;stats/list editor related, usually 0
#define listname1	$9711
#define listname2	$9716
#define listname3	$971b
#define listname4	$9720
#define listname5	$9725
#define listname6	$972a
#define listname7	$972f
#define listname8	$9734
#define listname9	$9739
#define listname10	$973e
#define listname11	$9743
#define listname12	$9748
#define listname13	$974d
#define listname14	$9752
#define listname15	$9757
#define listname16	$975c
#define listname17	$9761
#define listname18	$9766
#define listname19	$976b
#define listname20	$9770
;something	$9775
#define y1linetype	$9776 ;these bytes define the line type for functions which are graphed
#define y2linetype	$9777
#define y3linetype	$9778
#define y4linetype	$9779
#define y5linetype	$977a
#define y6linetype	$977b
#define y7linetype	$977c
#define y8linetype	$977d
#define y9linetype	$977e
#define y0linetype	$977f
#define para1linetype	$9780
#define para2linetype	$9781
#define para3linetype	$9782
#define para4linetype	$9783
#define para5linetype	$9784
#define para6linetype	$9785
#define polar1linetype	$9786
#define polar2linetype	$9787
#define polar3linetype	$9788
#define polar4linetype	$9789
#define polar5linetype	$978a
#define polar6linetype	$978b
#define seculinetype	$978c
#define secvlinetype	$978d
#define secwlinetype	$978e
;something	$979f
;something	$97a1
#define wintop	$97a5
#define winbtm	$97a6
#define winleftedge	$97a7
#define winleft	$97a8
#define winabove	$97aa
#define winrow	$97ac
#define wincol	$97ae
#define fmtdigits	$97b0
#define fmtstring	$97b1
#define fmtconv	$97f2
#define fmtleft	$9804
#define fmtindex	$9806
#define fmtmatsym	$9808
#define fmtmatmem	$980a
#define eqs	$980c
;something	$980e
;something	$9810
#define freeram	$9815 ;pretty sure this is the amount of ram free, valid in mem mgmt/del anyway
;something	$9817
#define tsymptr1	$9818
#define tsymptr2	$981a
#define chkdelptr3	$981c
#define chkdelptr4	$981e
#define tempmem	$9820
#define fpbase	$9822
#define fps	$9824
#define opbase	$9826
#define ops	$9828
#define ptempcnt	$982a
#define cleantmp	$982c
#define ptemp	$982e ;end of symbol table
#define progptr	$9830
#define newdataptr	$9832
#define pagedcount	$9834
#define pagedpn	$9835
#define pagedgetptr	$9836
#define pagedputptr	$9838
#define pagedbuf	$983a
;something	$984a ;this is the top lcd row for a menu (usually 1)
#define apperr1	$984d
#define apperr2	$985a
#define flashbyte1	$9867
#define flashbyte2	$9868
#define freearcblock	$9869
#define arcpage	$986b
#define arcptr	$986c
#define apprawkeyhandle	$9870
#define appbackupscreen	$9872
#define customheight	$9b72
#define locallanguage	$9b73
#define hookexectemp	$9b75
#define linkactivityhook	$9b78
#define cursorhookptr	$9b7c
#define libraryhookptr	$9b80
#define rawkeyhookptr	$9b84
#define getkeyhookptr	$9b88
#define homescreenhookptr	$9b8c
#define windowhookptr	$9b90
#define graphhookptr	$9b94
#define yequalshookptr	$9b98
#define fonthookptr	$9b9c
#define regraphhookptr	$9ba0
#define graphicshook	$9ba4
#define tracehookptr	$9ba8
#define parserhookptr	$9bac
#define appchangehookptr	$9bb0
#define catalog1ookptr	$9bb4
#define helphookptr	$9bb8
#define cxredisphookptr	$9bbc
#define menuhookptr	$9bc0
#define catalog2ookptr	$9bc4
#define tokenhookptr	$9bc8
#define localizehookptr	$9bcc
#define silentlinkhookptr	$9bd0 ;restartclr?
#define usbactivityhookptr	$9bd4
#define baseappbrtab2	$9c06 ;table of base pages for apps on page >= 20; first 20 bytes are zeroes.
#define usbcallbackpage	$9c13
#define usbcallbackptr	$9c14
#define vendorid	$9c16
#define productid	$9c18
#define devreleasenumber	$9c1a
#define oldsespeed	$9c21
#define calcperipheralstate	$9c26
#define usb_datawaitingcount	$9c27
#define basepagetable2end	$9c6f ;this is the last page
#define port91temp	$9c79
#define usb_dataexpectcount	$9c80
#define offpagecallpage	$9c83 ;temporarily stores off-page page and address
#define offpagecalladdress	$9c84
;something	$9c86 ;used with se link activity, values of $00, $0fa, $0ff probably mean something
;something	$9c87 ;zero this to force the apps menu to recache itself (this is always either 0, 1, or last app page, for some reason)
;something	$9c88 ;don't know, but it's 14 bytes and has to do with selecting stuff (if $9c87 is non-zero, this is zeroed out)
;something	$9c9e ;funky, this actually gets written to the certificate on non-83+ (11 bytes)
#define sespeed	$9cae
;something, table index	$9caf
;something	$9cb0
;something	$9cb1 ;table
;something	$9ccd
#define localtokstr	$9d65
#define keyforstr	$9d76
#define keytostrram	$9d77
#define sedmonsp	$9d88
#define bpsave	$9d8a
#define usermem	$9d95
#define symtable	$0fe66

;system flags
;----------------------------------------------------------------------
#define iodelflag	0
#define indelete	0	;1 = delete screen

#define trigflags	0	;trigonometry mode settings
#define trigdeg	2	;1=degrees, 0=radians

#define kbdflags	0	;keyboard scan
#define kbdscr	3	;1=scan code ready
#define kbdkeypress	4	;1=key has been pressed

#define doneflags	0	;display "done"
#define doneprgm	5	;1=display "done" after prgm
;----------------------------------------------------------------------
#define editflags	1
#define editopen	2	;1=edit buffer is open

#define ansflags	1
#define ansscroll	3	;1=answer can scroll, seems must be reset in order to move about edit buffer

#define monflags	1	 ;monitor flags
#define monabandon	4	;1=don't start any long process in put away (#715)
;----------------------------------------------------------------------
#define plotflags	2	;plot generation flags
#define plotloc 	1	;0=bkup & display, 1=display only
#define plotdisp	2	;1=plot is in display, 0=text in display

#define grfmodeflags	2	;graph mode settings
#define grffuncm	4	;1=function grap
#define grfpolarm	5	;1=polar grap
#define grfparamm	6	;1=parametric grap
#define grfrecurm	7	;1=recursion grap
;----------------------------------------------------------------------
#define graphflags	3
#define graphdraw	0	;0=graph is valid, 1=redraw graph(dirty)
#define graphcursor	2
;----------------------------------------------------------------------
#define grfdbflags	4
#define grfdot	0	;0=line, 1=dot
#define grfsimul	1	;0=sequential, 1=simultaneous
#define grfgrid 	2	;0=no grid, 1=grid
#define grfpolar	3	;0=rectangular, 1=polar coordinates
#define grfnocoord	4	;0=display coordinates, 1=off
#define grfnoaxis	5	;0=axis, 1=no axis
#define grflabel	6	;0=off, 1=axis label
;----------------------------------------------------------------------
#define textflags	5	;text output flags
#define texterasebelow	1	;1=erase line below small char
#define textscrolled	2	;1=screen scrolled
#define textinverse	3	;1=display inverse bit-map
#define textinsmode	4	;0=overstrike, 1=insert mode
;----------------------------------------------------------------------
#define parsflag	6	;parser flags
;----------------------------------------------------------------------
#define parsflag2	7	;parser flags
#define numop1	0	;1=result in op1, 0=no result
;----------------------------------------------------------------------
#define newdispf	8	;derivative mode flags
#define preclrformode	0	;1=help blink on mode screen
#define allowprogtokens	1	;1=allow programming tokens to be parsed in basic programs

#define apdflags	8	;automatic power-down
#define apdable 	2	;1=apd enabled
#define apdrunning	3	;1=apd clock running
;----------------------------------------------------------------------
#define web_err_mask	$60
;----------------------------------------------------------------------
#define onflags 	9	;on key flags
#define parseinput	1	;1=parse input when done
#define onrunning	3	;1=calculator is running
#define oninterrupt	4	;1=on key interrupt request

#define statflags	9	;statistics flags
;unknown	5	;unknown
#define statsvalid	6	;1=stats are valid
;----------------------------------------------------------------------
#define fmtflags	$0a	;numeric format flags
#define fmtexponent	0	 	;1=show exponent, 0=no exponent
#define fmteng	1	 	;1=engineering notion, 0=scientific
#define fmthex	2	 	;1=hexadecimal
#define fmtoct	3	 	;1=octal
#define fmtbin	4	 	;1=binary

#define nummode	$0a
#define fmtreal	5
#define fmtrect	6
#define fmtpolar	7

#define realmode	5
#define rectmode	6
#define polarmode	7
;			;if hex and oct both = 1
;			; then bin=0 means >frac
;			; bin=1 means >dms
#define fmtbasemask	 %00011100	; mask to base flags
#define fmtbaseshift	 2	; offset to base flags
;
;       check if these are used by numform,
;
;           	 6
;           	 7
;----------------------------------------------------------------------
#define fmtoverride	$0b	;copy of fmtflags with conversion override
;----------------------------------------------------------------------
#define fmteditflags	$0c	;numeric editing flags
#define fmtedit	0	;1=format number for editing

#define curflags	$0c	;cursor
#define curable 	2	;1=cursor flash is enabled
#define curon	3	;1=cursor is showing
#define curlock 	4	;1=cursor is locked off

#define cmdflags	$0c	;command editor flags
#define cmdvirgin	5	;1=nothing has been typed in cmd bfr
;----------------------------------------------------------------------
#define appflags	$0d	;application flags
#define appwantintrpt	0	;1=want on key interrupts
#define apptextsave	1	;1=save characters in textshadow
#define appautoscroll	2	;1=auto-scroll text on last line
#define appmenus	3	;1=process keys that bring up menus, 0=check lock menu flag
#define applockmenus	4	;1=ignore menu keys, 0=switch to home screen and bring up menu
#define appcurgraphic	5	;1=graphic cursor
#define appcurword	6	;1=text cursor covers entire word
#define appexit 	7	;1=application handles [exit] key itself

#define appwantintrptf	1<<appwantintrpt
#define apptextsavef	1<<apptextsave
#define appautoscrollf	1<<appautoscroll
#define appmenusf	1<<appmenus
#define applockmenusf	1<<applockmenus
#define appcurgraphicf	1<<appcurgraphic
#define appcurwordf	1<<appcurword
#define appexitf	1<<appexit
;----------------------------------------------------------------------
#define rclflag	$0e	;os recall queue flags
#define enablequeue	7	;1 = enable recall queue
;----------------------------------------------------------------------
#define seqflags	$0f	;sequential graph flags
#define webmode	0	;0 = normal seq mode, 1 = web mode
#define webvert	1
#define sequv	2	;u vs v
#define seqvw	3	;v vs w
#define sequw	4	;u vs w
;----------------------------------------------------------------------
#define promptflags	$11	;prompt line flags
#define promptedit	0	;1=editing in prompt buffer
;----------------------------------------------------------------------
#define indicflags	$12	;indicator flags
#define indicrun	0	;1=run indicator on
#define indicinuse	1	;indicator save area in use=1, free=0 ;resetting will disable 2nd while in _getkey
#define indiconly	2	;interrupt handler only checks run indicator

#define shiftflags	$12	;[2nd] and [alpha] flags
#define shift2nd	3	;1=[2nd] has been pressed
#define shiftalpha	4	;1=[alpha] has been pressed
#define shiftlwralph	5	;1=lower case, 0=upper case
#define shiftalock	6	;1=alpha lock has been pressed
#define shiftkeepalph	7	;1=cannot cancel alpha shift
;----------------------------------------------------------------------
#define tblflags	$13	;table flags.
#define autofill	4	;1=prompt, 0=fillauto
#define autocalc	5	;1=prompt, 0=calcauto
#define retable	6	;0=table is okay, 1=must recompute table.
;----------------------------------------------------------------------
#define sgrflags	$14
#define grfsplit	0	;1=split graph, 0=normal
#define vertsplit	1	;1=vertical (left-right) split
#define grfschanged	2	;1=graph just changed split <-> normal
#define grfsplitoverride	3	;1 = ignore graph split flag if set
#define write_on_graph	4	;1 = text or	writing to graph screen
#define g_style_active	5	;1 = graph styles are enabled, use them
#define cmp_mod_box	6	;1 = doing mod box plot computation
#define textwrite	7
;----------------------------------------------------------------------
#define newindicflags	$15
#define extraindic	0
#define saindic	1
;----------------------------------------------------------------------
#define batteryflags	$16
#define batteriesgood	2	;1 = batteries good
;----------------------------------------------------------------------
#define smartflags	$17
#define smarter_mask	3
#define smarter_test	1
#define smartgraph	0
#define smartgraph_inv	1
;----------------------------------------------------------------------
#define traceflags	$18
#define grfexpr	0	;set to hide expression while tracing
;----------------------------------------------------------------------
#define statflags2	$1a
#define statdiagnosticson	0	;1 = stat diagnostics on
;----------------------------------------------------------------------
#define linkflags	$1b
#define idis95	1	;link routines use machine id 95 (cbl)
#define idis82	2	;link routines use machine id 82 (ti-82)
#define idis83	3	;link routines use machine id 83 (ti-83)
#define idis03	4	;link routines use machine id 03 (pc to ti-83)
#define usbenabled	5	;use usb port first, or at least try to
;----------------------------------------------------------------------
;there is a flag $1c (stats-related).
;----------------------------------------------------------------------
;there is a flag $1e.
;----------------------------------------------------------------------
#define vartypemask	$1f	;is this a flag byte? yes
#define vargraphref	6
;----------------------------------------------------------------------
#define graphflags2	$1f
#define splitoverride	3	;0 = force full screen with parseinp, or something
;----------------------------------------------------------------------
#define asm_flag1	$21	;asm coding
#define asm_flag2	$22	;asm coding
#define asm_flag3	$23	;asm coding
;----------------------------------------------------------------------
#define arcflag	$24
#define checkbatterylevelfirst	0	;1 = check battery levels in arc_unarc first and throw error if low

#define getsendflg	$24
#define comfailed	1	;1 = get/send communication failed

#define selftestflag	$24
#define resetonpoweron	2	;1 = force ram reset when apd disabled on next power on

#define applwrcaseflag	$24
#define lwrcaseactive	3
;----------------------------------------------------------------------
#define contextflags	$25
#define nocxputaway	5	;1 = do not call cxputaway routine
;----------------------------------------------------------------------
#define groupflags	$26 ;used temporarily in arc_unarc
#define ingroup	1	;1 = in group context
#define nocompletionbyte	2	;1 = do not write 0fch when calling arc_unarc, leave as 0fe
#define nodatawrite	3	;1 = do not write data when calling arc_unarc, nor size bytes
#define writesizebytesonly	5	;1 = only write size bytes when calling arc_unarc
;----------------------------------------------------------------------
#define apiflg	$28
#define appallowcontext	0           ;app wants context changes to happen
;1 set to ignore a key after returning from rawkeyhook
;2 set to send this key back?
;3
#define apprunning	4	;app is currently running
;5
;6
#define appretkeyoff	7	;1 = getkey returns koff when [2nd]+[on] pressed
;----------------------------------------------------------------------
#define apiflg2	$29
;----------------------------------------------------------------------
#define apiflg3	$2a
;1 set means using small font?
;----------------------------------------------------------------------
#define apiflg4	$2b
#define celloverride	1	;use cell override
#define fullscrndraw	2	;draw into last row/col of screen
;----------------------------------------------------------------------
#define mouseflag1	$2c
;----------------------------------------------------------------------
#define mouseflag2	$2d ;might want to keep this always reset.
;----------------------------------------------------------------------
#define xapflag0	$2e	;external app flags
#define xapflag1	$2f
#define xapflag2	$30
#define xapflag3	$31
;----------------------------------------------------------------------
#define fontflags	$32
#define fracdrawlfont	2
#define fractalllfont	3
#define customfont	7
;----------------------------------------------------------------------
#define hookflags1	$33 ;also scriptflag, rclflag2, backgroundlink
#define alt_on	0	;run onscrpt at startup
#define alt_off	1	;run offscrpt at shutdown
#define userclqueueend	2	;1 = external mode
#define ignorebplink	3	;1 = override flag for link activity hook
#define bplinkon	4	;1 = link activity hook active
#define notempdelete	6	;1 = do not delete temporary programs at homescreen
;----------------------------------------------------------------------
#define hookflags2	$34 ;also syshookflg
#define getcschookactive	0	;1 = getcsc hook active
#define libraryhookactive	1	;1 = library hook active
#define homescreenhookactive	4	;1 = homescreen hook active
#define rawkeyhookactive	5	;1 = raw key hook active
#define catalog2ookactive	6	;1 = catalog 2 hook active
#define cursorhookactive	7	;1 = cursor hook active
;----------------------------------------------------------------------
#define hookflags3	$35 ;also syshookflg1
#define tokenhookactive	0	;1 = token hook active
#define localizehookactive	1	;1 = localize hook active
#define windowhookactive	2	;1 = window hook active
#define graphhookactive	3	;1 = graph hook active
#define yequhookactive	4	;1 = y= hook active
#define fonthookactive	5	;1 = font hook active
#define regraphhookactive	6	;1 = regraph hook active
#define drawinghookactive	7	;1 = drawing hook active
;----------------------------------------------------------------------
#define hookflags4	$36 ;also syshookflag2
#define tracehookactive	0	;1 = trace hook active
#define parserhookactive	1	;1 = parser hook active
#define appchangehookactive	2	;1 = app change hook active
#define catalog1ookactive	3	;1 = catalog 1 hook active
#define helphookactive	4	;1 = help hook active
#define cxredisphookactive	5	;1 = cxredisp hook active
#define menuhookactive	6	;1 = menu hook active
#define silentlinkhookactive	7	;1 = silent link hook active
;----------------------------------------------------------------------
;hookflags2override	$37	;set corresponding bit to kill iy+$35 hook when executing app
;----------------------------------------------------------------------
;hookflags3override	$38	;set corresponding bit to kill iy+$36 hook when executing app
;----------------------------------------------------------------------
;hookflags4override	$39	;set corresponding bit to kill iy+$37 hook when executing app
;----------------------------------------------------------------------
#define plotflag3	$3c
#define bufferonly	0
#define usefastcirc	4
;----------------------------------------------------------------------
#define dbkeyflags	$3d
#define keydefaultsf	6	;1 = getkey returns extended keycodes with ti-keyboard
;----------------------------------------------------------------------
#define clockflags	$3f
#define notmdymode	0	;0 = m/d/y format
#define isymdmode	1	;1 = y/m/d format
#define is24our	2	;1 = clock in 24 hour mode
#define clockon	6	;1 = clock on
;----------------------------------------------------------------------
#define usbflag1	$40
#define usbreceivezone1	2	;1 = receive to ram pages 3/2 ("zone 1")
;----------------------------------------------------------------------
#define usbflag2	$41
;0
;2
#define nousbhostinit	3	;1 = _initspecificusbdevice must fail
#define usbdatawaiting	5
;6
;7
;----------------------------------------------------------------------
;there is a flag $43.
;----------------------------------------------------------------------

;character font equates
;-------------------------------
#define lrecurn	$01
#define lrecuru	$02
#define lrecurv	$03
#define lrecurw	$04
#define lconvert	$05
#define lsqup	$06
#define lsqdown	$07
#define lintegral	$08
#define lcross	$09
#define lboxicon 	$0a
#define lcrossicon 	$0b
#define ldoticon 	$0c
#define lsubt   	$0d ;small capital t for parametric mode.
#define lcuber  	$0e ;slightly different 3 for cubed root.
#define lhexf	$0f
#define lroot	$10
#define linverse	$11
#define lsquare	$12
#define langle	$13
#define ldegree	$14
#define lradian	$15
#define ltranspose	$16
#define lle	$17
#define lne	$18
#define lge	$19
#define lneg	$1a
#define lexponent	$1b
#define lstore	$1c
#define lten	$1d
#define luparrow	$1e
#define ldownarrow	$1f
#define lspace	$20
#define lexclam	$21
#define lquote	$22
#define lpound	$23
#define lfourth	$24
#define lpercent	$25
#define lampersand	$26
#define lapostrophe	$27
#define llparen	$28
#define lrparen	$29
#define lasterisk	$2a
#define lplussign	$2b
#define lcomma	$2c
#define ldash	$2d
#define lperiod	$2e
#define lslash	$2f
#define l0	$30
#define l1	$31
#define l2	$32
#define l3	$33
#define l4	$34
#define l5	$35
#define l6	$36
#define l7	$37
#define l8	$38
#define l9	$39
#define lcolon	$3a
#define lsemicolon	$3b
#define llt	$3c
#define leq	$3d
#define lgt	$3e
#define lquestion	$3f
#define latsign	$40
#define lcapa	$41
#define lcapb	$42
#define lcapc	$43
#define lcapd	$44
#define lcape	$45
#define lcapf	$46
#define lcapg	$47
#define lcaph	$48
#define lcapi	$49
#define lcapj	$4a
#define lcapk	$4b
#define lcapl	$4c
#define lcapm	$4d
#define lcapn	$4e
#define lcapo	$4f
#define lcapp	$50
#define lcapq	$51
#define lcapr	$52
#define lcaps	$53
#define lcapt	$54
#define lcapu	$55
#define lcapv	$56
#define lcapw	$57
#define lcapx	$58
#define lcapy	$59
#define lcapz	$5a
#define ltheta	$5b
#define lbackslash	$5c
#define lrbrack	$5d
#define lcaret	$5e
#define lunderscore	$5f
#define lbackquote	$60
#define la	$61
#define lb	$62
#define lc	$63
#define ld	$64
#define le	$65
#define lf	$66
#define lg	$67
#define lh	$68
#define li	$69
#define lj	$6a
#define lk	$6b
#define ll	$6c
#define lm	$6d
#define ln	$6e
#define lo	$6f
#define lp	$70
#define lq	$71
#define lr	$72
#define ls	$73
#define lt	$74
#define lu	$75
#define lv	$76
#define lw	$77
#define lx	$78
#define ly	$79
#define lz	$7a
#define llbrace	$7b
#define lbar	$7c
#define lrbrace	$7d
#define ltilde	$7e
#define linveq	$7f
#define lsub0	$80
#define lsub1	$81
#define lsub2	$82
#define lsub3	$83
#define lsub4	$84
#define lsub5	$85
#define lsub6	$86
#define lsub7	$87
#define lsub8	$88
#define lsub9	$89
#define lcapaacute	$8a
#define lcapagrave	$8b
#define lcapacaret	$8c
#define lcapadier	$8d
#define laacute	$8e
#define lagrave	$8f
#define lacaret	$90
#define ladier	$91
#define lcapeacute	$92
#define lcapegrave	$93
#define lcapecaret	$94
#define lcapedier	$95
#define leacute	$96
#define legrave	$97
#define lecaret	$98
#define ledier	$99
#define lcapiacute	$9a
#define lcapigrave	$9b
#define lcapicaret	$9c
#define lcapidier	$9d
#define liacute	$9e
#define ligrave	$9f
#define licaret	$a0
#define lidier	$a1
#define lcapoacute	$a2
#define lcapograve	$a3
#define lcapocaret	$a4
#define lcapodier	$a5
#define loacute	$a6
#define lograve	$a7
#define locaret	$a8
#define lodier	$a9
#define lcapuacute	$aa
#define lcapugrave	$ab
#define lcapucaret	$ac
#define lcapudier	$ad
#define luacute	$ae
#define lugrave	$af
#define lucaret	$b0
#define ludier	$b1
#define lcapcced	$b2
#define lcced	$b3
#define lcapntilde	$b4
#define lntilde	$b5
#define laccent	$b6
#define lgrave	$b7
#define ldieresis	$b8
#define lquesdown	$b9
#define lexclamdown	$ba
#define lalpha	$bb
#define lbeta	$bc
#define lgamma	$bd
#define lcapdelta	$be
#define ldelta	$bf
#define lepsilon	$c0
#define llbrack 	$c1
#define llambda	$c2
#define lmu	$c3
#define lpi	$c4
#define lrho	$c5
#define lcapsigma	$c6
#define lsigma	$c7
#define ltau	$c8
#define lphi	$c9
#define lcapomega	$ca
#define lxmean	$cb
#define lymean	$cc
#define lsupx	$cd
#define lellipsis	$ce
#define lleft	$cf
#define lblock	$d0
#define lper	$d1
#define lhyphen	$d2
#define larea	$d3
#define ltemp	$d4
#define lcube	$d5
#define lenter	$d6
#define limagi	$d7
#define lphat	$d8
#define lchi	$d9
#define lstatf	$da
#define llne	$db
#define llistl	$dc
#define lfinann 	$dd
#define l2_r_paren 	$de
#define lblockarrow 	$df
#define lcuro   	$e0
#define lcuro2  	$e1
#define lcurocapa   	$e2
#define lcuroa  	$e3
#define lcuri   	$e4
#define lcuri2  	$e5
#define lcuricapa   	$e6
#define lcuria  	$e7
#define lgline      	$e8 ; = 0
#define lgthick     	$e9 ; = 1
#define lgabove	$ea ; = 2
#define lgbelow	$eb ; = 3
#define lgpath	$ec ; = 4
#define lganimate	$ed ; = 5
#define lgdot	$ee ; = 6
#define lupblk	$ef ;up arrow and block in solver
#define ldnblk	$f0 ;down arrow and block in solver
#define lcurfull	$f1 ;note: must be last char (putmap checks)

;(menucurrent) values
;--------------------------
#define mconfirmation	$01
#define mapps	$02
#define mprogramhome	$03
#define mprgm_run	$00
#define mprgm_edit	$01
#define mprgm_new	$02
#define mzoom	$04
#define mzoom_zoom	$00
#define mzoom_memory	$01
#define mdraw	$05
#define mdraw_draw	$00
#define mdraw_points	$01
#define mdraw_store	$02
#define mstatplots	$06
#define mstat	$07
#define mstat_edit	$00
#define mstat_calc	$01
#define mstat_tests	$02
#define mmath	$08
#define mmath_math	$00
#define mmath_number	$01
#define mmath_complex	$02
#define mmath_prob	$03
#define mtest	$09
#define mtest_test	$00
#define mtest_logic	$01
#define mvars	$0a
#define mvars_vars	$00
#define mvars_yvars	$01
#define mmemory	$0c
#define mmatrix	$0d
#define mmatrix_name	$00
#define mmatrix_math	$01
#define mmatrix_edit	$02
#define mdistr	$0e
#define mdistr_distr	$00
#define mdistr_draw	$01
#define mangle	$0f
#define mlist	$10
#define mlist_names	$00
#define mlist_ops	$01
#define mlist_math	$02
#define mcalculate	$11
#define mvarswin	$14
#define mvarswin_xy	$00
#define mvarswin_tth	$01
#define mvarswin_uvw	$02
#define mvarszoom	$15
#define mvarszoom_zxy	$00
#define mvarszoom_zt	$01
#define mvarszoom_uvw	$02
#define mvarsgdb	$16
#define mvarspics	$17
#define mvarsstrings	$18
#define mvarsstat	$19
#define mvarsstat_xy	$00
#define mvarsstat_sigma	$01
#define mvarsstat_eq	$02
#define mvarsstat_test	$03
#define mvarsstat_pts	$04
#define mvarstable	$1a
#define mvarsyequ	$1b
#define mvarsparametric	$1c
#define mvarspolar	$1d
#define mvarsfnonoff	$1e
#define mmemreset	$1f
#define mmemreset_ram	$00
#define mmemreset_rom	$01
#define mmemreset_all	$02
#define mmemmgmtdel	$20
#define mmemresetdefaults	$21
#define mmemresetramall	$23
#define mmemresetromvars	$24
#define mmemresetromapps	$25
#define mmemresetromall	$26
#define mmemresetall	$27
#define mgroup	$28
#define mgroup_new	$00
#define mgroup_ungroup	$01
#define mgroupvars	$29
#define mprogramedit	$2a
#define mprgmed_ctrl	$00
#define mprgmed_io	$01
#define mprgmed_exec	$02
#define mprgmzoom	$2b
#define mprgmzoom_zoom	$00
#define mprgmzoom_mem	$01
#define mprgmdraw	$2c
#define mprgmdraw_draw	$00
#define mprgmdraw_pt	$01
#define mprgmdraw_store	$02
#define mprgmstatplot	$2d
#define mprgmsp_plots	$00
#define mprgmsp_type	$01
#define mprgmsp_mark	$02
#define mprgmstat	$2e
#define mprgmstat_edit	$00
#define mprgmstat_calc	$01
#define mprgmstat_tests	$02
#define mprgmmath	$2f
#define mprgmmath_math	$00
#define mprgmmath_num	$01
#define mprgmmath_cplx	$02
#define mprgmmath_prob	$03
#define mlink	$30
#define mlink_send	$00
#define mlink_recieve	$01
#define mlinktrasmit	$31
#define mlinkxmit_xmit	$01
#define mgarbagecollect	$3f
#define mselectgroupvars	$40
#define mselgrpvars_sel	$00
#define mselgrpvars_grp	$01
#define mduplicatename	$42
#define mcatalog	$45
#define mfinance	$22
#define mfinance_calc	$00
#define mfinance_vars	$01

;keypress equates
;-------------------------------
#define kright	$01
#define kleft	$02
#define kup	$03
#define kdown	$04
#define kenter	$05
#define kalphaenter	$06
#define kalphaup	$07
#define kalphadown	$08
#define kclear	$09
#define kdel	$0a
#define kins	$0b
#define krecall	$0c
#define klastent	$0d
#define kbol	$0e
#define keol	$0f

#define kselall	$10
#define kunselall	$11
#define kltoti82	$12
#define kbackup	$13
#define krecieve	$14
#define klnkquit	$15
#define ktrans	$16
#define krename	$17
#define koverw	$18
#define komit	$19
#define kcont	$1a
#define ksendid	$1b
#define ksendsw	$1c
#define kyes	$1d
#define knoway	$1e
#define kvsendtype	$1f
#define koverwall	$20
#define kno	$25
#define kkreset	$26
#define kapp	$27
#define kdoug	$28
#define klistflag	$29
#define menustart	$2b
#define kareyousure	$2b
#define kappsmenu	$2c
#define kprgm	$2d
#define kzoom	$2e
#define kdraw	$2f
#define ksplot	$30
#define kstat	$31
#define kmath	$32
#define ktest	$33
#define kchar	$34
#define kvars	$35
#define kmem	$36
#define kmatrix	$37
#define kdist	$38
#define kangle	$39
#define klist	$3a
#define kcalc	$3b
#define kfin	$3c
#define menuend	$kfin
#define kcatalog	$3e
#define kinputdone	$3f
#define koff	$kinputdone
#define kquit	$40
#define appstart	$kquit
#define klinkio	$41
#define kmatrixed	$42
#define kstated	$43
#define kgraph	$44
#define kmode	$45
#define kprgmed	$46 ;program edit
#define kprgmcr	$47 ;program create
#define kwindow	$48 ;range editor
#define kyequ	$49 ;equation editor
#define ktable	$4a ;table editor
#define ktblset	$4b ;table set
#define kchkram	$4c ;check ram (about screen)
#define kdelmem	$4d ;delete mem
#define kresetmem	$4e ;reset mem
#define kresetdef	$4f ;reset default
#define kprgminput	$50 ;program input
#define kzfacted	$51 ;zoom factor editor
#define kerror	$52 ;error
#define ksolvetvm	$53 ;tvm solver
#define ksolveroot	$54 ;solve editor
#define kstatp	$55 ;stat plot
#define kinfstat	$56 ;inferential statistic
#define kformat	$57 ;format
#define kextapps	$58 ;external applications.     new
#define knewapps	$59 ;new apps for cerberus.
#define append	$knewapps
#define echostart1	$5a
#define ktrace	$5a
#define kzfit	$5b
#define kzin	$5c
#define kzout	$5d
#define kzprev	$5e
#define kbox	$5f
#define kdecml	$60
#define ksetzm	$61
#define ksquar	$62
#define kstd	$63
#define ktrig	$64
#define kusrzm	$65
#define kzsto	$66
#define kzint	$67
#define kzstat	$68
#define echostart2	$69
#define kselect	$69
#define kcircl	$6a
#define kcldrw	$6b
#define kline	$6c
#define kpen	$6d
#define kptchg	$6e
#define kptoff	$6f
#define kpton	$70
#define kvert	$71
#define khoriz	$72
#define ktext	$73
#define ktanln	$74
#define keval	$75
#define kinters	$76
#define kdydx	$77
#define kfnintg	$78
#define krootg	$79
#define kdydt	$7a
#define kdxdt	$7b
#define kdrdo	$7c
#define kgfmin	$7d
#define kgfmax	$7e
#define echostart	$7f
#define klistname	$7f
#define kadd	$80
#define ksub	$81
#define kmul	$82
#define kdiv	$83
#define kexpon	$84
#define klparen	$85
#define krparen	$86
#define klbrack	$87
#define krbrack	$88
#define kshade	$89
#define kstore	$8a
#define kcomma	$8b
#define kchs	$8c
#define kdecpnt	$8d
#define k0	$8e
#define k1	$8f
#define k2	$90
#define k3	$91
#define k4	$92
#define k5	$93
#define k6	$94
#define k7	$95
#define k8	$96
#define k9	$97
#define kee	$98
#define kspace	$99
#define kcapa	$9a
#define kcapb	$9b
#define kcapc	$9c
#define kcapd	$9d
#define kcape	$9e
#define kcapf	$9f
#define kcapg	$a0
#define kcaph	$a1
#define kcapi	$a2
#define kcapj	$a3
#define kcapk	$a4
#define kcapl	$a5
#define kcapm	$a6
#define kcapn	$a7
#define kcapo	$a8
#define kcapp	$a9
#define kcapq	$aa
#define kcapr	$ab
#define kcaps	$ac
#define kcapt	$ad
#define kcapu	$ae
#define kcapv	$af
#define kcapw	$b0
#define kcapx	$b1
#define kcapy	$b2
#define kcapz	$b3
#define kvarx	$b4
#define kpi	$b5
#define kinv	$b6
#define ksin	$b7
#define kasin	$b8
#define kcos	$b9
#define kacos	$ba
#define ktan	$bb
#define katan	$bc
#define ksquare	$bd
#define ksqrt	$be
#define kln	$bf
#define kexp	$c0
#define klog	$c1
#define kalog	$c2
#define ktoabc	$c3
#define kclrtbl	$c4
#define kans	$c5
#define kcolon	$c6
#define knderiv	$c7
#define kfnint	$c8
#define kroot	$c9
#define kquest	$ca
#define kquote	$cb
#define ktheta	$cc
#define kif	$cd
#define kthen	$ce
#define kelse	$cf
#define kfor	$d0
#define kwhile	$d1
#define krepeat	$d2
#define kend	$d3
#define kpause	$d4
#define klbl	$d5
#define kgoto	$d6
#define kisg	$d7
#define kdsl	$d8
#define kmenu	$d9
#define kexec	$da
#define kreturn	$db
#define kstop	$dc
#define kinput	$dd
#define kprompt	$de
#define kdisp	$df
#define kdispg	$e0
#define kdispt	$e1
#define koutput	$e2
#define kgetkey	$e3
#define kclrhome	$e4
#define kprtscr	$e5
#define ksinh	$e6
#define kcosh	$e7
#define ktanh	$e8
#define kasinh	$e9
#define kacosh	$ea
#define katanh	$eb
#define klbrace	$ec
#define krbrace	$ed
#define ki	$ee
#define kconstea	$ef
#define kplot3	$f0
#define kfmin	$f1
#define kfmax	$f2
#define kl1a	$f3
#define kl2a	$f4
#define kl3a	$f5
#define kl4a	$f6
#define kl5a	$f7
#define kl6a	$f8
#define kuna	$f9
#define kvna	$fa
#define kwna	$fb

;this key means that it is a 2 byte keycode
;there are 2 of these keys; be careful with usage
;------------------------------------------------
#define kextendecho2	$fc

;this key means that the key press is one that echos
;into a buffer, and it is a 2 byte key code, go look at
;(extecho) for the key value
;------------------------------------------------------
#define kextendecho	$fe

#define ke1bt	$00
#define kdrawinv	ke1bt
#define kdrawf	ke1bt+1
#define kpixelon	ke1bt+2
#define kpixeloff	ke1bt+3
#define kpxltest	ke1bt+4
#define krcgdb	ke1bt+5
#define krcpic	ke1bt+6
#define kstgdb	ke1bt+7
#define kstpic	ke1bt+8
#define kabs	ke1bt+9
#define ktequ	ke1bt+10 ;==
#define ktnoteq	ke1bt+11 ;<>
#define ktgt	ke1bt+12 ;>
#define ktgte	ke1bt+13 ;>=
#define ktlt	ke1bt+14 ;<
#define ktlte	ke1bt+15 ;<=
#define kand	ke1bt+16
#define kor	ke1bt+17
#define kxor	ke1bt+18
#define knot	ke1bt+19
#define klr1	ke1bt+20
#define kxroot	ke1bt+21
#define kcube	ke1bt+22
#define kcbrt	ke1bt+23 ;cube root
#define ktodec	ke1bt+24
#define kcubicr	ke1bt+25
#define kquartr	ke1bt+26
#define kplot1	ke1bt+27
#define kplot2	ke1bt+28
#define kround	ke1bt+29
#define kipart	ke1bt+30
#define kfpart	ke1bt+31
#define kint	ke1bt+32
#define krand	ke1bt+33
#define knpr	ke1bt+34
#define kncr	ke1bt+35
#define kxfactorial	ke1bt+36
#define krad	ke1bt+37
#define kdegr	ke1bt+38 ;degrees conv
#define kapost	ke1bt+39
#define ktodms	ke1bt+40
#define krtopo	ke1bt+41 ;r
#define krtopr	ke1bt+42
#define kptorx	ke1bt+43
#define kptory	ke1bt+44
#define krowswap	ke1bt+45
#define krowplus	ke1bt+46
#define ktimrow	ke1bt+47
#define ktrowp	ke1bt+48
#define ksorta	ke1bt+49
#define ksortd	ke1bt+50
#define kseq	ke1bt+51
#define kmin	ke1bt+52
#define kmax	ke1bt+53
#define kmean	ke1bt+54
#define kmedian	ke1bt+55
#define ksum	ke1bt+56
#define kprod	ke1bt+57
#define kdet	ke1bt+58
#define ktransp	ke1bt+59
#define kdim	ke1bt+60
#define kfill	ke1bt+61
#define kident	ke1bt+62
#define krandm	ke1bt+63
#define kaug	ke1bt+64
#define konevar	ke1bt+65
#define ktwovar	ke1bt+66
#define klr	ke1bt+67
#define klrexp	ke1bt+68
#define klrln	ke1bt+69
#define klrpwr	ke1bt+70
#define kmedmed	ke1bt+71
#define kquad	ke1bt+72
#define kclrlst	ke1bt+73
#define khist	ke1bt+74
#define kxyline	ke1bt+75
#define kscatter	ke1bt+76
#define kmrad	ke1bt+77
#define kmdeg	ke1bt+78
#define kmnormf	ke1bt+79
#define kmsci	ke1bt+80
#define kmeng	ke1bt+81
#define kmfloat	ke1bt+82
#define kfix	ke1bt+83
#define kspliton	ke1bt+84
#define kfullscreen	ke1bt+85
#define kstndrd	ke1bt+86
#define kparam	ke1bt+87
#define kpolar	ke1bt+88
#define kseqg	ke1bt+89
#define kafillon	ke1bt+90
#define kafilloff	ke1bt+91
#define kacalcon	ke1bt+92
#define kacalcoff	ke1bt+93
#define kfnon	ke1bt+94
#define kfnoff	ke1bt+95
#define kplotson	ke1bt+96
#define kplotsoff	ke1bt+97
#define kpixelchg	ke1bt+98
#define ksendmbl	ke1bt+99
#define krecvmbl	ke1bt+100
#define kboxplot	ke1bt+101
#define kboxicon	ke1bt+102
#define kcrossicon	ke1bt+103
#define kdoticon	ke1bt+104
#define ke2bt	ke1bt+105
#define kseqential	ke2bt
#define ksimulg	ke2bt+1
#define kpolarg	ke2bt+2
#define krectg	ke2bt+3
#define kcoordon	ke2bt+4
#define kcoordoff	ke2bt+5
#define kdrawline	ke2bt+6
#define kdrawdot	ke2bt+7
#define kaxison	ke2bt+8
#define kaxisoff	ke2bt+9
#define kgridon	ke2bt+10
#define kgridoff	ke2bt+11
#define klblon	ke2bt+12
#define klbloff	ke2bt+13
#define kl1	ke2bt+14
#define kl2	ke2bt+15
#define kl3	ke2bt+16
#define kl4	ke2bt+17
#define kl5	ke2bt+18
#define kl6	ke2bt+19

;these keys are laid on top of existing keys to
;enable localization in the inferential stats editor.
;----------------------------------------------------
#define kinfdata	kl1
#define kinfstats	kl1+1
#define kinfyes	kl1+2
#define kinfno	kl1+3
#define kinfcalc	kl1+4
#define kinfdraw	kl1+5
#define kinfalt1ne	kl1+6
#define kinfalt1lt	kl1+7
#define kinfalt1gt	kl1+8
#define kinfalt2ne	kl1+9
#define kinfalt2lt	kl1+10
#define kinfalt2gt	kl1+11
#define kinfalt3ne	kl1+12
#define kinfalt3lt	kl1+13
#define kinfalt3gt	kl1+14
#define kinfalt4ne	kl1+15
#define kinfalt4lt	kl1+16
#define kinfalt4gt	kl1+17
#define kinfalt5ne	kl1+18
#define kinfalt5lt	kl1+19
#define kinfalt5gt	kl1+20
#define kinfalt6ne	kl1+21
#define kinfalt6lt	kl1+22
#define kinfalt6gt	kl1+23
#define kmata	ke2bt+20
#define kmatb	ke2bt+21
#define kmatc	ke2bt+22
#define kmatd	ke2bt+23
#define kmate	ke2bt+24
#define kxmin	ke2bt+25
#define kxmax	ke2bt+26
#define kxscl	ke2bt+27
#define kymin	ke2bt+28
#define kymax	ke2bt+29
#define kyscl	ke2bt+30
#define ktmin	ke2bt+31
#define ktmax	ke2bt+32
#define ktstep	ke2bt+33
#define komin	ke2bt+34
#define komax	ke2bt+35
#define kostep	ke2bt+36
#define ku0	ke2bt+37
#define kv0	ke2bt+38
#define knmin	ke2bt+39
#define knmax	ke2bt+40
#define kdeltay	ke2bt+41
#define kdeltax	ke2bt+42
#define kzxmin	ke2bt+43
#define kzxmax	ke2bt+44
#define kzxscl	ke2bt+45
#define kzymin	ke2bt+46
#define kzymax	ke2bt+47
#define kzyscl	ke2bt+48
#define kztmin	ke2bt+49
#define kztmax	ke2bt+50
#define kztstep	ke2bt+51
#define kzomin	ke2bt+52
#define kzomax	ke2bt+53
#define kzostep	ke2bt+54
#define kzu0	ke2bt+55
#define kzv0	ke2bt+56
#define kznmin	ke2bt+57
#define kznmax	ke2bt+58
#define kdellast	ke2bt+59
#define ksinreg	ke2bt+60
#define kconste	ke2bt+61
#define kpic1	ke2bt+62
#define kpic2	ke2bt+63
#define kpic3	ke2bt+64
#define kdelvar	ke2bt+65
#define kgetcalc	ke2bt+66
#define krealm	ke2bt+67
#define kpolarm	ke2bt+68
#define krectm	ke2bt+69
#define kuv	ke2bt+70 ;u vs v
#define kvw	ke2bt+71 ;v vs w
#define kuw	ke2bt+72 ;u vs w
#define kfinpmtend	ke2bt+73
#define kfinpmtbeg	ke2bt+74
#define kgraphstyle	ke2bt+75
#define kexpron	ke2bt+76
#define kexproff	ke2bt+77
#define kstata	ke2bt+78
#define kstatb	ke2bt+79
#define kstatc	ke2bt+80
#define kcorr	ke2bt+81
#define kstatd	ke2bt+82
#define kstate	ke2bt+83
#define kregeq	ke2bt+84
#define kminx	ke2bt+85
#define kq1	ke2bt+86
#define kmd	ke2bt+87
#define kq3	ke2bt+88
#define kmaxx	ke2bt+89
#define kstatx1	ke2bt+90
#define kstaty1	ke2bt+91
#define kstatx2	ke2bt+92
#define kstaty2	ke2bt+93
#define kstatx3	ke2bt+94
#define kstaty3	ke2bt+95
#define ktblmin	ke2bt+96
#define ktblstep	ke2bt+97
#define ksetuplst	ke2bt+98
#define kclralllst	ke2bt+99
#define klogistic	ke2bt+100
#define kztest	ke2bt+101
#define kttest	ke2bt+102
#define k2sampztest	ke2bt+103
#define k2sampttest	ke2bt+104
#define k1propztest	ke2bt+105
#define k2propztest	ke2bt+106
#define kchitest	ke2bt+107
#define k2sampftest	ke2bt+108
#define kzintval	ke2bt+109
#define ktintval	ke2bt+110
#define k2samptint	ke2bt+111
#define k2sampzint	ke2bt+112
#define k1propzint	ke2bt+113
#define k2propzint	ke2bt+114
#define kdnormal	ke2bt+115
#define kinvnorm	ke2bt+116
#define kdt	ke2bt+117
#define kchi	ke2bt+118
#define kdf	ke2bt+119
#define kbinpdf	ke2bt+120
#define kbincdf	ke2bt+121
#define kpoipdf	ke2bt+122
#define kpoicdf	ke2bt+123
#define kun	ke2bt+124
#define kvn	ke2bt+125
#define kwn	ke2bt+126
#define krecn	ke2bt+127
#define kplotstart	ke2bt+128
#define kzplotstart	ke2bt+129 ;recursion n
#define kxfact	ke2bt+130 ;plotstart
#define kyfact	ke2bt+131 ;zplotstart
#define kanova	ke2bt+132 ;xfact
#define kmaxy	ke2bt+133 ;yfact
#define kwebon	ke2bt+134 ;miny
#define kweboff	ke2bt+135 ;maxy
#define ktblinput	ke2bt+136 ;web on
#define kgeopdf	ke2bt+137 ;web off
#define kgeocdf	ke2bt+138 ;web off
#define kshadenorm	ke2bt+139
#define kshadet	ke2bt+140
#define kshadechi	ke2bt+141
#define kshadef	ke2bt+142
#define kplotstep	ke2bt+143
#define kzplotstep	ke2bt+144
#define klinregttest	ke2bt+145
#define kmgt	ke2bt+146 ;vert split
#define kselecta	ke2bt+147
#define kzfita	ke2bt+148
#define ke2bt_end	kzfita

;more 2 byte keys
;------------------------------------
#define ke2bt2	$00
#define kgdb1	ke2bt2
#define kgdb2	ke2bt2+1
#define kgdb3	ke2bt2+2
#define ky1	ke2bt2+3
#define ky2	ke2bt2+4
#define ky3	ke2bt2+5
#define ky4	ke2bt2+6
#define ky5	ke2bt2+7
#define ky6	ke2bt2+8
#define ky7	ke2bt2+9
#define ky8	ke2bt2+10
#define ky9	ke2bt2+11
#define ky0	ke2bt2+12
#define kx1t	ke2bt2+13
#define ky1t	ke2bt2+14
#define kx2t	ke2bt2+15
#define ky2t	ke2bt2+16
#define kx3t	ke2bt2+17
#define ky3t	ke2bt2+18
#define kx4t	ke2bt2+19
#define ky4t	ke2bt2+20
#define kx5t	ke2bt2+21
#define ky5t	ke2bt2+22
#define kx6t	ke2bt2+23
#define ky6t	ke2bt2+24
#define kr1	ke2bt2+25
#define kr2	ke2bt2+26
#define kr3	ke2bt2+27
#define kr4	ke2bt2+28
#define kr5	ke2bt2+29
#define kr6	ke2bt2+30
#define kgdb4	ke2bt2+31
#define kgdb5	ke2bt2+32
#define kgdb6	ke2bt2+33
#define kpic4	ke2bt2+34
#define kpic5	ke2bt2+35
#define kpic6	ke2bt2+36
#define kgdb7	ke2bt2+37
#define kgdb8	ke2bt2+38
#define kgdb9	ke2bt2+39
#define kgdb0	ke2bt2+40
#define kpic7	ke2bt2+41
#define kpic8	ke2bt2+42
#define kpic9	ke2bt2+43
#define kpic0	ke2bt2+44
#define kstatn	ke2bt2+45
#define kxmean	ke2bt2+46
#define kconj	ke2bt2+47
#define kreal	ke2bt2+48
#define kfangle	ke2bt2+49
#define klcm	ke2bt2+50
#define kgcd	ke2bt2+51
#define krandint	ke2bt2+52
#define krandnorm	ke2bt2+53
#define ktopolar	ke2bt2+54
#define ktorect	ke2bt2+55
#define kymean	ke2bt2+56
#define kstdx	ke2bt2+57
#define kstdx1	ke2bt2+58
#define kw0	ke2bt2+59
#define kmatf	ke2bt2+60
#define kmatg	ke2bt2+61
#define kmatrh	ke2bt2+62
#define kmati	ke2bt2+63
#define kmatj	ke2bt2+64
#define kymean1	ke2bt2+65
#define kstdy	ke2bt2+66
#define kstdy1	ke2bt2+67
#define kmattolst	ke2bt2+68
#define klsttomat	ke2bt2+69
#define kcumsum	ke2bt2+70
#define kdeltalst	ke2bt2+71
#define kstddev	ke2bt2+72
#define kvariance	ke2bt2+73
#define klength	ke2bt2+74
#define kequtostrng	ke2bt2+75
#define kstrngtoequ	ke2bt2+76
#define kexpr	ke2bt2+77
#define ksubstrng	ke2bt2+78
#define kinstrng	ke2bt2+79
#define kstr1	ke2bt2+80
#define kstr2	ke2bt2+81
#define kstr3	ke2bt2+82
#define kstr4       	ke2bt2+83
#define kstr5       	ke2bt2+84
#define kstr6       	ke2bt2+85
#define kstr7       	ke2bt2+86
#define kstr8       	ke2bt2+87
#define kstr9       	ke2bt2+88
#define kstr0       	ke2bt2+89
#define kfinn       	ke2bt2+90
#define kfini       	ke2bt2+91
#define kfinpv      	ke2bt2+92
#define kfinpmt     	ke2bt2+93
#define kfinfv      	ke2bt2+94
#define kfinpy      	ke2bt2+95
#define kfincy      	ke2bt2+96
#define kfinfpmt    	ke2bt2+97
#define kfinfi      	ke2bt2+98
#define kfinfpv     	ke2bt2+99
#define kfinfn      	ke2bt2+100
#define kfinffv     	ke2bt2+101
#define kfinnpv     	ke2bt2+102
#define kfinirr     	ke2bt2+103
#define kfinbal     	ke2bt2+104
#define kfinprn     	ke2bt2+105
#define kfinint     	ke2bt2+106
#define ksumx       	ke2bt2+107
#define ksumx2      	ke2bt2+108
#define kfintonom   	ke2bt2+109
#define kfintoeff   	ke2bt2+110
#define kfindbd     	ke2bt2+111
#define kstatvp     	ke2bt2+112
#define kstatz      	ke2bt2+113
#define kstatt      	ke2bt2+114
#define kstatchi    	ke2bt2+115
#define kstatf      	ke2bt2+116
#define kstatdf     	ke2bt2+117
#define kstatphat   	ke2bt2+118
#define kstatphat1  	ke2bt2+119
#define kstatphat2  	ke2bt2+120
#define kstatmeanx1 	ke2bt2+121
#define kstatmeanx2 	ke2bt2+122
#define kstatstdx1  	ke2bt2+123
#define kstatstdx2  	ke2bt2+124
#define kstatstdxp	ke2bt2+125
#define kstatn1	ke2bt2+126
#define kstatn2	ke2bt2+127
#define kstatlower	ke2bt2+128
#define kstatupper	ke2bt2+129
#define kuw0	ke2bt2+130
#define kimag	ke2bt2+131
#define ksumy	ke2bt2+132
#define kxres	ke2bt2+133
#define kstat_s	ke2bt2+134
#define ksumy2	ke2bt2+135
#define ksumxy	ke2bt2+136
#define kuxres	ke2bt2+137
#define kmodbox	ke2bt2+138
#define knormprob	ke2bt2+139
#define knormalpdf	ke2bt2+140
#define ktpdf	ke2bt2+141
#define kchipdf	ke2bt2+142
#define kfpdf	ke2bt2+143
#define kminy	ke2bt2+144 ;miny
#define krandbin	ke2bt2+145
#define kref	ke2bt2+146
#define krref	ke2bt2+147
#define klrsqr	ke2bt2+148
#define kbrsqr	ke2bt2+149
#define kdiagon	ke2bt2+150
#define kdiagoff	ke2bt2+151
#define kun1	ke2bt2+152 ;for rcl use when gotten from 82
#define kvn1	ke2bt2+153 ;for rcl use when gotten from 82
#define k83_00end	kvn1 ;end of original keys...
#define karchive	k83_00end+1
#define kunarchive	k83_00end+2
#define kasm	k83_00end+3 ;asm(
#define kasmprgm	k83_00end+4 ;asmprgm
#define kasmcomp	k83_00end+5 ;asmcomp(
#define kcapaacute	k83_00end+6
#define kcapagrave	k83_00end+7
#define kcapacaret	k83_00end+8
#define kcapadier	k83_00end+9
#define kaacute	k83_00end+10
#define kagrave	k83_00end+11
#define kacaret	k83_00end+12
#define kadier	k83_00end+13
#define kcapeacute	k83_00end+14
#define kcapegrave	k83_00end+15
#define kcapecaret	k83_00end+16
#define kcapedier	k83_00end+17
#define keacute	k83_00end+18
#define kegrave	k83_00end+19
#define kecaret	k83_00end+20
#define kedier	k83_00end+21
#define kcapiacute	k83_00end+22
#define kcapigrave	k83_00end+23
#define kcapicaret	k83_00end+24
#define kcapidier	k83_00end+25
#define kiacute	k83_00end+26
#define kigrave	k83_00end+27
#define kicaret	k83_00end+28
#define kidier	k83_00end+29
#define kcapoacute	k83_00end+30
#define kcapograve	k83_00end+31
#define kcapocaret	k83_00end+32
#define kcapodier	k83_00end+33
#define koacute	k83_00end+34
#define kograve	k83_00end+35
#define kocaret	k83_00end+36
#define kodier	k83_00end+37
#define kcapuacute	k83_00end+38
#define kcapugrave	k83_00end+39
#define kcapucaret	k83_00end+40
#define kcapudier	k83_00end+41
#define kuacute	k83_00end+42
#define kugrave	k83_00end+43
#define kucaret	k83_00end+44
#define kudier	k83_00end+45
#define kcapcced	k83_00end+46
#define kcced	k83_00end+47
#define kcapntilde	k83_00end+48
#define kntilde	k83_00end+49
#define kaccent	k83_00end+50
#define kgrave	k83_00end+51
#define kdieresis	k83_00end+52
#define kquesdown	k83_00end+53
#define kexclamdown 	k83_00end+54
#define kalpha      	k83_00end+55
#define kbeta       	k83_00end+56
#define kgamma      	k83_00end+57
#define kcapdelta	k83_00end+58
#define kdelta	k83_00end+59
#define kepsilon	k83_00end+60
#define klambda	k83_00end+61
#define kmu	k83_00end+62
#define kpi2	k83_00end+63
#define krho	k83_00end+64
#define kcapsigma	k83_00end+65
#define ksigma	k83_00end+66
#define ktau	k83_00end+67
#define kphi	k83_00end+68
#define kcapomega	k83_00end+69
#define kphat	k83_00end+70
#define kchi2	k83_00end+71
#define kstatf2	k83_00end+72
#define kla	k83_00end+73
#define klb	k83_00end+74
#define klc	k83_00end+75
#define kld	k83_00end+76
#define kle	k83_00end+77
#define klf	k83_00end+78
#define klg	k83_00end+79
#define klh	k83_00end+80
#define kli	k83_00end+81
#define klj	k83_00end+82
#define klk	k83_00end+83
#define kll	k83_00end+84
#define klm	k83_00end+85
#define klsmalln	k83_00end+86
#define klo	k83_00end+87
#define klp	k83_00end+88
#define klq	k83_00end+89
#define klsmallr	k83_00end+90
#define kls	k83_00end+91
#define klt	k83_00end+92
#define klu	k83_00end+93
#define klv	k83_00end+94
#define klw	k83_00end+95
#define klx	k83_00end+96
#define kly	k83_00end+97
#define klz	k83_00end+98
#define kgarbagec	k83_00end+99 ;garbagecollect
#define ke2bt2_end	kgarbagec

;ti-83 plus context equates
;---------------------------------------------
#define cxcmd	kquit ;home screen
#define cxmatedit	kmatrixed ;matrix editor
#define cxprgmedit	kprgmed ;program editor
#define cxequedit	kyequ ;equation editor
#define cxgrrange	kwindow ;graph range editor
#define cxgrzfact	kzfacted ;graph zoom factors editor
#define cxgraph	kgrap ;graph mode
#define cxstatedit	kstated ;statistics list editor
#define cxprgminput	kprgminput ;programmed input
#define cxerror	kerror ;error handler
#define cxlinkio	klinkio ;link i/o interface
#define cxmem	kresetmem ;reset memory
#define cxdefmem	kresetdef ;reset default
#define cxramapp	kchkram ;ram usage screen
#define cxmode	kmode ;mode settings screen
#define cxerase	kdelmem ;memory erase
#define cxprgmcreate	kprgmcr ;program create
#define cxtableeditor	ktable ;table editor
#define cxtableset	ktblset ;table set up
#define cxstatplot	kstatp ;stat plots
#define cxinfstat	kinfstat ;inferential statistic
#define cxformat	kformat ;format context
#define cxsolvetvm	ksolvetvm ;solve tvm
#define cxsolveroot	ksolveroot ;solve root
#define lastoldapp	kextapps ;external applications
#define cxextapps	kextapps
#define cxnewapps	knewapps ;new cerberus applications
#define cxgroup	cxnewapps+0 ;$1st new app.
#define cxungroup	cxnewapps+1 ;$2nd new app.
#define lastnewapp	cxungroup ;last new app for this ver

;scan code equates
;-------------------------------
#define skdown	$01
#define skleft	$02
#define skright	$03
#define skup	$04
#define skenter	$09
#define skadd	$0a
#define sksub	$0b
#define skmul	$0c
#define skdiv	$0d
#define skpower	$0e
#define skclear	$0f
#define skchs	$11
#define sk3	$12
#define sk6	$13
#define sk9	$14
#define skrparen	$15
#define sktan	$16
#define skvars	$17
#define skdecpnt	$19
#define sk2	$1a
#define sk5	$1b
#define sk8	$1c
#define sklparen	$1d
#define skcos	$1e
#define skprgm	$1f
#define skstat	$20
#define sk0	$21
#define sk1	$22
#define sk4	$23
#define sk7	$24
#define skcomma	$25
#define sksin	$26
#define skmatrix	$27
#define skgraphvar	$28
#define skstore	$2a
#define skln	$2b
#define sklog	$2c
#define sksquare	$2d
#define skrecip	$2e
#define skmath	$2f
#define skalpha	$30
#define skgraph	$31
#define sktrace	$32
#define skzoom	$33
#define skwindow	$34
#define skyequ	$35
#define sk2nd	$36
#define skmode	$37
#define skdel	$38

;tokens
;----------------------------------------------------
#define eosstart	$00

;display conversions come immediately before 'tstore'
;
#define dconv	$01
;
#define ttodms	dconv ;$01
#define ttodec	dconv+1 ;$02
#define ttoabc	dconv+2 ;$03 > a b/c
;
#define tstore	dconv+3 ;$04 lstore 01
;
#define tboxplot	$05
;
#define bracks	$06
;
#define tlbrack	bracks ;$06 '['
#define trbrack	bracks+1 ;$07 ']'
#define tlbrace	bracks+2 ;$08 '{'
#define trbrace	bracks+3 ;$09 '}'
;
#define tpost1	bracks+4
;
#define tfromrad	tpost1 ;$0a lradian
#define tfromdeg	tpost1+1 ;$0b ldegree
#define trecip	tpost1+2 ;$0c linverse
#define tsqr	tpost1+3 ;$0d lsquare
#define ttrnspos	tpost1+4 ;$0e ltranspose
#define tcube	tpost1+5 ;$0f '^3'
;
#define tlparen	$10 ;$10 '('
#define trparen	$11 ;$11 ')'
;
#define imun	$12
;
#define tround	imun ;$12 'round'
#define tpxtst	imun+1 ;$13 'pxl-test'
#define taug	imun+2 ;$14 'aug'
#define trowswap	imun+3 ;$15 'rswap'
#define trowplus	imun+4 ;$16 'radd'
#define tmrow	imun+5 ;$17 'multr'
#define tmrowplus	imun+6 ;$18 'mradd'
#define tmax	imun+7 ;$19 'max'
#define tmin	imun+8 ;$1a 'min'
#define trtopr	imun+9 ;$1b 'r>pr
#define trtopo	imun+10 ;$1c 'r>po
#define tptorx	imun+11 ;$1d 'p>rx
#define tptory	imun+12 ;$1e 'p>ry
#define tmedian	imun+13 ;$1f 'median
#define trandm	imun+14 ;$20 'randm'
#define tmean	imun+15 ;$21
#define troot	imun+16 ;$22 'root'
#define tseries	imun+17 ;$23 'seq'
#define tfnint	imun+18 ;$24 'fnint'
#define tnderiv	imun+19 ;$25 'fnir'
#define tevalf	imun+20 ;$26
#define tfmin	imun+21 ;$27
#define tfmax	imun+22 ;$28
;
#define teosel	imun+23
;
#define tspace	teosel ;$29 ' '
#define tstring	teosel+1 ;$2a '"'
#define tcomma	teosel+2 ;$2b ','
;
#define tii	$2c ;i

;postfix functions
;-----------------------------------------
#define tpost	$2d
;
#define tfact	tpost ;$2d '!'
;
#define tcubicr	$2e
#define tquartr	$2f

;number tokens
;---------------------------------------
#define nums	$30
;
#define t0	nums ;$30
#define t1	nums+1 ;$31
#define t2	nums+2 ;$32
#define t3	nums+3 ;$33
#define t4	nums+4 ;$34
#define t5	nums+5 ;$35
#define t6	nums+6 ;$36
#define t7	nums+7 ;$37
#define t8	nums+8 ;$38
#define t9	nums+9 ;$39
#define tdecpt	nums+10 ;$3a
#define tee	nums+11 ;$3b

;binary op
;-------------------------------------------
#define tor	$3c ;$3c '_or_'
#define txor	$3d ;$3d
;
#define tcolon	$3e ;$3e ':'
#define tenter	$3f ;$3f lenter
;
#define tand	$40 ;$40 '_and_'

;letter tokens
;--------------------------------------
#define let	$41
#define ta	let ;$41
#define tb	let+1 ;$42
#define tc	let+2 ;$43
#define td	let+3 ;$44
#define te	let+4 ;$45
#define tf	let+5 ;$46
#define tg	let+6 ;$47
#define th	let+7 ;$48
#define ti	let+8 ;$49
#define tj	let+9 ;$4a
#define tk	let+10 ;$4b
#define tl	let+11 ;$4c
#define tm	let+12 ;$4d
#define tn	let+13 ;$4e
#define to	let+14 ;$4f
#define tp	let+15 ;$50
#define tq	let+16 ;$51
#define tr	let+17 ;$52
#define ts	let+18 ;$53
#define tt	let+19 ;$54
#define tu	let+20 ;$55
#define tv	let+21 ;$56
#define tw	let+22 ;$57
#define tx	let+23 ;$58
#define ty	let+24 ;$59
#define tz	let+25 ;$5a
#define ttheta	let+26 ;$5b

;these var tokens are 1st of a double token
;------------------------------------------

#define vtoks	let+27

;user matrix token, 2nd token needed for name
;
#define tvarmat	vtoks ;$5c
;
;user list token, 2nd token needed for name
;
#define tvarlst	vtoks+1 ;$5d
;
;user equation token, 2nd token needed for name
;
#define tvarequ	vtoks+2 ;$5e
#define tprog	vtoks+3 ;$5f
;
;user pict token, 2nd token needed for name
;
#define tvarpict	vtoks+4 ;$60
;
;user gdb token, 2nd token needed for name
;
#define tvargdb	vtoks+5 ;$61
#define tvarout	vtoks+6 ;$62
#define tvarsys	vtoks+7 ;$63

;mode setting commands
;-------------------------------------------------
#define modesa	vtoks+8 ;$64
#define trad	modesa ;$64 'radian'
#define tdeg	modesa+1 ;$65 'degree'
#define tnormf	modesa+2 ;$66 'normal'
#define tsci	modesa+3 ;$67 'sci'
#define teng	modesa+4 ;$68 'eng'
#define tfloat	modesa+5 ;$69 'float'
#define cmps	$6a
#define teq	cmps ;$6a '=='
#define tlt	cmps+1 ;$6b '<'
#define tgt	cmps+2 ;$6c '>'
#define tle	cmps+3 ;$6d lle
#define tge	cmps+4 ;$6e lge
#define tne	cmps+5 ;$6f lne

;binary op
;---------------------------------------
#define tadd	$70 ;$70 '+'
#define tsub	$71 ;$71 '-'
#define tans	$72 ;$72

;mode setting commands
;-------------------------------------------------------
#define modes	$73
#define tfix	modes ;$73 'fix_'
#define tspliton	modes+1 ;$74
#define tfullscreen	modes+2 ;$75
#define tstndrd	modes+3 ;$76 'func'
#define tparam	modes+4 ;$77 'param'
#define tpolar	modes+5 ;$78 'pol'
#define tseqg	modes+6 ;$79
#define tafillon	modes+7 ;$7a 'auto fill on'
#define tafilloff	modes+8 ;$7b
#define tacalcon	modes+9 ;$7c
#define tacalcoff	modes+10 ;$7d 'autofill off'

;graph format tokens are 2 byte tokens
;----------------------------------------
#define tgformat	modes+11 ;$7e
#define tboxicon	$7f
#define tcrossicon	$80
#define tdoticon	$81

;(more) binary op
;---------------------------------------
#define tmul	$82 ;$82 '*'
#define tdiv	$83 ;$83 '/'

;some graph commands
;------------------------------------------------------
#define grcmds	$84
#define ttrace	grcmds ;$84 'trace'
#define tcldrw	grcmds+1 ;$85 'cldrw'
#define tzoomstd	grcmds+2 ;$86 'zstd'
#define tzoomtrg	grcmds+3 ;$87 'ztrg'
#define tzoombox	grcmds+4 ;$88 'zbox'
#define tzoomin	grcmds+5 ;$89 'zin'
#define tzoomout	grcmds+6 ;$8a 'zout'
#define tzoomsqr	grcmds+7 ;$8b 'zsqr'
#define tzoomint	grcmds+8 ;$8c 'zint'
#define tzoomprev	grcmds+9 ;$8d 'zprev'
#define tzoomdec	grcmds+10 ;$8e 'zdecm'
#define tzoomstat	grcmds+11 ;$8f 'zstat
#define tusrzm	grcmds+12 ;$90 'zrcl'
#define tprtscrn	grcmds+13 ;$91 'prtscrn'
#define tzoomsto	grcmds+14 ;$92  zoom store
#define ttext	grcmds+15 ;$93

;binary op (combination & permutation)
;-------------------------------------------------
#define tnpr	grcmds+16 ;$94 '_npr_'
#define tncr	grcmds+17 ;$95 '_ncr_'

;more graph commands
;--------------------------------------------------
#define tyon	grcmds+18 ;$96 'fnon_'
#define tyoff	grcmds+19 ;$97 'fnoff_'
#define tstpic	grcmds+20 ;$98 'stpic_'
#define trcpic	grcmds+21 ;$99 'rcpic_'
#define tstodb	grcmds+22 ;$9a 'stgdb_'
#define trcldb	grcmds+23 ;$9b 'rcgdb_'
#define tline	grcmds+24 ;$9c 'line'
#define tvert	grcmds+25 ;$9d 'vert_'
#define tpton	grcmds+26 ;$9e 'pton'
#define tptoff	grcmds+27 ;$9f 'ptoff'

;token a0 cannot be an eos function since low mult=a0 already
;------------------------------------------------------------
#define tptchg	grcmds+28 ;$a0 'ptchg'
#define tpxon	grcmds+29 ;$a1
#define tpxoff	grcmds+30 ;$a2
#define tpxchg	grcmds+31 ;$a3
#define tshade	grcmds+32 ;$a4 'shade'
#define tcircl	grcmds+33 ;$a5 'circl'
#define thorz	grcmds+34 ;$a6 'horizontal'
#define ttanln	grcmds+35 ;$a7 'tanln'
#define tdrinv	grcmds+36 ;$a8 'drinv_'
#define tdrawf	grcmds+37 ;$a9 'drawf_'
#define tvarstrng	$aa

;functions with no arguments
;--------------------------------------------------
#define noarg	$0ab
#define trand	noarg ;$ab 'rand'
#define tpi	noarg+1 ;$ac  lpi
#define tgetkey	noarg+2 ;$ad 'getky'
#define tapost	tgetkey+1 ;apostrophy
#define tquest	tapost+1 ;question mark
#define unary	tquest+1 ;$b0
#define tchs	unary ;$b0
#define tint	unary+1 ;$b1
#define tabs	unary+2 ;$b2
#define tdet	unary+3 ;$b3
#define tident	unary+4 ;$b4
#define tdim	unary+5 ;$b5
#define tsum	unary+6 ;$b6
#define tprod	unary+7 ;$b7
#define tnot	unary+8 ;$b8
#define tipart	unary+9 ;$b9
#define tfpart	unary+10 ;$ba

;new 2 byte tokens
;------------------------------------------
#define t2bytetok	$bb
#define unarylr	unary+12
#define tsqrt	unarylr ;$bc
#define tcubrt	unarylr+1 ;$bd
#define tln	unarylr+2 ;$be
#define texp	unarylr+3 ;$bf
#define tlog	unarylr+4 ;$c0
#define talog	unarylr+5 ;$c1
#define tsin	unarylr+6 ;$c2
#define tasin	unarylr+7 ;$c3
#define tcos	unarylr+8 ;$c4
#define tacos	unarylr+9 ;$c5
#define ttan	unarylr+10 ;$c6
#define tatan	unarylr+11 ;$c7
#define tsinh	unarylr+12 ;$c8
#define tasinh	unarylr+13 ;$c9
#define tcoshh	unarylr+14 ;$ca
#define tacosh	unarylr+15 ;$cb
#define ttanh	unarylr+16 ;$cc
#define tatanh	unarylr+17 ;$cd

;some programming commands
;------------------------------------------------------
#define progtok	unarylr+18
#define tif	progtok ;$ce
#define tthen	progtok+1 ;$cf
#define telse	progtok+2 ;$d0
#define twhile	progtok+3 ;$d1
#define trepeat	progtok+4 ;$d2
#define tfor	progtok+5 ;$d3
#define tend	progtok+6 ;$d4
#define treturn	progtok+7 ;$d5
#define tlbl	progtok+8 ;$d6 'lbl_'
#define tgoto	progtok+9 ;$d7 'goto_'
#define tpause	progtok+10 ;$d8 'pause_'
#define tstop	progtok+11 ;$d9 'stop'
#define tisg	progtok+12 ;$da 'is>'
#define tdsl	progtok+13 ;$db 'ds<'
#define tinput	progtok+14 ;$dc 'input_'
#define tprompt	progtok+15 ;$dd 'prompt_'
#define tdisp	progtok+16 ;$de 'disp_'
#define tdispg	progtok+17 ;$df 'dispg'
#define toutput	progtok+18 ;$e0 'outpt'
#define tcllcd	progtok+19 ;$e1 'cllcd'
#define tconst	progtok+20 ;$e2 'fill'
#define tsorta	progtok+21 ;$e3 'sorta_'
#define tsortd	progtok+22 ;$e4 'sortd_'
#define tdisptab	progtok+23 ;$e5 'disp table
#define tmenu	progtok+24 ;$e6 'menu'
#define tsendmbl	progtok+25 ;$e7 'send'
#define tgetmbl	progtok+26 ;$e8 'get'

;stat plot commands
;------------------------------------------------------
#define statpcmd	progtok+27
#define tploton	statpcmd ;$e9 ' plotson'
#define tplotoff	statpcmd+1 ;$ea ' plotsoff
#define tlistname	$eb ;list designator
#define tplot1	$ec
#define tplot2	$ed
#define tplot3	$ee
#define tunused01	$ef ;available?
#define tpower	$f0 ;'^'
#define txroot	$f1 ;lsupx,lroot
#define statcmd	$f2
#define tonevar	statcmd ;f2 'onevar_'
#define ttwovar	statcmd+1 ;f3
#define tlr	statcmd+2 ;f4 'linr(a+bx
#define tlrexp	statcmd+3 ;f5 'expr_'
#define tlrln	statcmd+4 ;f6 'lnr_'
#define tlrpwr	statcmd+5 ;f7 'pwrr_'
#define tmedmed	statcmd+6 ;f8
#define tquad	statcmd+7 ;f9
#define tclrlst	statcmd+8 ;$fa 'clear list
#define tclrtbl	statcmd+9 ;$fb clear table
#define thist	statcmd+10 ;$fc 'hist_'
#define txyline	statcmd+11 ;$fd 'xyline_'
#define tscatter	statcmd+12 ;$fe 'scatter_'
#define tlr1	statcmd+13 ;$ff 'linr(ax+b

;$2nd half of graph format tokens
;----------------------------------------------
;           format settings commands
;
#define gfmt	$00
#define tseq	gfmt ; 'seqg'
#define tsimulg	gfmt+1 ; 'simulg'
#define tpolarg	gfmt+2 ; 'polargc'
#define trectg	gfmt+3 ; 'rectgc'
#define tcoordon	gfmt+4 ; 'coordon'
#define tcoordoff	gfmt+5 ; 'coordoff'
#define tdrawline	gfmt+6 ; 'drawline'
#define tdrawdot	gfmt+7 ; 'drawdot'
#define taxison	gfmt+8 ; 'axeson'
#define taxisoff	gfmt+9 ; 'axesoff'
#define tgridon	gfmt+10 ; 'gridon'
#define tgridoff	gfmt+11 ; 'gridoff'
#define tlblon	gfmt+12 ; 'labelon'
#define tlbloff	gfmt+13 ; 'labeloff'
#define twebon	gfmt+14 ; 'webon'
#define tweboff	gfmt+15 ; 'weboff'
#define tuv	gfmt+16 ; u vs v
#define tvw	gfmt+17 ; v vs w
#define tuw	gfmt+18 ; u vs w

;$2nd half of user matrix tokens
;-------------------------------------
#define tmata	$00 ;mat a
#define tmatb	$01 ;mat b
#define tmatc	$02 ;mat c
#define tmatd	$03 ;mat d
#define tmate	$04 ;mat e
#define tmatf	$05 ;mat f
#define tmatg	$06 ;mat g
#define tmath	$07 ;mat
#define tmati	$08 ;mat i
#define tmatj	$09 ;mat j

;$2nd half of user list tokens
;--------------------------------------
#define tl1	$00 ;list 1
#define tl2	$01 ;list 2
#define tl3	$02 ;list 3
#define tl4	$03 ;list 4
#define tl5	$04 ;list 5
#define tl6	$05 ;list 6

;$2nd half of user equation tokens
;----------------------------------
;  "y" equations have bit 4 set
;
#define ty1	$10 ;y1
#define ty2	$11 ;y2
#define ty3	$12 ;y3
#define ty4	$13 ;y4
#define ty5	$14 ;y5
#define ty6	$15 ;y6
#define ty7	$16 ;y7
#define ty8	$17 ;y8
#define ty9	$18 ;y9
#define ty0	$19 ;y0

;param equations have bit 5 set
;-----------------------------------
#define tx1t	$20 ;x1t
#define ty1t	$21 ;y1t
#define tx2t	$22 ;x2t
#define ty2t	$23 ;y2t
#define tx3t	$24 ;x3t
#define ty3t	$25 ;y3t
#define tx4t	$26 ;x4t
#define ty4t	$27 ;y4t
#define tx5t	$28 ;x5t
#define ty5t	$29 ;y5t
#define tx6t	$2a ;x6t
#define ty6t	$2b ;y6t

;polar equations have bit 6 set
;----------------------------------
#define tr1	$40 ;r1
#define tr2	$41 ;r2
#define tr3	$42 ;r3
#define tr4	$43 ;r4
#define tr5	$44 ;r5
#define tr6	$45 ;r6

;recursion equations have bit 7 set
;----------------------------------
#define tun	$80 ;un
#define tvn	$81 ;vn
#define twn	$82 ;wn

;$2nd half of user picture tokens
;------------------------------------
#define tpic1	$00 ;pic1
#define tpic2	$01 ;pic2
#define tpic3	$02 ;pic3
#define tpic4	$03 ;pic4
#define tpic5	$04 ;pic5
#define tpic6	$05 ;pic6
#define tpic7	$06 ;pic7
#define tpic8	$07 ;pic8
#define tpic9	$08 ;pic9
#define tpic0	$09 ;pic0

;$2nd half of user graph database tokens
;--------------------------------------
#define tgdb1	$00 ;gdb1
#define tgdb2	$01 ;gdb2
#define tgdb3	$02 ;gdb3
#define tgdb4	$03 ;gdb4
#define tgdb5	$04 ;gdb5
#define tgdb6	$05 ;gdb6
#define tgdb7	$06 ;gdb7
#define tgdb8	$07 ;gdb8
#define tgdb9	$08 ;gdb9
#define tgdb0	$09 ;gdb0

;$2nd half of string vars
;------------------------------
#define tstr1	$00
#define tstr2	$01
#define tstr3	$02
#define tstr4	$03
#define tstr5	$04
#define tstr6	$05
#define tstr7	$06
#define tstr8	$07
#define tstr9	$08
#define tstr0	$09

;$2nd half of system output only variables
;-----------------------------------------------------------------
;open	$00
#define tregeq	$01 ;regression equation
#define tstatn	$02 ;statistics n
#define txmean	$03 ;x mean
#define tsumx	$04 ;sum(x)
#define tsumxsqr	$05 ;sum(x^2)
#define tstdx	$06 ;standard dev x
#define tstdpx	$07 ;standard dev pop x
#define tminx	$08 ;min x value
#define tmaxx	$09 ;max x value
#define tminy	$0a ;min y value
#define tmaxy	$0b ;max y value
#define tymean	$0c ;y mean
#define tsumy	$0d ;sum(y)
#define tsumysqr	$0e ;sum(y^2)
#define tstdy	$0f ;standard dev y
#define tstdpy	$10 ;standard dev pop y
#define tsumxy	$11 ;sum(xy)
#define tcorr	$12 ;correlation
#define tmedx	$13 ;med(x)
#define tq1	$14 ;1st quadrant of x
#define tq3	$15 ;3rd quadrant of x
#define tquada	$16 ;1st term of quad poly reg/ y-int
#define tquadb	$17 ;2nd term of quad poly reg/ slope
#define tquadc	$18 ;3rd term of quad poly reg
#define tcubed	$19 ;4th term of cubic poly reg
#define tquarte	$1a ;5th term of quart poly reg
#define tmedx1	$1b ;x1 for med-med
#define tmedx2	$1c ;x2 for med-med
#define tmedx3	$1d ;x3 for med-med
#define tmedy1	$1e ;y1 for med-med
#define tmedy2	$1f ;y2 for med-med
#define tmedy3	$20 ;y3 for med-med
#define trecurn	$21	;recursion n
#define tstatp	$22
#define tstatz	$23
#define tstatt	$24
#define tstatchi	$25
#define tstatf	$26
#define tstatdf	$27
#define tstatphat	$28
#define tstatphat1	$29
#define tstatphat2	$2a
#define tstatmeanx1	$2b
#define tstatstdx1	$2c
#define tstatn1	$2d
#define tstatmeanx2	$2e
#define tstatstdx2	$2f
#define tstatn2	$30
#define tstatstdxp	$31
#define tstatlower	$32
#define tstatupper	$33
#define tstat_s	$34
#define tlrsqr	$35 ;r^2
#define tbrsqr	$36 ;r^2

;these next tokens are only used to access the data
;they are display only and the user cannot access them at all
;------------------------------------------------------------
#define tf_df	$37 ;anofav factor df
#define tf_ss	$38 ;anofav factor ss
#define tf_ms	$39 ;anofav factor ms
#define te_df	$3a ;anofav error df
#define te_ss	$3b ;anofav error ss
#define te_ms	$3c ;anofav error ms

;$2nd half of system input/output variables
;------------------------------------------------
;      system variable equates
;
#define tuxscl	$00
#define tuyscl	$01
#define txscl	$02
#define tyscl	$03
#define trecuru0	$04 ;u 1st initial cond
#define trecurv0	$05 ;v 1st initial cond
#define tun1	$06 ;u(n-1); not used
#define tvn1	$07 ;v(n-1); not used
#define turecuru0	$08 ;
#define turecurv0	$09 ;
#define txmin	$0a
#define txmax	$0b
#define tymin	$0c
#define tymax	$0d
#define ttmin	$0e
#define ttmax	$0f
#define tthetamin	$10
#define tthetamax	$11
#define tuxmin	$12
#define tuxmax	$13
#define tuymin	$14
#define tuymax	$15
#define tuthetmin	$16
#define tuthetmax	$17
#define tutmin	$18
#define tutmax	$19
#define ttblmin	$1a
#define tplotstart	$1b
#define tuplotstart	$1c
#define tnmax	$1d
#define tunmax	$1e
#define tnmin	$1f
#define tunmin	$20
#define ttblstep	$21
#define ttstep	$22
#define tthetastep	$23
#define tutstep	$24
#define tuthetstep	$25
#define tdeltax	$26
#define tdeltay	$27
#define txfact	$28
#define tyfact	$29
#define ttblinput	$2a
#define tfinn	$2b
#define tfini	$2c
#define tfinpv	$2d
#define tfinpmt	$2e
#define tfinfv	$2f
#define tfinpy	$30
#define tfincy	$31
#define trecurw0	$32 ;w0(1)
#define turecurw0	$33
#define tplotstep	$34
#define tuplotstep	$35
#define txres	$36
#define tuxres	$37
#define trecuru02	$38 ;u0(2)
#define turecuru02	$39
#define trecurv02	$3c ;v0(2)
#define turecurv02	$3d
#define trecurw02	$3e ;w0(2)
#define turecurw02	$3f

;$2nd byte of t2bytetok tokens
;------------------------------
#define tfinnpv	$00
#define tfinirr	$01
#define tfinbal	$02
#define tfinprn	$03
#define tfinint	$04
#define tfintonom	$05
#define tfintoeff	$06
#define tfindbd	$07
#define tlcm	$08
#define tgcd	$09
#define trandint	$0a
#define trandbin	$0b
#define tsubstrng	$0c
#define tstddev	$0d
#define tvariance	$0e
#define tinstrng	$0f
#define tdnormal	$10
#define tinvnorm	$11
#define tdt	$12
#define tchi	$13
#define tdf	$14
#define tbinpdf	$15
#define tbincdf	$16
#define tpoipdf	$17
#define tpoicdf	$18
#define tgeopdf	$19
#define tgeocdf	$1a
#define tnormalpdf	$1b
#define ttpdf	$1c
#define tchipdf	$1d
#define tfpdf	$1e
#define trandnorm	$1f
#define tfinfpmt	$20
#define tfinfi	$21
#define tfinfpv	$22
#define tfinfn	$23
#define tfinffv	$24
#define tconj	$25
#define treal	$26
#define timag	$27
#define tangle	$28
#define tcumsum	$29
#define texpr	$2a
#define tlength	$2b
#define tdeltalst	$2c
#define tref	$2d
#define trref	$2e
#define ttorect	$2f
#define ttopolar	$30
#define tconste	$31
#define tsinreg	$32
#define tlogistic	$33
#define tlinregttest	$34
#define tshadenorm	$35
#define tshadet	$36
#define tshadechi	$37
#define tshadef	$38
#define tmattolst	$39
#define tlsttomat	$3a
#define tztest	$3b
#define tttest	$3c
#define t2sampztest	$3d
#define t1propztest	$3e
#define t2propztest	$3f
#define tchitest	$40
#define tzintval	$41
#define t2sampzint	$42
#define t1propzint	$43
#define t2propzint	$44
#define tgraphstyle	$45
#define t2sampttest	$46
#define t2sampftest	$47
#define ttintval	$48
#define t2samptint	$49
#define tsetuplst	$4a
#define tfinpmtend	$4b
#define tfinpmtbeg	$4c
#define trealm	$4d
#define tpolarm	$4e
#define trectm	$4f
#define texpron	$50
#define texproff	$51
#define tclralllst	$52
#define tgetcalc	$53
#define tdelvar	$54
#define tequtostrng	$55
#define tstrngtoequ	$56
#define tdellast	$57
#define tselect	$58
#define tanova	$59
#define tmodbox	$5a
#define tnormprob	$5b
#define tmgt	$64 ;vertical split
#define tzfit	$65 ;zoom fit
#define tdiag_on	$66 ;dianostic display on
#define tdiag_off	$67 ;dianostic display off
#define tokend2v0	$67 ;end of 2byte tokens for version 0.
#define tarchive	$68 ;archive
#define tunarchive	$69 ;unarchive
#define tasm	$6a
#define tasmcomp	$6b	;asm compile
#define tasmprgm	$6c	;signifies a program is asm
#define tasmcmp	$6d	;asm program is compiled
#define tlcapaacute	$6e
#define tlcapagrave	$6f
#define tlcapacaret	$70
#define tlcapadier	$71
#define tlaacute	$72
#define tlagrave	$73
#define tlacaret	$74
#define tladier	$75
#define tlcapeacute	$76
#define tlcapegrave	$77
#define tlcapecaret	$78
#define tlcapedier	$79
#define tleacute	$7a
#define tlegrave	$7b
#define tlecaret	$7c
#define tledier	$7d
#define tlcapigrave	$7f
#define tlcapicaret	$80
#define tlcapidier	$81
#define tliacute	$82
#define tligrave	$83
#define tlicaret	$84
#define tlidier	$85
#define tlcapoacute	$86
#define tlcapograve	$87
#define tlcapocaret	$88
#define tlcapodier	$89
#define tloacute	$8a
#define tlograve	$8b
#define tlocaret	$8c
#define tlodier	$8d
#define tlcapuacute	$8e
#define tlcapugrave	$8f
#define tlcapucaret	$90
#define tlcapudier	$91
#define tluacute	$92
#define tlugrave	$93
#define tlucaret	$94
#define tludier	$95
#define tlcapcced	$96
#define tlcced	$97
#define tlcapntilde	$98
#define tlntilde	$99
#define tlaccent	$9a
#define tlgrave	$9b
#define tldieresis	$9c
#define tlquesdown	$9d
#define tlexclamdown	$9e
#define tlalpha	$9f
#define tlbeta	$a0
#define tlgamma	$a1
#define tlcapdelta	$a2
#define tldelta	$a3
#define tlepsilon	$a4
#define tllambda	$a5
#define tlmu	$a6
#define tlpi	$a7
#define tlrho	$a8
#define tlcapsigma	$a9
#define tlphi	$ab
#define tlcapomega	$ac
#define tlphat	$ad
#define tlchi	$ae
#define tlstatf	$af
#define tla	$b0
#define tlb	$b1
#define tlc	$b2
#define tld	$b3
#define tlsmalle	$b4
#define tlf	$b5
#define tlsmallg	$b6
#define tlh	$b7
#define tli	$b8
#define tlj	$b9
#define tlk	$ba
#define tll	$bc
#define tlm	$bd
#define tlsmalln	$be
#define tlo	$bf
#define tlp	$c0
#define tlq	$c1
#define tlsmallr	$c2
#define tls	$c3
#define tlsmallt	$c4
#define tlu	$c5
#define tlv	$c6
#define tlw	$c7
#define tlx	$c8
#define tly	$c9
#define tlz	$ca
#define tlsigma	$cb
#define tltau	$cc
#define tlcapiacute	$cd
#define tgarbagec	$ce
#define lasttoken	$ce ;tlast token in this version...

;data type equates
;---------------------------------------------------------------------
#define realobj	$00
#define listobj	$01
#define matobj	$02
#define equobj	$03
#define strngobj	$04
#define progobj	$05
#define protprogobj	$06
#define pictobj	$07
#define gdbobj	$08
#define unknownobj	$09
#define unknownequobj	$0a
#define newequobj	$0b
#define cplxobj	$0c
#define clistobj	$0d
#define undefobj	$0e
#define windowobj	$0f
#define zstoobj	$10
#define tblrngobj	$11
#define lcdobj	$12
#define backupobj	$13
#define appobj	$14	;application, only used in menus/link
#define appvarobj	$15	;application variable
#define tempprogobj	$16 ;program, home deletes when finished
#define groupobj	$17 ;group.

;i/o equates
;---------------------------------------------------
#define d0d1_bits	$03
#define d0ld1l	$03
#define d0ld1	$01
#define d0d1l	$02
#define d0d1	$00
#define bport	$00 ;$4-bit link port (i/o)

;device codes
;-----------------------------------------------------------------
#define ti82dev	$82
#define pc82dev	$02
#define mac82dev	$12
#define ti83fdev	$73
#define link83fdev	$23
#define ti83dev	$83
#define pc83dev	$03
#define mac83dev	$13
#define ti85dev	$95 ;different than real 85 so me talk
#define pc85dev	$05
#define mac85dev	$15
#define ti73dev	$74 ;device x3 is always an 83
#define pc73dev	$07
#define mac73dev	$17
#define link73fdev	$23
#define pc83fdev	$23

;system error codes
;-----------------------------------------------------------
#define e_editf	7 ;allow re-entering application
#define e_edit	1<<e_editf
#define e_mask	$7f
#define e_overflow	1+e_edit
#define e_divby0	2+e_edit
#define e_singularmat	3+e_edit
#define e_domain	4+e_edit
#define e_increment	5+e_edit
#define e_break	6+e_edit
#define e_nonreal	7+e_edit
#define e_syntax	8+e_edit
#define e_datatype	9+e_edit
#define e_argument	10+e_edit
#define e_dimmismatch	11+e_edit
#define e_dimension	12+e_edit
#define e_undefined	13+e_edit
#define e_memory	14+e_edit
#define e_invalid	15+e_edit
#define e_illegalnest	16+e_edit
#define e_bound	17+e_edit
#define e_graphrange	18+e_edit
#define e_zoom	19+e_edit
#define e_label	20
#define e_stat	21
#define e_solver	22+e_edit
#define e_singularity	23+e_edit
#define e_signchange	24+e_edit
#define e_iterations	25+e_edit
#define e_badguess	26+e_edit
#define e_statplo	27
#define e_toltoosmall	28+e_edit
#define e_reserved	29+e_edit
#define e_mode	30+e_edit
#define e_lnkerr	31+e_edit
#define e_lnkmemerr	32+e_edit
#define e_lnktranserr	33+e_edit
#define e_lnkduperr	34+e_edit
#define e_lnkmemfull	35+e_edit
#define e_unknown	36+e_edit
#define e_scale	37+e_edit
#define e_idnotfound	38
#define e_nomode	39+e_edit
#define e_validation	40
#define e_length	41+e_edit
#define e_application	42+e_edit
#define e_apperr1	43+e_edit
#define e_apperr2	44+e_edit
#define e_expiredapp	45
#define e_badadd	46
#define e_archived	47+e_edit
#define e_version	48
#define e_archfull	49
#define e_variable	50+e_edit
#define e_duplicate	51+e_edit
#define higerrnum	51
;obsolete error numbers 34 ;first link error
#define e_linkiochksum	34
#define e_linkiotimeout	35
#define e_linkiobusy	36
#define e_linkiover	37

;equates to ram locations for stat vars
;----------------------------------------------------------------
#define fplen	9 ;length of a floating-point number.
#define statn	statvars
#define xmean	statn+fplen
#define sumx	xmean+fplen
#define sumxsqr	sumx+fplen
#define stdx	sumxsqr+fplen
#define stdpx	stdx+fplen
#define minx	stdpx+fplen
#define maxx	minx+fplen
#define miny	maxx+fplen
#define maxy	miny+fplen
#define ymean	maxy+fplen
#define sumy	ymean+fplen
#define sumysqr	sumy+fplen
#define stdy	sumysqr+fplen
#define stdpy	stdy+fplen
#define sumxy	stdpy+fplen
#define corr	sumxy+fplen
#define medx	corr+fplen
#define q1	medx+fplen
#define q3	q1+fplen
#define quada	q3+fplen
#define quadb	quada+fplen
#define quadc	quadb+fplen
#define cubed	quadc+fplen
#define quarte	cubed+fplen
#define medx1	quarte+fplen
#define medx2	medx1+fplen
#define medx3	medx2+fplen
#define medy1	medx3+fplen
#define medy2	medy1+fplen
#define medy3	medy2+fplen
#define pstat	medy3+2*fplen
#define zstat	pstat+fplen
#define tstat	zstat+fplen
#define chistat	tstat+fplen
#define fstat	chistat+fplen
#define df	fstat+fplen
#define phat	df+fplen
#define phat1	phat+fplen
#define phat2	phat1+fplen
#define meanx1	phat2+fplen
#define stdx1	meanx1+fplen
#define statn1	stdx1+fplen
#define meanx2	statn1+fplen
#define stdx2	meanx2+fplen
#define statn2	stdx2+fplen
#define stdxp2	statn2+fplen
#define slower	stdxp2+fplen
#define supper	slower+fplen
#define sstat	supper+fplen
#define f_df	anovaf_vars
#define f_ss	f_df+fplen
#define f_ms	f_ss+fplen
#define e_df	f_ms+fplen
#define e_ss	e_df+fplen
#define e_ms	e_ss+fplen
