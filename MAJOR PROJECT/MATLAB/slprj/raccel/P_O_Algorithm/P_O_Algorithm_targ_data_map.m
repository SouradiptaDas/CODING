  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 69;
      section.data(69)  = dumData; %prealloc
      
	  ;% rtP.Battery_BatType
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.PVArray_Npar
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.PVArray_Nser
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Battery_SOC
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.RepeatingSequence_rep_seq_y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.SwitchCurrents_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.Constant1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtP.Constant_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtP.itinit1_InitialCondition
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtP.R2_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% rtP.Currentfilter_NumCoef
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% rtP.Currentfilter_DenCoef
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% rtP.Currentfilter_InitialStates
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtP.Constant_Value_n3bn4aqtv0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtP.inti_gainval
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtP.inti_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtP.inti_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtP.Gain_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtP.Constant9_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtP.Constant4_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtP.R3_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtP.Constant_Value_iuuok2jfzc
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rtP.Constant1_Value_drkiaq15p3
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% rtP.Constant3_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% rtP.Constant2_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% rtP.DiscreteTimeIntegrator_gainval
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% rtP.Memory2_InitialCondition
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% rtP.Temperature_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% rtP.u_K_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% rtP.Tref_K_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% rtP.alpha_Isc_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% rtP.IL_module_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% rtP.Irradiance_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
	  ;% rtP.uSref_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 39;
	
	  ;% rtP.UnitDelay_InitialCondition
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 40;
	
	  ;% rtP.eee_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 41;
	
	  ;% rtP.StateSpace_AS_param
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 42;
	
	  ;% rtP.StateSpace_BS_param
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 58;
	
	  ;% rtP.StateSpace_CS_param
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 86;
	
	  ;% rtP.StateSpace_DS_param
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 110;
	
	  ;% rtP.StateSpace_X0_param
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 152;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 156;
	
	  ;% rtP.UnitDelay_InitialCondition_hsukbc1fti
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 157;
	
	  ;% rtP.UnitDelay1_InitialCondition
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 158;
	
	  ;% rtP.R4_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 159;
	
	  ;% rtP.Saturation_UpperSat_gfnwdnhivs
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 160;
	
	  ;% rtP.Saturation_LowerSat_ofwy2u1vqp
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 161;
	
	  ;% rtP.R_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 162;
	
	  ;% rtP.donotdeletethisgain_Gain_aicr253wuj
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 163;
	
	  ;% rtP.Constant12_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 164;
	
	  ;% rtP.Constant_Value_jqsaqx4mlv
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 165;
	
	  ;% rtP.Gain4_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 166;
	
	  ;% rtP.Gain1_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 167;
	
	  ;% rtP.Gain2_Gain
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 168;
	
	  ;% rtP.R1_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 169;
	
	  ;% rtP.Constant_Value_g20vuihr23
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 170;
	
	  ;% rtP.LookUpTable1_bp01Data
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 171;
	
	  ;% rtP.donotdeletethisgain_Gain_oumtwrk3lg
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 173;
	
	  ;% rtP.Tref_K2_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 174;
	
	  ;% rtP.one_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 175;
	
	  ;% rtP.EgRef_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 176;
	
	  ;% rtP.one1_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 177;
	
	  ;% rtP.Tref_K1_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 178;
	
	  ;% rtP.dEgdT_Gain
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 179;
	
	  ;% rtP.EgRef_Gain
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 180;
	
	  ;% rtP.k1_Gain
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 181;
	
	  ;% rtP.Rsh_array_5Sref_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 182;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% rtB.d0bpobslze
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ljtvghxtux
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.koobqpf22y
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.n5qsf2ppfq
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.lygq3ygt2j
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.bsarhrs4kr
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.e32yfly1mg
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.lqkgfyhkru
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.a0f1utn1ur
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.ngemnoz21l
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.eunl3qcjlh
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.npzp2nktgj
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.mxi5esqlco
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.hsenihq3bi
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% rtB.em2nnuuz40
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% rtB.fbx0qo0g3f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% rtB.iabhbltntc
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% rtB.hilvlxo5dw
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% rtB.h42gj14eth
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
	  ;% rtB.kvt5zhgzbi
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 26;
	
	  ;% rtB.okf5iwwvho
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 27;
	
	  ;% rtB.iwtvfahc01
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 28;
	
	  ;% rtB.h5bixvn1me
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 29;
	
	  ;% rtB.dpwivq0fds
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 30;
	
	  ;% rtB.iedo3uzdki
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 31;
	
	  ;% rtB.jdiw3tifo0
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 32;
	
	  ;% rtB.hzgt3pwgdg
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 33;
	
	  ;% rtB.dfm0cs3350
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 34;
	
	  ;% rtB.n5yaxbsj3n
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% rtB.f1zgdmvpbp
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 36;
	
	  ;% rtB.adwlkt4aji
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% rtDW.knu05efaia
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ocfkalkmt1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.kzb1bipvzc
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kxq3i3a5e0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ba0fhn43mf
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ef5gie5krl
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.mpwvjztsbx
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.fccnxrfig4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtDW.dtaijnbgzm
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtDW.oz5r5rhz1r
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtDW.gxtljmpzqd
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtDW.bojdogcykn
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% rtDW.gnlmv2t1lw
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.kfvpshvioz.AS
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lkeccsk1xw.LoggedData
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jmio3su4bh
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.hvnlljol2x
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.mnxr2r3vae
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.gvp50ey4nq
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3620723121;
  targMap.checksum1 = 3273175510;
  targMap.checksum2 = 974960485;
  targMap.checksum3 = 1462179910;

