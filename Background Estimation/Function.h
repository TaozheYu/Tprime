void Estimation(char CUT_prov[1000], char muo1_prov[1000], char muo2_prov[1000], char ele1_prov[1000], char ele2_prov[1000], char trm1_prov[1000], char trm2_prov[1000], char tre1_prov[1000], char tre2_prov[1000], char bta1_prov[1000], char bta2_prov[1000], char pup1_prov[1000], char pup2_prov[1000], char wje1_prov[1000], char wje2_prov[1000], char top1_prov[1000], char top2_prov[1000], char for1_prov[1000], char for2_prov[1000], char zj1_prov[1000], char zj2_prov[1000], char clos_prov[1000], int category, int forward, TH1F *histo_PRE, TH1F *histo_PREup, TH1F *histo_PREdo, TH1F *histo_DAT, TH1F *ERR, THStack *hs, bool save){
  //char plot = "ZPt";
  int bin=1; 
  float min=0; 
  float MAX=50000; 
  int A1=-1; int A2=0;
  for(int i=0; i<N-1; i++){
    A1=A1+1;
    A2=A2+1;
    char   CUT[1000]; sprintf(CUT, "%s&&TprimeMass>%f&&TprimeMass<%f)",CUT_prov ,xbins[A1],xbins[A2]);
    char  muo1[1000]; sprintf(muo1,"%s&&TprimeMass>%f&&TprimeMass<%f)",muo1_prov,xbins[A1],xbins[A2]);
    char  muo2[1000]; sprintf(muo2,"%s&&TprimeMass>%f&&TprimeMass<%f)",muo2_prov,xbins[A1],xbins[A2]);
    char  ele1[1000]; sprintf(ele1,"%s&&TprimeMass>%f&&TprimeMass<%f)",ele1_prov,xbins[A1],xbins[A2]);
    char  ele2[1000]; sprintf(ele2,"%s&&TprimeMass>%f&&TprimeMass<%f)",ele2_prov,xbins[A1],xbins[A2]);
    char  trm1[1000]; sprintf(trm1,"%s&&TprimeMass>%f&&TprimeMass<%f)",trm1_prov,xbins[A1],xbins[A2]);
    char  trm2[1000]; sprintf(trm2,"%s&&TprimeMass>%f&&TprimeMass<%f)",trm2_prov,xbins[A1],xbins[A2]);
    char  tre1[1000]; sprintf(tre1,"%s&&TprimeMass>%f&&TprimeMass<%f)",tre1_prov,xbins[A1],xbins[A2]);
    char  tre2[1000]; sprintf(tre2,"%s&&TprimeMass>%f&&TprimeMass<%f)",tre2_prov,xbins[A1],xbins[A2]);
    char  bta1[1000]; sprintf(bta1,"%s&&TprimeMass>%f&&TprimeMass<%f)",bta1_prov,xbins[A1],xbins[A2]);
    char  bta2[1000]; sprintf(bta2,"%s&&TprimeMass>%f&&TprimeMass<%f)",bta2_prov,xbins[A1],xbins[A2]);
    char  pup1[1000]; sprintf(pup1,"%s&&TprimeMass>%f&&TprimeMass<%f)",pup1_prov,xbins[A1],xbins[A2]);
    char  pup2[1000]; sprintf(pup2,"%s&&TprimeMass>%f&&TprimeMass<%f)",pup2_prov,xbins[A1],xbins[A2]);
    char  wje1[1000]; sprintf(wje1,"%s&&TprimeMass>%f&&TprimeMass<%f)",wje1_prov,xbins[A1],xbins[A2]);
    char  wje2[1000]; sprintf(wje2,"%s&&TprimeMass>%f&&TprimeMass<%f)",wje2_prov,xbins[A1],xbins[A2]);
    char  top1[1000]; sprintf(top1,"%s&&TprimeMass>%f&&TprimeMass<%f)",top1_prov,xbins[A1],xbins[A2]);
    char  top2[1000]; sprintf(top2,"%s&&TprimeMass>%f&&TprimeMass<%f)",top2_prov,xbins[A1],xbins[A2]);
    char  for1[1000]; sprintf(for1,"%s&&TprimeMass>%f&&TprimeMass<%f)",for1_prov,xbins[A1],xbins[A2]);
    char  for2[1000]; sprintf(for2,"%s&&TprimeMass>%f&&TprimeMass<%f)",for2_prov,xbins[A1],xbins[A2]);
    char   zj1[1000]; sprintf(zj1, "%s&&TprimeMass>%f&&TprimeMass<%f)",zj1_prov ,xbins[A1],xbins[A2]);
    char   zj2[1000]; sprintf(zj2, "%s&&TprimeMass>%f&&TprimeMass<%f)",zj2_prov ,xbins[A1],xbins[A2]);
    char  clos[1000]; sprintf(clos,"%s&&TprimeMass>%f&&TprimeMass<%f)",clos_prov,xbins[A1],xbins[A2]);
    MakeHistos(CUT,0,"TprimeMass",i,1,xbins[A1],xbins[A2], category,Nsb,     Alpha,     histo_PRE,     histo_PREup,     histo_PREdo,     histo_DAT,     DY,     SINGLETOP,     TTbar,     TTV,     DIBOSON,     tptzm0700lh,     tptzm0800lh,     tptzm0900lh,     tptzm1000lh,     tptzm1100lh,     tptzm1200lh,     tptzm1300lh,     tptzm1400lh,     tptzm1500lh,     tptzm1600lh,     tptzm1700lh,     ERR);
    MakeHistos(muo1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_muo1,Alpha_muo1,histo_PRE_muo1,histo_PREup_muo1,histo_PREdo_muo1,histo_DAT_muo1,DY_muo1,SINGLETOP_muo1,TTbar_muo1,TTV_muo1,DIBOSON_muo1,tptzm0700lh_muo1,tptzm0800lh_muo1,tptzm0900lh_muo1,tptzm1000lh_muo1,tptzm1100lh_muo1,tptzm1200lh_muo1,tptzm1300lh_muo1,tptzm1400lh_muo1,tptzm1500lh_muo1,tptzm1600lh_muo1,tptzm1700lh_muo1,ERR_muo1);
    MakeHistos(muo2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_muo2,Alpha_muo2,histo_PRE_muo2,histo_PREup_muo2,histo_PREdo_muo2,histo_DAT_muo2,DY_muo2,SINGLETOP_muo2,TTbar_muo2,TTV_muo2,DIBOSON_muo2,tptzm0700lh_muo2,tptzm0800lh_muo2,tptzm0900lh_muo2,tptzm1000lh_muo2,tptzm1100lh_muo2,tptzm1200lh_muo2,tptzm1300lh_muo2,tptzm1400lh_muo2,tptzm1500lh_muo2,tptzm1600lh_muo2,tptzm1700lh_muo2,ERR_muo2);
    MakeHistos(ele1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_ele1,Alpha_ele1,histo_PRE_ele1,histo_PREup_ele1,histo_PREdo_ele1,histo_DAT_ele1,DY_ele1,SINGLETOP_ele1,TTbar_ele1,TTV_ele1,DIBOSON_ele1,tptzm0700lh_ele1,tptzm0800lh_ele1,tptzm0900lh_ele1,tptzm1000lh_ele1,tptzm1100lh_ele1,tptzm1200lh_ele1,tptzm1300lh_ele1,tptzm1400lh_ele1,tptzm1500lh_ele1,tptzm1600lh_ele1,tptzm1700lh_ele1,ERR_ele1);
    MakeHistos(ele2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_ele2,Alpha_ele2,histo_PRE_ele2,histo_PREup_ele2,histo_PREdo_ele2,histo_DAT_ele2,DY_ele2,SINGLETOP_ele2,TTbar_ele2,TTV_ele2,DIBOSON_ele2,tptzm0700lh_ele2,tptzm0800lh_ele2,tptzm0900lh_ele2,tptzm1000lh_ele2,tptzm1100lh_ele2,tptzm1200lh_ele2,tptzm1300lh_ele2,tptzm1400lh_ele2,tptzm1500lh_ele2,tptzm1600lh_ele2,tptzm1700lh_ele2,ERR_ele2);
    MakeHistos(trm1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_trm1,Alpha_trm1,histo_PRE_trm1,histo_PREup_trm1,histo_PREdo_trm1,histo_DAT_trm1,DY_trm1,SINGLETOP_trm1,TTbar_trm1,TTV_trm1,DIBOSON_trm1,tptzm0700lh_trm1,tptzm0800lh_trm1,tptzm0900lh_trm1,tptzm1000lh_trm1,tptzm1100lh_trm1,tptzm1200lh_trm1,tptzm1300lh_trm1,tptzm1400lh_trm1,tptzm1500lh_trm1,tptzm1600lh_trm1,tptzm1700lh_trm1,ERR_trm1);
    MakeHistos(trm2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_trm2,Alpha_trm2,histo_PRE_trm2,histo_PREup_trm2,histo_PREdo_trm2,histo_DAT_trm2,DY_trm2,SINGLETOP_trm2,TTbar_trm2,TTV_trm2,DIBOSON_trm2,tptzm0700lh_trm2,tptzm0800lh_trm2,tptzm0900lh_trm2,tptzm1000lh_trm2,tptzm1100lh_trm2,tptzm1200lh_trm2,tptzm1300lh_trm2,tptzm1400lh_trm2,tptzm1500lh_trm2,tptzm1600lh_trm2,tptzm1700lh_trm2,ERR_trm2);
    MakeHistos(tre1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_tre1,Alpha_tre1,histo_PRE_tre1,histo_PREup_tre1,histo_PREdo_tre1,histo_DAT_tre1,DY_tre1,SINGLETOP_tre1,TTbar_tre1,TTV_tre1,DIBOSON_tre1,tptzm0700lh_tre1,tptzm0800lh_tre1,tptzm0900lh_tre1,tptzm1000lh_tre1,tptzm1100lh_tre1,tptzm1200lh_tre1,tptzm1300lh_tre1,tptzm1400lh_tre1,tptzm1500lh_tre1,tptzm1600lh_tre1,tptzm1700lh_tre1,ERR_tre1);
    MakeHistos(tre2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_tre2,Alpha_tre2,histo_PRE_tre2,histo_PREup_tre2,histo_PREdo_tre2,histo_DAT_tre2,DY_tre2,SINGLETOP_tre2,TTbar_tre2,TTV_tre2,DIBOSON_tre2,tptzm0700lh_tre2,tptzm0800lh_tre2,tptzm0900lh_tre2,tptzm1000lh_tre2,tptzm1100lh_tre2,tptzm1200lh_tre2,tptzm1300lh_tre2,tptzm1400lh_tre2,tptzm1500lh_tre2,tptzm1600lh_tre2,tptzm1700lh_tre2,ERR_tre2);
    MakeHistos(bta1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_bta1,Alpha_bta1,histo_PRE_bta1,histo_PREup_bta1,histo_PREdo_bta1,histo_DAT_bta1,DY_bta1,SINGLETOP_bta1,TTbar_bta1,TTV_bta1,DIBOSON_bta1,tptzm0700lh_bta1,tptzm0800lh_bta1,tptzm0900lh_bta1,tptzm1000lh_bta1,tptzm1100lh_bta1,tptzm1200lh_bta1,tptzm1300lh_bta1,tptzm1400lh_bta1,tptzm1500lh_bta1,tptzm1600lh_bta1,tptzm1700lh_bta1,ERR_bta1);
    MakeHistos(bta2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_bta2,Alpha_bta2,histo_PRE_bta2,histo_PREup_bta2,histo_PREdo_bta2,histo_DAT_bta2,DY_bta2,SINGLETOP_bta2,TTbar_bta2,TTV_bta2,DIBOSON_bta2,tptzm0700lh_bta2,tptzm0800lh_bta2,tptzm0900lh_bta2,tptzm1000lh_bta2,tptzm1100lh_bta2,tptzm1200lh_bta2,tptzm1300lh_bta2,tptzm1400lh_bta2,tptzm1500lh_bta2,tptzm1600lh_bta2,tptzm1700lh_bta2,ERR_bta2);
    MakeHistos(pup1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_pup1,Alpha_pup1,histo_PRE_pup1,histo_PREup_pup1,histo_PREdo_pup1,histo_DAT_pup1,DY_pup1,SINGLETOP_pup1,TTbar_pup1,TTV_pup1,DIBOSON_pup1,tptzm0700lh_pup1,tptzm0800lh_pup1,tptzm0900lh_pup1,tptzm1000lh_pup1,tptzm1100lh_pup1,tptzm1200lh_pup1,tptzm1300lh_pup1,tptzm1400lh_pup1,tptzm1500lh_pup1,tptzm1600lh_pup1,tptzm1700lh_pup1,ERR_pup1);
    MakeHistos(pup2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_pup2,Alpha_pup2,histo_PRE_pup2,histo_PREup_pup2,histo_PREdo_pup2,histo_DAT_pup2,DY_pup2,SINGLETOP_pup2,TTbar_pup2,TTV_pup2,DIBOSON_pup2,tptzm0700lh_pup2,tptzm0800lh_pup2,tptzm0900lh_pup2,tptzm1000lh_pup2,tptzm1100lh_pup2,tptzm1200lh_pup2,tptzm1300lh_pup2,tptzm1400lh_pup2,tptzm1500lh_pup2,tptzm1600lh_pup2,tptzm1700lh_pup2,ERR_pup2);
    MakeHistos(CUT,1,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_jes1,Alpha_jes1,histo_PRE_jes1,histo_PREup_jes1,histo_PREdo_jes1,histo_DAT_jes1,DY_jes1,SINGLETOP_jes1,TTbar_jes1,TTV_jes1,DIBOSON_jes1,tptzm0700lh_jes1,tptzm0800lh_jes1,tptzm0900lh_jes1,tptzm1000lh_jes1,tptzm1100lh_jes1,tptzm1200lh_jes1,tptzm1300lh_jes1,tptzm1400lh_jes1,tptzm1500lh_jes1,tptzm1600lh_jes1,tptzm1700lh_jes1,ERR_jes1);
    MakeHistos(CUT,2,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_jes2,Alpha_jes2,histo_PRE_jes2,histo_PREup_jes2,histo_PREdo_jes2,histo_DAT_jes2,DY_jes2,SINGLETOP_jes2,TTbar_jes2,TTV_jes2,DIBOSON_jes2,tptzm0700lh_jes2,tptzm0800lh_jes2,tptzm0900lh_jes2,tptzm1000lh_jes2,tptzm1100lh_jes2,tptzm1200lh_jes2,tptzm1300lh_jes2,tptzm1400lh_jes2,tptzm1500lh_jes2,tptzm1600lh_jes2,tptzm1700lh_jes2,ERR_jes2);
    MakeHistos(CUT,3,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_jer1,Alpha_jer1,histo_PRE_jer1,histo_PREup_jer1,histo_PREdo_jer1,histo_DAT_jer1,DY_jer1,SINGLETOP_jer1,TTbar_jer1,TTV_jer1,DIBOSON_jer1,tptzm0700lh_jer1,tptzm0800lh_jer1,tptzm0900lh_jer1,tptzm1000lh_jer1,tptzm1100lh_jer1,tptzm1200lh_jer1,tptzm1300lh_jer1,tptzm1400lh_jer1,tptzm1500lh_jer1,tptzm1600lh_jer1,tptzm1700lh_jer1,ERR_jer1);
    MakeHistos(CUT,4,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_jer2,Alpha_jer2,histo_PRE_jer2,histo_PREup_jer2,histo_PREdo_jer2,histo_DAT_jer2,DY_jer2,SINGLETOP_jer2,TTbar_jer2,TTV_jer2,DIBOSON_jer2,tptzm0700lh_jer2,tptzm0800lh_jer2,tptzm0900lh_jer2,tptzm1000lh_jer2,tptzm1100lh_jer2,tptzm1200lh_jer2,tptzm1300lh_jer2,tptzm1400lh_jer2,tptzm1500lh_jer2,tptzm1600lh_jer2,tptzm1700lh_jer2,ERR_jer2);
    MakeHistos(wje1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_wje1,Alpha_wje1,histo_PRE_wje1,histo_PREup_wje1,histo_PREdo_wje1,histo_DAT_wje1,DY_wje1,SINGLETOP_wje1,TTbar_wje1,TTV_wje1,DIBOSON_wje1,tptzm0700lh_wje1,tptzm0800lh_wje1,tptzm0900lh_wje1,tptzm1000lh_wje1,tptzm1100lh_wje1,tptzm1200lh_wje1,tptzm1300lh_wje1,tptzm1400lh_wje1,tptzm1500lh_wje1,tptzm1600lh_wje1,tptzm1700lh_wje1,ERR_wje1);
    MakeHistos(wje2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_wje2,Alpha_wje2,histo_PRE_wje2,histo_PREup_wje2,histo_PREdo_wje2,histo_DAT_wje2,DY_wje2,SINGLETOP_wje2,TTbar_wje2,TTV_wje2,DIBOSON_wje2,tptzm0700lh_wje2,tptzm0800lh_wje2,tptzm0900lh_wje2,tptzm1000lh_wje2,tptzm1100lh_wje2,tptzm1200lh_wje2,tptzm1300lh_wje2,tptzm1400lh_wje2,tptzm1500lh_wje2,tptzm1600lh_wje2,tptzm1700lh_wje2,ERR_wje2);
    MakeHistos(top1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_top1,Alpha_top1,histo_PRE_top1,histo_PREup_top1,histo_PREdo_top1,histo_DAT_top1,DY_top1,SINGLETOP_top1,TTbar_top1,TTV_top1,DIBOSON_top1,tptzm0700lh_top1,tptzm0800lh_top1,tptzm0900lh_top1,tptzm1000lh_top1,tptzm1100lh_top1,tptzm1200lh_top1,tptzm1300lh_top1,tptzm1400lh_top1,tptzm1500lh_top1,tptzm1600lh_top1,tptzm1700lh_top1,ERR_top1);
    MakeHistos(top2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_top2,Alpha_top2,histo_PRE_top2,histo_PREup_top2,histo_PREdo_top2,histo_DAT_top2,DY_top2,SINGLETOP_top2,TTbar_top2,TTV_top2,DIBOSON_top2,tptzm0700lh_top2,tptzm0800lh_top2,tptzm0900lh_top2,tptzm1000lh_top2,tptzm1100lh_top2,tptzm1200lh_top2,tptzm1300lh_top2,tptzm1400lh_top2,tptzm1500lh_top2,tptzm1600lh_top2,tptzm1700lh_top2,ERR_top2);
    MakeHistos(for1,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_for1,Alpha_for1,histo_PRE_for1,histo_PREup_for1,histo_PREdo_for1,histo_DAT_for1,DY_for1,SINGLETOP_for1,TTbar_for1,TTV_for1,DIBOSON_for1,tptzm0700lh_for1,tptzm0800lh_for1,tptzm0900lh_for1,tptzm1000lh_for1,tptzm1100lh_for1,tptzm1200lh_for1,tptzm1300lh_for1,tptzm1400lh_for1,tptzm1500lh_for1,tptzm1600lh_for1,tptzm1700lh_for1,ERR_for1);
    MakeHistos(for2,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_for2,Alpha_for2,histo_PRE_for2,histo_PREup_for2,histo_PREdo_for2,histo_DAT_for2,DY_for2,SINGLETOP_for2,TTbar_for2,TTV_for2,DIBOSON_for2,tptzm0700lh_for2,tptzm0800lh_for2,tptzm0900lh_for2,tptzm1000lh_for2,tptzm1100lh_for2,tptzm1200lh_for2,tptzm1300lh_for2,tptzm1400lh_for2,tptzm1500lh_for2,tptzm1600lh_for2,tptzm1700lh_for2,ERR_for2);
    //MakeHistos(zj1 ,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_zje1,Alpha_zje1,histo_PRE_zje1,histo_PREup_zje1,histo_PREdo_zje1,histo_DAT_zje1,DY_zje1,SINGLETOP_zje1,TTbar_zje1,TTV_zje1,DIBOSON_zje1,tptzm0700lh_zje1,tptzm0800lh_zje1,tptzm0900lh_zje1,tptzm1000lh_zje1,tptzm1100lh_zje1,tptzm1200lh_zje1,tptzm1300lh_zje1,tptzm1400lh_zje1,tptzm1500lh_zje1,tptzm1600lh_zje1,tptzm1700lh_zje1,ERR_zje1);
    //MakeHistos(zj2 ,0,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_zje2,Alpha_zje2,histo_PRE_zje2,histo_PREup_zje2,histo_PREdo_zje2,histo_DAT_zje2,DY_zje2,SINGLETOP_zje2,TTbar_zje2,TTV_zje2,DIBOSON_zje2,tptzm0700lh_zje2,tptzm0800lh_zje2,tptzm0900lh_zje2,tptzm1000lh_zje2,tptzm1100lh_zje2,tptzm1200lh_zje2,tptzm1300lh_zje2,tptzm1400lh_zje2,tptzm1500lh_zje2,tptzm1600lh_zje2,tptzm1700lh_zje2,ERR_zje2);
    MakeHistosZjet(CUT,zj1,zj2,"TprimeMass",i,1,xbins[A1],xbins[A2],category, DY_SR_zje1, DY_SB_zje1, DY_SR_zje2, DY_SB_zje2, data_SB_zjet, TTV_SB_zjet, TTbar_SB_zjet, DIBOSON_SB_zjet, SINGLETOP_SB_zjet);
    MakeHistos(clos,5,"TprimeMass",i,1,xbins[A1],xbins[A2],category,Nsb_clo1,Alpha_clo1,histo_PRE_clo1,histo_PREup_clo1,histo_PREdo_clo1,histo_DAT_clo1,DY_clo1,SINGLETOP_clo1,TTbar_clo1,TTV_clo1,DIBOSON_clo1,tptzm0700lh_clo1,tptzm0800lh_clo1,tptzm0900lh_clo1,tptzm1000lh_clo1,tptzm1100lh_clo1,tptzm1200lh_clo1,tptzm1300lh_clo1,tptzm1400lh_clo1,tptzm1500lh_clo1,tptzm1600lh_clo1,tptzm1700lh_clo1,ERR_clo1);
    MakeHistosPdfQcd(CUT,"TprimeMass",i,1,xbins[A1],xbins[A2],category,111,213,tptzm0700lh_pdf1,tptzm0800lh_pdf1,tptzm0900lh_pdf1,tptzm1000lh_pdf1,tptzm1100lh_pdf1,tptzm1200lh_pdf1,
    		     tptzm1300lh_pdf1,tptzm1400lh_pdf1,tptzm1500lh_pdf1,tptzm1600lh_pdf1,tptzm1700lh_pdf1,tptzm0700lh_pdf2,tptzm0800lh_pdf2,tptzm0900lh_pdf2,tptzm1000lh_pdf2,
    		     tptzm1100lh_pdf2,tptzm1200lh_pdf2,tptzm1300lh_pdf2,tptzm1400lh_pdf2,tptzm1500lh_pdf2,tptzm1600lh_pdf2,tptzm1700lh_pdf2);
    MakeHistosPdfQcd(CUT,"TprimeMass",i,1,xbins[A1],xbins[A2],category,0,8,tptzm0700lh_qcd1,tptzm0800lh_qcd1,tptzm0900lh_qcd1,tptzm1000lh_qcd1,tptzm1100lh_qcd1,tptzm1200lh_qcd1,
    		     tptzm1300lh_qcd1,tptzm1400lh_qcd1,tptzm1500lh_qcd1,tptzm1600lh_qcd1,tptzm1700lh_qcd1,tptzm0700lh_qcd2,tptzm0800lh_qcd2,tptzm0900lh_qcd2,tptzm1000lh_qcd2,
    		     tptzm1100lh_qcd2,tptzm1200lh_qcd2,tptzm1300lh_qcd2,tptzm1400lh_qcd2,tptzm1500lh_qcd2,tptzm1600lh_qcd2,tptzm1700lh_qcd2);
  }
  ZjetSYST();
  ClosureTestSYST();
  histo_PRE2=(TH1F*)histo_PRE->Clone();
  for(int m=1; m<ERR->GetNbinsX()+1; m++){ 
    MakeHistoErrors(m, histo_PRE2, histo_PREup, histo_PREdo, histo_PRE_bta1, histo_PRE_bta2, histo_PRE_zje1, histo_PRE_zje2, histo_PRE_clo1, histo_PRE_clo2);//计算使用alpha方法所造成的误差
  }
  double DYYield_errStat     = 0.; double DYYield          = DY         ->IntegralAndError(1,N-1,DYYield_errStat); 
  double STYield_errStat     = 0.; double STYield          = SINGLETOP  ->IntegralAndError(1,N-1,STYield_errStat); 
  double TTYield_errStat     = 0.; double TTYield          = TTbar      ->IntegralAndError(1,N-1,TTYield_errStat); 
  double TTVYield_errStat    = 0.; double TTVYield         = TTV        ->IntegralAndError(1,N-1,TTVYield_errStat); 
  double VVYield_errStat     = 0.; double VVYield          = DIBOSON    ->IntegralAndError(1,N-1,VVYield_errStat); 
  double tptzm0800lh_errStat = 0.; double tptzm0800lhYield = tptzm0800lh->IntegralAndError(1,N-1,tptzm0800lh_errStat); 
  double tptzm1600lh_errStat = 0.; double tptzm1600lhYield = tptzm1600lh->IntegralAndError(1,N-1,tptzm1600lh_errStat); 
  double tptzm1700lh_errStat = 0.; double tptzm1700lhYield = tptzm1700lh->IntegralAndError(1,N-1,tptzm1700lh_errStat); 
  double N1_errStat = 0.;          double N1               = histo_PRE2 ->IntegralAndError(1,N-1,N1_errStat); 
  double N2_errStat = 0.;          double N2               = ERR        ->IntegralAndError(1,N-1,N2_errStat);
  double N3_errStat = 0.;          double N3               = histo_DAT  ->IntegralAndError(1,N-1,N3_errStat);
  for(int m=1; m<ERR->GetNbinsX()+1; m++){ 
    MakeHistoErrorsMC(m, ERR, ERR_muo1, ERR_muo2, ERR_ele1, ERR_ele2, ERR_trm1, ERR_trm2, ERR_tre1, ERR_tre2, ERR_pup1, ERR_pup2, ERR_bta1, ERR_bta2, ERR_wje1, ERR_wje2, ERR_top1, ERR_top2, ERR_for1, ERR_for2, ERR_jes1, ERR_jes2, ERR_jer1, ERR_jer2);
    MakeHistoErrorsMC(m, DY, DY_muo1, DY_muo2, DY_ele1, DY_ele2, DY_trm1, DY_trm2, DY_tre1, DY_tre2, DY_pup1, DY_pup2, DY_bta1, DY_bta2, DY_wje1, DY_wje2, DY_top1, DY_top2, DY_for1, DY_for2, DY_jes1, DY_jes2, DY_jer1, DY_jer2);
    MakeHistoErrorsMC(m, SINGLETOP, SINGLETOP_muo1, SINGLETOP_muo2, SINGLETOP_ele1, SINGLETOP_ele2, SINGLETOP_trm1, SINGLETOP_trm2, SINGLETOP_tre1, SINGLETOP_tre2, SINGLETOP_pup1, SINGLETOP_pup2, SINGLETOP_bta1, SINGLETOP_bta2, SINGLETOP_wje1, SINGLETOP_wje2, SINGLETOP_top1, SINGLETOP_top2, SINGLETOP_for1, SINGLETOP_for2, SINGLETOP_jes1, SINGLETOP_jes2, SINGLETOP_jer1, SINGLETOP_jer2);
    MakeHistoErrorsMC(m, TTbar, TTbar_muo1, TTbar_muo2, TTbar_ele1, TTbar_ele2, TTbar_trm1, TTbar_trm2, TTbar_tre1, TTbar_tre2, TTbar_pup1, TTbar_pup2, TTbar_bta1, TTbar_bta2, TTbar_wje1, TTbar_wje2, TTbar_top1, TTbar_top2, TTbar_for1, TTbar_for2, TTbar_jes1, TTbar_jes2, TTbar_jer1, TTbar_jer2);
    MakeHistoErrorsMC(m, TTV, TTV_muo1, TTV_muo2, TTV_ele1, TTV_ele2, TTV_trm1, TTV_trm2, TTV_tre1, TTV_tre2, TTV_pup1, TTV_pup2, TTV_bta1, TTV_bta2, TTV_wje1, TTV_wje2, TTV_top1, TTV_top2, TTV_for1, TTV_for2, TTV_jes1, TTV_jes2, TTV_jer1, TTV_jer2);
    MakeHistoErrorsMC(m, DIBOSON, DIBOSON_muo1, DIBOSON_muo2, DIBOSON_ele1, DIBOSON_ele2, DIBOSON_trm1, DIBOSON_trm2, DIBOSON_tre1, DIBOSON_tre2, DIBOSON_pup1, DIBOSON_pup2, DIBOSON_bta1, DIBOSON_bta2, DIBOSON_wje1, DIBOSON_wje2, DIBOSON_top1, DIBOSON_top2, DIBOSON_for1, DIBOSON_for2, DIBOSON_jes1, DIBOSON_jes2, DIBOSON_jer1, DIBOSON_jer2);
    MakeHistoErrorsMC(m, tptzm0800lh, tptzm0800lh_muo1, tptzm0800lh_muo2, tptzm0800lh_ele1, tptzm0800lh_ele2, tptzm0800lh_trm1, tptzm0800lh_trm2, tptzm0800lh_tre1, tptzm0800lh_tre2, tptzm0800lh_pup1, tptzm0800lh_pup2, tptzm0800lh_bta1, tptzm0800lh_bta2, tptzm0800lh_wje1, tptzm0800lh_wje2, tptzm0800lh_top1, tptzm0800lh_top2, tptzm0800lh_for1, tptzm0800lh_for2, tptzm0800lh_jes1, tptzm0800lh_jes2, tptzm0800lh_jer1, tptzm0800lh_jer2);
    MakeHistoErrorsMC(m, tptzm1600lh, tptzm1600lh_muo1, tptzm1600lh_muo2, tptzm1600lh_ele1, tptzm1600lh_ele2, tptzm1600lh_trm1, tptzm1600lh_trm2, tptzm1600lh_tre1, tptzm1600lh_tre2, tptzm1600lh_pup1, tptzm1600lh_pup2, tptzm1600lh_bta1, tptzm1600lh_bta2, tptzm1600lh_wje1, tptzm1600lh_wje2, tptzm1600lh_top1, tptzm1600lh_top2, tptzm1600lh_for1, tptzm1600lh_for2, tptzm1600lh_jes1, tptzm1600lh_jes2, tptzm1600lh_jer1, tptzm1600lh_jer2);
    MakeHistoErrorsMC(m, tptzm1700lh, tptzm1700lh_muo1, tptzm1700lh_muo2, tptzm1700lh_ele1, tptzm1700lh_ele2, tptzm1700lh_trm1, tptzm1700lh_trm2, tptzm1700lh_tre1, tptzm1700lh_tre2, tptzm1700lh_pup1, tptzm1700lh_pup2, tptzm1700lh_bta1, tptzm1700lh_bta2, tptzm1700lh_wje1, tptzm1700lh_wje2, tptzm1700lh_top1, tptzm1700lh_top2, tptzm1700lh_for1, tptzm1700lh_for2, tptzm1700lh_jes1, tptzm1700lh_jes2, tptzm1700lh_jer1, tptzm1700lh_jer2);
  }
  double DYYield_errSyst     = 0.; DYYield          = DY         ->IntegralAndError(1,N-1,DYYield_errSyst); 
  double STYield_errSyst     = 0.; STYield          = SINGLETOP  ->IntegralAndError(1,N-1,STYield_errSyst); 
  double TTYield_errSyst     = 0.; TTYield          = TTbar      ->IntegralAndError(1,N-1,TTYield_errSyst); 
  double TTVYield_errSyst    = 0.; TTVYield         = TTV        ->IntegralAndError(1,N-1,TTVYield_errSyst); 
  double VVYield_errSyst     = 0.; VVYield          = DIBOSON    ->IntegralAndError(1,N-1,VVYield_errSyst); 
  double tptzm0800lh_errSyst = 0.; tptzm0800lhYield = tptzm0800lh->IntegralAndError(1,N-1,tptzm0800lh_errSyst); 
  double tptzm1600lh_errSyst = 0.; tptzm1600lhYield = tptzm1600lh->IntegralAndError(1,N-1,tptzm1600lh_errSyst); 
  double tptzm1700lh_errSyst = 0.; tptzm1700lhYield = tptzm1700lh->IntegralAndError(1,N-1,tptzm1700lh_errSyst); 
  double N2_errSyst = 0.;          N2               = ERR        ->IntegralAndError(1,N-1,N2_errSyst);
  DYYield_errSyst     = sqrt(pow(DYYield_errSyst    ,2) - pow(DYYield_errStat    ,2));
  STYield_errSyst     = sqrt(pow(STYield_errSyst    ,2) - pow(STYield_errStat    ,2));
  TTYield_errSyst     = sqrt(pow(TTYield_errSyst    ,2) - pow(TTYield_errStat    ,2));
  TTVYield_errSyst    = sqrt(pow(TTVYield_errSyst   ,2) - pow(TTVYield_errStat   ,2));
  VVYield_errSyst     = sqrt(pow(VVYield_errSyst    ,2) - pow(VVYield_errStat    ,2));
  tptzm0800lh_errSyst = sqrt(pow(tptzm0800lh_errSyst,2) - pow(tptzm0800lh_errStat,2));
  tptzm1600lh_errSyst = sqrt(pow(tptzm1600lh_errSyst,2) - pow(tptzm1600lh_errStat,2));
  tptzm1700lh_errSyst = sqrt(pow(tptzm1700lh_errSyst,2) - pow(tptzm1700lh_errStat,2));
  N2_errSyst          = sqrt(pow(N2_errSyst         ,2) - pow(N2_errStat         ,2));         
  cout<<endl;
  cout<<"RESULTS"<<endl;
  cout<<"Number of predicted BKG events = "<<N1<<"+/-"<<N1_errStat<<endl;
  cout<<"Number of BKG events from MC   = "<<N2<<"+/-"<<N2_errStat<<"(stat)+/-"<<N2_errSyst<<"(syst)"<<endl;
  cout<<"Number of DY  events from MC   = "<<DYYield<<"+/-"<<DYYield_errStat<<"(stat)+/-"<<DYYield_errSyst<<"(syst)"<<endl;
  cout<<"Number of ST  events from MC   = "<<STYield<<"+/-"<<STYield_errStat<<"(stat)+/-"<<STYield_errSyst<<"(syst)"<<endl;
  cout<<"Number of TT  events from MC   = "<<TTYield<<"+/-"<<TTYield_errStat<<"(stat)+/-"<<TTYield_errSyst<<"(syst)"<<endl;
  cout<<"Number of TTV events from MC   = "<<TTVYield<<"+/-"<<TTVYield_errStat<<"(stat)+/-"<<TTVYield_errSyst<<"(syst)"<<endl;
  cout<<"Number of VV  events from MC   = "<<VVYield<<"+/-"<<VVYield_errStat<<"(stat)+/-"<<VVYield_errSyst<<"(syst)"<<endl;
  cout<<"Number of signal events 0.8TeV = "<<tptzm0800lh->Integral()<<"+/-"<<tptzm0800lh_errStat<<"(stat)+/-"<<tptzm0800lh_errSyst<<"(syst)"<<" (eff = "<<100*tptzm0800lh->Integral()/(w_SIG2 *399800*(0.03363+0.03366))<<" %)"<<endl;
  cout<<"Number of signal events 1.6TeV = "<<tptzm1600lh->Integral()<<"+/-"<<tptzm1600lh_errStat<<"(stat)+/-"<<tptzm1600lh_errSyst<<"(syst)"<<" (eff = "<<100*tptzm1600lh->Integral()/(w_SIG10*400000*(0.03363+0.03366))<<" %)"<<endl;
  //cout<<"Number of signal events 1.7TeV = "<<tptzm1700lh->Integral()<<"+/-"<<tptzm1700lh_errStat<<"(stat)+/-"<<tptzm1700lh_errSyst<<"(syst)"<<" (eff = "<<100*tptzm1700lh->Integral()/(w_SIG11*400000*(0.03363+0.03366))<<" %)"<<endl;
  cout<<"Number of DATA events          = "<<N3<<"+/-"<<N3_errStat<<endl;
  cout<<endl;
  DY->SetFillColor(kOrange);
  TTbar->SetFillColor(kGreen+3);
  DIBOSON->SetFillColor(kCyan+2);
  TTV->SetFillColor(kCyan-4);
  SINGLETOP->SetFillColor(40);
  DY->SetLineColor(kOrange);
  TTbar->SetLineColor(kGreen+3);
  DIBOSON->SetLineColor(kCyan+2);
  TTV->SetLineColor(kCyan-4);
  SINGLETOP->SetLineColor(40);
  TTbar->Add(SINGLETOP);
  for(int i=0; i<DIBOSON->GetNbinsX(); i++){
    double N_PRE     = histo_PRE->GetBinContent(i+1);
    double alpha_num = DIBOSON->GetBinContent(i+1) + TTbar->GetBinContent(i+1) + TTV->GetBinContent(i+1) + DY->GetBinContent(i+1);
    DIBOSON    ->SetBinContent(i+1, DIBOSON->GetBinContent(i+1) * N_PRE/alpha_num);
    TTbar      ->SetBinContent(i+1, TTbar  ->GetBinContent(i+1) * N_PRE/alpha_num);
    TTV        ->SetBinContent(i+1, TTV    ->GetBinContent(i+1) * N_PRE/alpha_num);
    DY         ->SetBinContent(i+1, DY     ->GetBinContent(i+1) * N_PRE/alpha_num);
  }//MC模拟数据中本底的组成成分各占多少
  hs->Add(DIBOSON);
  hs->Add(TTbar);
  hs->Add(TTV);
  hs->Add(DY);
  //hs->Add(SINGLETOP);
  Nsb->SetLineWidth(2); 
  Nsb->SetLineColor(2);
  Nsb->SetMarkerColor(2); 
  Nsb->SetMarkerStyle(20); 
  Nsb->SetMarkerSize(1.3);
  Nsb->GetYaxis()->SetTitleSize(0.045);
  Nsb->GetXaxis()->SetTitleSize(0.045);
  Nsb->GetYaxis()->SetLabelSize(0.045);
  Nsb->GetXaxis()->SetLabelSize(0.045); 
  Nsb->SetMinimum(0);
  Nsb->SetTitle("");
  Nsb->GetYaxis()->SetTitle("Number of Events in SB");
  Nsb->GetXaxis()->SetTitle("#it{m}_{Z,top} [GeV]"); 
  Alpha->SetLineWidth(2); 
  Alpha->SetLineColor(kGreen+3);
  Alpha->SetMarkerColor(kGreen+3); 
  Alpha->SetMarkerStyle(20); 
  Alpha->SetMarkerSize(1.3);
  Alpha->GetYaxis()->SetTitleSize(0.045);
  Alpha->GetXaxis()->SetTitleSize(0.045);
  Alpha->GetYaxis()->SetLabelSize(0.045);
  Alpha->GetXaxis()->SetLabelSize(0.045); 
  Alpha->SetMinimum(0);
  Alpha->SetMaximum(1.0);
  Alpha->SetTitle("");
  Alpha->GetYaxis()->SetTitle("#alpha-ratio");
  Alpha->GetXaxis()->SetTitle("#it{m}_{Z,top} [GeV]"); 
  TCanvas* canvasAlpha = new TCanvas("canvasAlpha","canvasAlpha",0,0,900,600); 
  if(save){
    Alpha->Draw("E");
    TString channelText = "";
    if(category==0) channelText = "T in 2#mu + 1b jet + 2jets";
    if(category==1) channelText = "T in 2e + 1b jet + 2jets";
    if(category==2) channelText = "T in 2#mu + 1W jet + 1b jet ";
    if(category==3) channelText = "T in 2e + 1W jet + 1b jet ";
    if(category==4) channelText = "T in 2#mu + 1top jet";
    if(category==5) channelText = "T in 2e + 1top jet";
    if(category==6) channelText = "B in 2#mu + 1b jet";
    if(category==7) channelText = "B in 2e + 1b jet";
    TString channelText2 = "";
    if(forward==1) channelText2 = "N(forward jets) = 0";
    if(forward==2) channelText2 = "N(forward jets) > 0";
    float channelTextFont   = 42;
    float channelTextSize   = 0.06;
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack); 
    latex.SetTextFont(channelTextFont);
    latex.SetTextSize(channelTextSize);
    if(category<2) latex.DrawLatex(0.54, 0.85, channelText);
    else if(category<4) latex.DrawLatex(0.52, 0.85, channelText);
    else if(category<6) latex.DrawLatex(0.59, 0.85, channelText);
    else if(category<8) latex.DrawLatex(0.62, 0.85, channelText);
    latex.DrawLatex(0.60, 0.77, channelText2);
    if(forward==1){
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_1.pdf");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_1.pdf");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_1.pdf");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_1.pdf");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_1.pdf");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_1.pdf");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_1.pdf");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_1.pdf");
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_1.png");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_1.png");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_1.png");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_1.png");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_1.png");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_1.png");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_1.png");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_1.png");
    } else if(forward==2){
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_2.pdf");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_2.pdf");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_2.pdf");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_2.pdf");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_2.pdf");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_2.pdf");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_2.pdf");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_2.pdf");
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_2.png");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_2.png");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_2.png");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_2.png");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_2.png");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_2.png");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_2.png");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_2.png");
    } else {
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_0.pdf");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_0.pdf");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_0.pdf");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_0.pdf");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_0.pdf");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_0.pdf");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_0.pdf");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_0.pdf");
      if(category==0) canvasAlpha->SaveAs("alphaRatio_MuoRes_0.png");
      if(category==1) canvasAlpha->SaveAs("alphaRatio_EleRes_0.png");
      if(category==2) canvasAlpha->SaveAs("alphaRatio_MuoPar_0.png");
      if(category==3) canvasAlpha->SaveAs("alphaRatio_ElePar_0.png");
      if(category==4) canvasAlpha->SaveAs("alphaRatio_MuoFul_0.png");
      if(category==5) canvasAlpha->SaveAs("alphaRatio_EleFul_0.png");
      if(category==6) canvasAlpha->SaveAs("alphaRatio_MuoBprime_0.png");
      if(category==7) canvasAlpha->SaveAs("alphaRatio_EleBprime_0.png");
    }
    char NewFileName[500]; sprintf(NewFileName, "alpharatio_Cat%i_%i.root",category,forward);
    TFile f(NewFileName,"new");
    Alpha->Write();
    Nsb->Draw("E");
    TLatex latex2;
    latex2.SetNDC();
    latex2.SetTextAngle(0);
    latex2.SetTextColor(kBlack); 
    latex2.SetTextFont(channelTextFont);
    latex2.SetTextSize(channelTextSize);
    if(category<2) latex.DrawLatex(0.54, 0.85, channelText);
    else if(category<4) latex.DrawLatex(0.52, 0.85, channelText);
    else if(category<6) latex.DrawLatex(0.59, 0.85, channelText);
    else if(category<8) latex.DrawLatex(0.62, 0.85, channelText);
    latex.DrawLatex(0.60, 0.77, channelText2);
    if(forward==1){
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_1.pdf");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_1.pdf");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_1.pdf");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_1.pdf");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_1.pdf");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_1.pdf");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_1.pdf");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_1.pdf");
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_1.png");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_1.png");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_1.png");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_1.png");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_1.png");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_1.png");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_1.png");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_1.png");
    } else if(forward==2){
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_2.pdf");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_2.pdf");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_2.pdf");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_2.pdf");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_2.pdf");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_2.pdf");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_2.pdf");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_2.pdf");
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_2.png");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_2.png");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_2.png");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_2.png");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_2.png");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_2.png");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_2.png");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_2.png");
    } else {
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_0.pdf");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_0.pdf");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_0.pdf");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_0.pdf");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_0.pdf");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_0.pdf");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_0.pdf");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_0.pdf");
      if(category==0) canvasAlpha->SaveAs("Nsideband_MuoRes_0.png");
      if(category==1) canvasAlpha->SaveAs("Nsideband_EleRes_0.png");
      if(category==2) canvasAlpha->SaveAs("Nsideband_MuoPar_0.png");
      if(category==3) canvasAlpha->SaveAs("Nsideband_ElePar_0.png");
      if(category==4) canvasAlpha->SaveAs("Nsideband_MuoFul_0.png");
      if(category==5) canvasAlpha->SaveAs("Nsideband_EleFul_0.png");
      if(category==6) canvasAlpha->SaveAs("Nsideband_MuoBprime_0.png");
      if(category==7) canvasAlpha->SaveAs("Nsideband_EleBprime_0.png");
    }
  }
  delete file01;
  delete file02;
  delete file03;
  delete file04;
  delete file05;
  delete file06;
  delete file07;
  delete file08;
  delete file09;
  delete file10;
  delete file11;
}

void SavePlot(int category, int forward,TCanvas* c, TH1F *histo_PRE2, TH1F *histo_DAT, TH1F *ERR, THStack *hs, bool save){
  c->cd();
  TGraphAsymmErrors *gDATA = new TGraphAsymmErrors(histo_DAT);	
  gDATA->SetLineWidth(2); 
  gDATA->SetLineColor(1);
  gDATA->SetMarkerColor(1); 
  gDATA->SetMarkerStyle(20); 
  gDATA->SetMarkerSize(1.3);
  histo_DAT->SetLineWidth(2); 
  histo_DAT->SetLineColor(1);
  histo_DAT->SetMarkerColor(1); 
  histo_DAT->SetMarkerStyle(20); 
  histo_DAT->SetMarkerSize(1.3);
  for (int i = 0; i < gDATA->GetN(); ++i) {
    double alpha = 1 - 0.6827;
    int M = gDATA->GetY()[i];
    double L =  (M==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,M,1.));
    double U =  ROOT::Math::gamma_quantile_c(alpha/2,M+1,1);
    //if(M!=0){
    gDATA->SetPointEYlow(i, M-L);
    gDATA->SetPointEYhigh(i, U-M);
    //}
  }
  TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.32);
  c1_1->Draw();
  c1_1->cd();
  c1_1->SetTopMargin(0.045);
  c1_1->SetBottomMargin(0.3);
  c1_1->SetRightMargin(0.035);
  c1_1->SetLeftMargin(0.11);
  TH1F *RATIO2 = (TH1F*)histo_PRE2->Clone();
  Double_t x[N-1]; Double_t exl[N-1]; Double_t exh[N-1];
  Double_t y[N-1]; Double_t eyl[N-1]; Double_t eyh[N-1]; 
  for(int m=0; m<histo_PRE2->GetNbinsX(); m++){ 
    x[m]=xbins[m]+(xbins[m+1]-xbins[m])/2;
    exl[m]=(xbins[m+1]-xbins[m])/2;
    exh[m]=(xbins[m+1]-xbins[m])/2;
    RATIO2->SetBinContent(m+1,1);
    if(histo_PRE2->GetBinContent(m+1)!=0) {
      y[m]=histo_DAT->GetBinContent(m+1)/histo_PRE2->GetBinContent(m+1);
      eyl[m]=sqrt(gDATA->GetErrorYlow(m) *gDATA->GetErrorYlow(m) )/histo_PRE2->GetBinContent(m+1);
      eyh[m]=sqrt(gDATA->GetErrorYhigh(m)*gDATA->GetErrorYhigh(m))/histo_PRE2->GetBinContent(m+1);
      RATIO2->SetBinError(m+1,histo_PRE2->GetBinError(m+1)/histo_PRE2->GetBinContent(m+1));
    } else {
      y[m]=-1;
      eyl[m]=0;
      eyh[m]=0;
    }
  }
  TGraphAsymmErrors *RATIO = new TGraphAsymmErrors(N-1,x,y,exl,exh,eyl,eyh);
  RATIO->Draw("AE0p");
  RATIO->SetMarkerColor(1); 
  RATIO->SetMarkerStyle(21); 
  RATIO->SetMarkerSize(1.0);
  RATIO->SetMaximum(2);
  RATIO->SetMinimum(0);
  RATIO->SetLineColor(1);
  RATIO->SetLineWidth(2);
  RATIO->GetXaxis()->SetTitleOffset(0.9);
  RATIO->GetYaxis()->SetTitleOffset(0.5);
  RATIO->SetTitle("");
  RATIO->GetYaxis()->SetTitle("observed/expected");
  RATIO->GetXaxis()->SetTitle("#it{m}_{Z,top} [GeV]");
  RATIO->GetXaxis()->SetLabelSize(0.13);
  RATIO->GetYaxis()->SetLabelSize(0.13);
  RATIO->GetXaxis()->SetTitleSize(0.15);
  RATIO->GetYaxis()->SetTitleSize(0.09);
  RATIO->GetYaxis()->SetNdivisions(505);
  RATIO->GetXaxis()->SetRangeUser(xbins[0],xbins[N-1]);
  TLine* line = new TLine(xbins[0],1,xbins[N-1],1);
  line->SetLineColor(2);
  line->SetLineWidth(2);
  line->Draw("same");
  RATIO2->SetFillStyle(3002);
  RATIO2->SetFillColor(12);
  RATIO2->SetLineColor(12);
  RATIO2->SetMarkerSize(0);
  RATIO2->Draw("E2same");
  RATIO->Draw("E0psame");	
  c->cd();	
  TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.32,0.99,1.0);
  c1_2->Draw();
  c1_2->cd();
  c1_2->SetTopMargin(0.08);
  c1_2->SetBottomMargin(0.02);
  c1_2->SetRightMargin(0.035);
  c1_2->SetLeftMargin(0.11);   
  float maxy=-10;
  float ADD=5000;
  if(category<2) ADD = 35;
  else ADD = 15;
  for(int ABC=0; ABC<histo_PRE2->GetNbinsX(); ABC++){
    if(histo_PRE2->GetBinContent(ABC+1)+sqrt(histo_PRE2->GetBinContent(ABC+1))+ADD>=maxy) maxy=histo_PRE2->GetBinContent(ABC+1)+sqrt(histo_PRE2->GetBinContent(ABC+1))+ADD;
    if(histo_DAT ->GetBinContent(ABC+1)+sqrt(histo_DAT ->GetBinContent(ABC+1))+ADD>=maxy) maxy=histo_DAT ->GetBinContent(ABC+1)+sqrt(histo_DAT ->GetBinContent(ABC+1))+ADD;
    if(ERR       ->GetBinContent(ABC+1)+sqrt(ERR       ->GetBinContent(ABC+1))+ADD>=maxy) maxy=ERR       ->GetBinContent(ABC+1)+sqrt(ERR       ->GetBinContent(ABC+1))+ADD;
  }
  //histo_PRE2->SetLineWidth(2); 
  //histo_PRE2->SetLineColor(2);
  //histo_PRE2->SetMarkerColor(2); 
  //histo_PRE2->SetMarkerStyle(21); 
  //histo_PRE2->SetMarkerSize(1.5);
  ERR = (TH1F*)histo_PRE2->Clone("ERR");
  ERR->SetMaximum(maxy);
  ERR->SetMinimum(0.0);
  ERR->GetYaxis()->SetTitleSize(0.070);
  ERR->GetXaxis()->SetTitleSize(0.070);
  ERR->GetYaxis()->SetLabelSize(0.070);
  ERR->GetXaxis()->SetLabelSize(0.0); 
  ERR->SetTitle("");
  ERR->GetYaxis()->SetTitle("Events");
  ERR->GetXaxis()->SetTitle("");
  ERR->GetYaxis()->SetTitleOffset(0.80);
  ERR->GetXaxis()->SetTitleOffset(0.85);
  ERR->SetFillStyle(3005);
  ERR->SetFillColor(12);
  ERR->SetLineColor(12);
  TH1F *DYFake        = new TH1F("DYFake",       "DYFake",       1,0,10);
  TH1F *TTbarFake     = new TH1F("TTbarFake",    "TTbarFake",    1,0,10);
  TH1F *DIBOSONFake   = new TH1F("DIBOSONFake",  "DIBOSONFake",  1,0,10); 
  TH1F *SINGLETOPFake = new TH1F("SINGLETOPFake","SINGLETOPFake",1,0,10); 
  TH1F *TTVFake       = new TH1F("TTVFake",      "TTVFake",      1,0,10); 
  DYFake->SetFillColor(kOrange);
  TTbarFake->SetFillColor(kGreen+3);
  DIBOSONFake->SetFillColor(kCyan+2);
  SINGLETOPFake->SetFillColor(40);
  TTVFake->SetFillColor(kCyan-4);
  DYFake->SetLineColor(kOrange);
  TTbarFake->SetLineColor(kGreen+3);
  DIBOSONFake->SetLineColor(kCyan+2);
  SINGLETOPFake->SetLineColor(40);
  TTVFake->SetLineColor(kCyan-4);
  tptzm1000lh->SetLineWidth(3);
  tptzm1000lh->SetLineColor(4);
  //tptzm1000lh->SetFillColor(kRed+2);
  //tptzm1000lh->SetFillStyle(3003);
  TLegend *pl2 = new TLegend(0.525,0.61,0.96,0.91);
  pl2->SetTextSize(0.05); 
  pl2->SetFillColor(0);
  TLegendEntry *//ple2 = pl2->AddEntry(histo_PRE2, "Background estimation",  "LEP");
  ple2 = pl2->AddEntry(histo_DAT, "Observed",  "LEP");
  ple2 = pl2->AddEntry(DYFake, "Z/#gamma+jets",  "F");
  ple2 = pl2->AddEntry(TTbarFake, "t#bar{t} and single-top",  "F");
  ple2 = pl2->AddEntry(DIBOSONFake, "VV (V = Z or W)",  "F");
  ple2 = pl2->AddEntry(TTVFake, "ttV and tZq (V = Z or W)",  "F");
  if(category<6) ple2 = pl2->AddEntry(tptzm1000lh, "Tb#rightarrow tZb (M=1TeV, LH)",  "F");
  else           ple2 = pl2->AddEntry(tptzm1000lh, "Bt#rightarrow bZt (M=1TeV, LH)",  "F");
  //if(category<2) histo_PRE2->SetMinimum(0.5);
  //histo_PRE2->Draw("E1");
  ERR->Draw("E2");	
  hs->Draw("histosame");
  ERR->Draw("E2same");
  //histo_PRE2->Draw("E1same");
  tptzm1000lh->Draw("same histo");
  gDATA->Draw("E0psame");
  pl2->Draw();
  //c1_2->SetLogy();
  TPad *pad = new TPad("pad","pad",0.01,0.01,0.99,0.99);
  gPad->RedrawAxis();
  TString channelText = "";
  if(category==0) channelText = "T in 2#mu + 1b jet + 2jets";
  if(category==1) channelText = "T in 2e + 1b jet + 2jets";
  if(category==2) channelText = "T in 2#mu + 1W jet + 1b jet ";
  if(category==3) channelText = "T in 2e + 1W jet + 1b jet ";
  if(category==4) channelText = "T in 2#mu + 1top jet";
  if(category==5) channelText = "T in 2e + 1top jet";
  if(category==6) channelText = "B in 2#mu + 1b jet";
  if(category==7) channelText = "B in 2e + 1b jet";
  TString channelText2 = "";
  if(forward==1) channelText2 = "N(forward jets) = 0";
  if(forward==2) channelText2 = "N(forward jets) > 0";
  float channelTextFont   = 42;
  float channelTextSize   = 0.06;
  TString cmsText     = "CMS";
  float cmsTextFont   = 61;  // default is helvetic-bold
  bool writeExtraText = true;
  TString extraText   = "Preliminary";
  //TString extraText   = "";
  float extraTextFont = 52;  // default is helvetica-italics
  // text sizes and text offsets with respect to the top frame in unit of the top margin size
  float lumiTextSize     = 0.6;
  float lumiTextOffset   = 0.2;
  float cmsTextSize      = 0.75;
  float cmsTextOffset    = 0.1;  // only used in outOfFrame version
  float relPosX    = 0.045;
  float relPosY    = 0.035;
  float relExtraDY = 1.2;
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  TString lumi_13TeV = "35.9 fb^{-1}";
  TString lumi_8TeV  = "19.7 fb^{-1}";
  TString lumi_7TeV  = "5.1 fb^{-1}";
  TString lumiText;
  lumiText += lumi_13TeV;
  lumiText += " (2016, 13 TeV)";
  float t = pad->GetTopMargin();
  float b = pad->GetBottomMargin();
  float r = pad->GetRightMargin();
  float l = pad->GetLeftMargin();
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);    
  float extraTextSize = extraOverCmsTextSize*cmsTextSize;
  latex.SetTextFont(42);
  latex.SetTextAlign(31); 
  latex.SetTextSize(lumiTextSize*t);    
  latex.DrawLatex(1-r+0.06,0.94,lumiText);
  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(11); 
  latex.SetTextSize(cmsTextSize*t);    
  latex.DrawLatex(l+0.01, 0.94,cmsText);
  latex.SetTextFont(extraTextFont);
  latex.SetTextSize(extraTextSize*t);
  latex.DrawLatex(l+0.12, 0.94, extraText); 
  latex.SetTextFont(channelTextFont);
  latex.SetTextSize(channelTextSize);
  if(category<2) latex.DrawLatex(0.585, 0.55, channelText);
  else if(category<4) latex.DrawLatex(0.565, 0.55, channelText);
  else if(category<6) latex.DrawLatex(0.645, 0.55, channelText);
  else if(category<8) latex.DrawLatex(0.705, 0.55, channelText);
  latex.DrawLatex(0.65, 0.49, channelText2);
  if(save) {
    if(forward==1){
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_1.pdf");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_1.pdf");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_1.pdf");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_1.pdf");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_1.pdf");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_1.pdf");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_1.pdf");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_1.pdf");
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_1.png");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_1.png");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_1.png");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_1.png");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_1.png");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_1.png");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_1.png");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_1.png");
    } else if(forward==2){
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_2.pdf");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_2.pdf");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_2.pdf");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_2.pdf");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_2.pdf");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_2.pdf");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_2.pdf");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_2.pdf");
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_2.png");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_2.png");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_2.png");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_2.png");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_2.png");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_2.png");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_2.png");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_2.png");
    } else {
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_0.pdf");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_0.pdf");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_0.pdf");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_0.pdf");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_0.pdf");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_0.pdf");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_0.pdf");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_0.pdf");
      if(category==0) c->SaveAs("bkgEstimation_MuoRes_0.png");
      if(category==1) c->SaveAs("bkgEstimation_EleRes_0.png");
      if(category==2) c->SaveAs("bkgEstimation_MuoPar_0.png");
      if(category==3) c->SaveAs("bkgEstimation_ElePar_0.png");
      if(category==4) c->SaveAs("bkgEstimation_MuoFul_0.png");
      if(category==5) c->SaveAs("bkgEstimation_EleFul_0.png");
      if(category==6) c->SaveAs("bkgEstimation_MuoBprime_0.png");
      if(category==7) c->SaveAs("bkgEstimation_EleBprime_0.png");
    }
  }
  delete DYFake;
  delete TTbarFake;
  delete DIBOSONFake;
  delete SINGLETOPFake;
  delete TTVFake;
  hs->RecursiveRemove(TTV);
  hs->RecursiveRemove(DIBOSON);
  hs->RecursiveRemove(TTbar);
  hs->RecursiveRemove(DY);
}

void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX){
  char input[50]; sprintf(input,"%s>>h(%i,%f,%f)",plot,BIN,MIN,MAX);
  TH1F *temp = new TH1F("", "", BIN,MIN,MAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH1F* h=(TH1F*)gDirectory->Get("h"); histo = (TH1F*)h->Clone(); delete h; } else { histo = (TH1F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
}

void MakeHistos(char CUT[1000],int Syst,const char *plot,int BIN1,int BIN2,float MIN,float MAX, int category, TH1F* &Nsb_func, TH1F* &Alpha_func, TH1F* &histo_PRE_func, 
		TH1F* &histo_PREup_func, TH1F* &histo_PREdo_func, TH1F* &histo_DAT_func, TH1F* &DY_func, TH1F* &SINGLETOP_func, TH1F* &TTbar_func, TH1F* &TTV_func, TH1F* &DIBOSON_func, 
		TH1F* &tptzm0700lh_func, TH1F* &tptzm0800lh_func, TH1F* &tptzm0900lh_func, TH1F* &tptzm1000lh_func, TH1F* &tptzm1100lh_func, TH1F* &tptzm1200lh_func, 
		TH1F* &tptzm1300lh_func, TH1F* &tptzm1400lh_func, TH1F* &tptzm1500lh_func, TH1F* &tptzm1600lh_func, TH1F* &tptzm1700lh_func, TH1F* &ERR_func){
  int i = BIN1;
  TH1F *SIG01; TH1F *SIG02; TH1F *SIG03; TH1F *SIG04; TH1F *SIG05; TH1F *SIG06; TH1F *SIG07; TH1F *SIG08; TH1F *SIG09; TH1F *SIG10; TH1F *SIG11; TH1F *SIG12; TH1F *data; TH1F *DY1; TH1F *DY2; TH1F *DY3; TH1F *DY4; TH1F *TT; TH1F *WW1; TH1F *WW2; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *ST1; TH1F *ST2; TH1F *ttZ; TH1F *ttW; TH1F *tZq; TH1F *data_SR; TH1F *DY1_SR; TH1F *DY2_SR; TH1F *DY3_SR; TH1F *DY4_SR; TH1F *TT_SR; TH1F *WW1_SR; TH1F *WW2_SR; TH1F *WZ1_SR; TH1F *WZ2_SR; TH1F *WZ3_SR; TH1F *ZZ1_SR; TH1F *ZZ2_SR; TH1F *ZZ3_SR; TH1F *ST1_SR; TH1F *ST2_SR; TH1F *ttZ_SR; TH1F *ttW_SR; TH1F *tZq_SR;
  if(Syst==0){
    GetHisto(CUT, TreeS1, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR, WZ3_SR    ,plot,BIN2,MIN,MAX);
  } else if(Syst==1){
    GetHisto(CUT, TreeS1_J1, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2_J1, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3_J1, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4_J1, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5_J1, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6_J1, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7_J1, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8_J1, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9_J1, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10_J1,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11_J1,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12_J1,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB_J1, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB_J1, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB_J1, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB_J1, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB_J1, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB_J1, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB_J1, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB_J1, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB_J1, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB_J1, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB_J1, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB_J1, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB_J1, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB_J1, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB_J1, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB_J1, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB_J1, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB_J1, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB_J1, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR_J1, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR_J1, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR_J1, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR_J1, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR_J1, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR_J1, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR_J1, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR_J1, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR_J1, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR_J1, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR_J1, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR_J1, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR_J1, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR_J1, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR_J1, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR_J1, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR_J1, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR_J1, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR_J1, WZ3_SR    ,plot,BIN2,MIN,MAX);
  } else if(Syst==2){
    GetHisto(CUT, TreeS1_J2, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2_J2, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3_J2, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4_J2, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5_J2, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6_J2, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7_J2, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8_J2, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9_J2, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10_J2,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11_J2,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12_J2,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB_J2, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB_J2, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB_J2, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB_J2, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB_J2, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB_J2, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB_J2, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB_J2, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB_J2, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB_J2, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB_J2, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB_J2, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB_J2, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB_J2, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB_J2, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB_J2, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB_J2, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB_J2, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB_J2, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR_J2, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR_J2, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR_J2, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR_J2, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR_J2, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR_J2, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR_J2, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR_J2, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR_J2, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR_J2, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR_J2, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR_J2, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR_J2, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR_J2, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR_J2, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR_J2, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR_J2, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR_J2, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR_J2, WZ3_SR    ,plot,BIN2,MIN,MAX);
  } else if(Syst==3){
    GetHisto(CUT, TreeS1_J3, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2_J3, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3_J3, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4_J3, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5_J3, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6_J3, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7_J3, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8_J3, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9_J3, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10_J3,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11_J3,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12_J3,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB_J3, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB_J3, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB_J3, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB_J3, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB_J3, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB_J3, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB_J3, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB_J3, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB_J3, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB_J3, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB_J3, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB_J3, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB_J3, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB_J3, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB_J3, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB_J3, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB_J3, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB_J3, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB_J3, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR_J3, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR_J3, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR_J3, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR_J3, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR_J3, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR_J3, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR_J3, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR_J3, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR_J3, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR_J3, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR_J3, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR_J3, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR_J3, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR_J3, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR_J3, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR_J3, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR_J3, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR_J3, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR_J3, WZ3_SR    ,plot,BIN2,MIN,MAX);
  } else if(Syst==4){
    GetHisto(CUT, TreeS1_J4, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2_J4, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3_J4, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4_J4, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5_J4, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6_J4, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7_J4, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8_J4, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9_J4, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10_J4,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11_J4,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12_J4,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB_J4, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB_J4, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB_J4, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB_J4, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB_J4, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB_J4, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB_J4, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB_J4, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB_J4, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB_J4, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB_J4, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB_J4, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB_J4, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB_J4, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB_J4, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB_J4, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB_J4, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB_J4, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB_J4, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR_J4, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR_J4, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR_J4, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR_J4, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR_J4, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR_J4, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR_J4, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR_J4, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR_J4, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR_J4, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR_J4, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR_J4, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR_J4, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR_J4, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR_J4, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR_J4, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR_J4, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR_J4, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR_J4, WZ3_SR    ,plot,BIN2,MIN,MAX);
  } else if(Syst==5){
    GetHisto(CUT, TreeS1_CL, SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2_CL, SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3_CL, SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4_CL, SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5_CL, SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6_CL, SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7_CL, SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8_CL, SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9_CL, SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10_CL,SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11_CL,SIG11  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS12_CL,SIG12  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SB_CL, data   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SB_CL, DY1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SB_CL, DY2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SB_CL, DY3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SB_CL, DY4    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SB_CL, ST1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SB_CL, ST2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SB_CL, TT     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SB_CL, ttZ    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SB_CL, ttW    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SB_CL, tZq    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SB_CL, ZZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SB_CL, ZZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SB_CL, ZZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SB_CL, WW1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SB_CL, WW2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SB_CL, WZ1    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SB_CL, WZ2    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SB_CL, WZ3    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree01_SR_CL, data_SR   ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree02_SR_CL, DY1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree03_SR_CL, DY2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree04_SR_CL, DY3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree05_SR_CL, DY4_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree06_SR_CL, ST1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree07_SR_CL, ST2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree08_SR_CL, TT_SR     ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree09_SR_CL, ttZ_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree10_SR_CL, ttW_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree11_SR_CL, tZq_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree12_SR_CL, ZZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree13_SR_CL, ZZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree14_SR_CL, ZZ3_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree15_SR_CL, WW1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree16_SR_CL, WW2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree17_SR_CL, WZ1_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree18_SR_CL, WZ2_SR    ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, Tree19_SR_CL, WZ3_SR    ,plot,BIN2,MIN,MAX);
  }
  double N_sb         = data->Integral();
  double N_sb_err     = sqrt(data->Integral());
  double f_sb_err     = 0;  
  double f_sb         = 0; 
  double alpha        = 0; 
  double alpha_err    = 0;
  double N_DY1_SR     = 0; if(DY1_SR->Integral()>0){N_DY1_SR =w01*DY1_SR->Integral();}
  double N_DY2_SR     = 0; if(DY2_SR->Integral()>0){N_DY2_SR =w02*DY2_SR->Integral();}
  double N_DY3_SR     = 0; if(DY3_SR->Integral()>0){N_DY3_SR =w03*DY3_SR->Integral();}
  double N_DY4_SR     = 0; if(DY4_SR->Integral()>0){N_DY4_SR =w04*DY4_SR->Integral();}
  double N_ST1_SR     = 0; if(ST1_SR->Integral()>0){N_ST1_SR =w05*ST1_SR->Integral();}
  double N_ST2_SR     = 0; if(ST2_SR->Integral()>0){N_ST2_SR =w06*ST2_SR->Integral();}
  double N_TT_SR      = 0; if(TT_SR ->Integral()>0){N_TT_SR  =w07*TT_SR ->Integral();}
  double N_TTZ_SR     = 0; if(ttZ_SR->Integral()>0){N_TTZ_SR =w08*ttZ_SR->Integral();}
  double N_TTW_SR     = 0; if(ttW_SR->Integral()>0){N_TTW_SR =w09*ttW_SR->Integral();}
  double N_tZq_SR     = 0; if(tZq_SR->Integral()>0){N_tZq_SR =w10*tZq_SR->Integral();}
  double N_VV1_SR     = 0; if(ZZ1_SR->Integral()>0){N_VV1_SR =w11*ZZ1_SR->Integral();}
  double N_VV2_SR     = 0; if(ZZ2_SR->Integral()>0){N_VV2_SR =w12*ZZ2_SR->Integral();}
  double N_VV3_SR     = 0; if(ZZ3_SR->Integral()>0){N_VV3_SR =w13*ZZ3_SR->Integral();}
  double N_VV4_SR     = 0; if(WW1_SR->Integral()>0){N_VV4_SR =w14*WW1_SR->Integral();}
  double N_VV5_SR     = 0; if(WW2_SR->Integral()>0){N_VV5_SR =w15*WW2_SR->Integral();}
  double N_VV6_SR     = 0; if(WZ1_SR->Integral()>0){N_VV6_SR =w16*WZ1_SR->Integral();}
  double N_VV7_SR     = 0; if(WZ2_SR->Integral()>0){N_VV7_SR =w17*WZ2_SR->Integral();}
  double N_VV8_SR     = 0; if(WZ3_SR->Integral()>0){N_VV8_SR =w18*WZ3_SR->Integral();}
  double N_DY_SR      = N_DY1_SR+N_DY2_SR+N_DY3_SR+N_DY4_SR;
  double N_ST_SR      = N_ST1_SR+N_ST2_SR;
  double N_TTV_SR     = N_TTZ_SR + N_TTW_SR + N_tZq_SR;
  double N_VV_SR      = N_VV1_SR+N_VV2_SR+N_VV3_SR+N_VV4_SR+N_VV5_SR+N_VV6_SR+N_VV7_SR+N_VV8_SR;
  double N_DY1_SR_err = w01; if(DY1_SR->Integral()>0){N_DY1_SR_err=sqrt(w01*w01*DY1_SR->Integral());}
  double N_DY2_SR_err = w02; if(DY2_SR->Integral()>0){N_DY2_SR_err=sqrt(w02*w02*DY2_SR->Integral());}
  double N_DY3_SR_err = w03; if(DY3_SR->Integral()>0){N_DY3_SR_err=sqrt(w03*w03*DY3_SR->Integral());}
  double N_DY4_SR_err = w04; if(DY4_SR->Integral()>0){N_DY4_SR_err=sqrt(w04*w04*DY4_SR->Integral());}
  double N_ST1_SR_err = w05; if(ST1_SR->Integral()>0){N_ST1_SR_err=sqrt(w05*w05*ST1_SR->Integral());}
  double N_ST2_SR_err = w06; if(ST2_SR->Integral()>0){N_ST2_SR_err=sqrt(w06*w06*ST2_SR->Integral());}
  double N_TT_SR_err  = w07; if(TT_SR ->Integral()>0){N_TT_SR_err =sqrt(w07*w07*TT_SR ->Integral());}
  double N_TTZ_SR_err = w08; if(ttZ_SR->Integral()>0){N_TTZ_SR_err=sqrt(w08*w08*ttZ_SR->Integral());}
  double N_TTW_SR_err = w09; if(ttW_SR->Integral()>0){N_TTW_SR_err=sqrt(w09*w09*ttW_SR->Integral());}
  double N_tZq_SR_err = w10; if(tZq_SR->Integral()>0){N_tZq_SR_err=sqrt(w10*w10*tZq_SR->Integral());}
  double N_VV1_SR_err = w11; if(ZZ1_SR->Integral()>0){N_VV1_SR_err=sqrt(w11*w11*ZZ1_SR->Integral());}
  double N_VV2_SR_err = w12; if(ZZ2_SR->Integral()>0){N_VV2_SR_err=sqrt(w12*w12*ZZ2_SR->Integral());}
  double N_VV3_SR_err = w13; if(ZZ3_SR->Integral()>0){N_VV3_SR_err=sqrt(w13*w13*ZZ3_SR->Integral());}
  double N_VV4_SR_err = w14; if(WW1_SR->Integral()>0){N_VV4_SR_err=sqrt(w14*w14*WW1_SR->Integral());}
  double N_VV5_SR_err = w15; if(WW2_SR->Integral()>0){N_VV5_SR_err=sqrt(w15*w15*WW2_SR->Integral());}
  double N_VV6_SR_err = w16; if(WZ1_SR->Integral()>0){N_VV6_SR_err=sqrt(w16*w16*WZ1_SR->Integral());}
  double N_VV7_SR_err = w17; if(WZ2_SR->Integral()>0){N_VV7_SR_err=sqrt(w17*w17*WZ2_SR->Integral());}
  double N_VV8_SR_err = w18; if(WZ3_SR->Integral()>0){N_VV8_SR_err=sqrt(w18*w18*WZ3_SR->Integral());}
  double N_ST_SR_err  = sqrt(N_ST1_SR_err*N_ST1_SR_err+N_ST2_SR_err*N_ST2_SR_err); 
  double N_VV_SR_err  = sqrt(N_VV1_SR_err*N_VV1_SR_err+N_VV2_SR_err*N_VV2_SR_err+N_VV3_SR_err*N_VV3_SR_err+N_VV4_SR_err*N_VV4_SR_err+N_VV5_SR_err*N_VV5_SR_err+N_VV6_SR_err*N_VV6_SR_err+N_VV7_SR_err*N_VV7_SR_err+N_VV8_SR_err*N_VV8_SR_err); 
  double N_DY_SR_err  = sqrt(N_DY1_SR_err*N_DY1_SR_err+N_DY2_SR_err*N_DY2_SR_err+N_DY3_SR_err*N_DY3_SR_err+N_DY4_SR_err*N_DY4_SR_err);
  double N_TTV_SR_err = sqrt(N_TTZ_SR_err*N_TTZ_SR_err + N_TTW_SR_err*N_TTW_SR_err + N_tZq_SR_err*N_tZq_SR_err);
  double N_DY1_SB     = 0; if(DY1->Integral()>0){N_DY1_SB =w01*DY1->Integral();}
  double N_DY2_SB     = 0; if(DY2->Integral()>0){N_DY2_SB =w02*DY2->Integral();}
  double N_DY3_SB     = 0; if(DY3->Integral()>0){N_DY3_SB =w03*DY3->Integral();}
  double N_DY4_SB     = 0; if(DY4->Integral()>0){N_DY4_SB =w04*DY4->Integral();}
  double N_ST1_SB     = 0; if(ST1->Integral()>0){N_ST1_SB =w05*ST1->Integral();}
  double N_ST2_SB     = 0; if(ST2->Integral()>0){N_ST2_SB =w06*ST2->Integral();}
  double N_TT_SB      = 0; if(TT ->Integral()>0){N_TT_SB  =w07*TT ->Integral();}
  double N_TTZ_SB     = 0; if(ttZ->Integral()>0){N_TTZ_SB =w08*ttZ->Integral();}
  double N_TTW_SB     = 0; if(ttW->Integral()>0){N_TTW_SB =w09*ttW->Integral();}
  double N_tZq_SB     = 0; if(tZq->Integral()>0){N_tZq_SB =w10*tZq->Integral();}
  double N_VV1_SB     = 0; if(ZZ1->Integral()>0){N_VV1_SB =w11*ZZ1->Integral();}
  double N_VV2_SB     = 0; if(ZZ2->Integral()>0){N_VV2_SB =w12*ZZ2->Integral();}
  double N_VV3_SB     = 0; if(ZZ3->Integral()>0){N_VV3_SB =w13*ZZ3->Integral();}
  double N_VV4_SB     = 0; if(WW1->Integral()>0){N_VV4_SB =w14*WW1->Integral();}
  double N_VV5_SB     = 0; if(WW2->Integral()>0){N_VV5_SB =w15*WW2->Integral();}
  double N_VV6_SB     = 0; if(WZ1->Integral()>0){N_VV6_SB =w16*WZ1->Integral();}
  double N_VV7_SB     = 0; if(WZ2->Integral()>0){N_VV7_SB =w17*WZ2->Integral();}
  double N_VV8_SB     = 0; if(WZ3->Integral()>0){N_VV8_SB =w18*WZ3->Integral();}
  double N_DY_SB      = N_DY1_SB+N_DY2_SB+N_DY3_SB+N_DY4_SB;
  double N_ST_SB      = N_ST1_SB+N_ST2_SB;
  double N_TTV_SB     = N_TTZ_SB + N_TTW_SB + N_tZq_SB;
  double N_VV_SB      = N_VV1_SB+N_VV2_SB+N_VV3_SB+N_VV4_SB+N_VV5_SB+N_VV6_SB+N_VV7_SB+N_VV8_SB;
  double N_DY1_SB_err = w01; if(DY1->Integral()>0){N_DY1_SB_err=sqrt(w01*w01*DY1->Integral());}
  double N_DY2_SB_err = w02; if(DY2->Integral()>0){N_DY2_SB_err=sqrt(w02*w02*DY2->Integral());}
  double N_DY3_SB_err = w03; if(DY3->Integral()>0){N_DY3_SB_err=sqrt(w03*w03*DY3->Integral());}
  double N_DY4_SB_err = w04; if(DY4->Integral()>0){N_DY4_SB_err=sqrt(w04*w04*DY4->Integral());}
  double N_ST1_SB_err = w05; if(ST1->Integral()>0){N_ST1_SB_err=sqrt(w05*w05*ST1->Integral());}
  double N_ST2_SB_err = w06; if(ST2->Integral()>0){N_ST2_SB_err=sqrt(w06*w06*ST2->Integral());}
  double N_TT_SB_err  = w07; if(TT ->Integral()>0){N_TT_SB_err =sqrt(w07*w07*TT ->Integral());}
  double N_TTZ_SB_err = w08; if(ttZ->Integral()>0){N_TTZ_SB_err=sqrt(w08*w08*ttZ->Integral());}
  double N_TTW_SB_err = w09; if(ttW->Integral()>0){N_TTW_SB_err=sqrt(w09*w09*ttW->Integral());}
  double N_tZq_SB_err = w10; if(tZq->Integral()>0){N_tZq_SB_err=sqrt(w10*w10*tZq->Integral());}
  double N_VV1_SB_err = w11; if(ZZ1->Integral()>0){N_VV1_SB_err=sqrt(w11*w11*ZZ1->Integral());}
  double N_VV2_SB_err = w12; if(ZZ2->Integral()>0){N_VV2_SB_err=sqrt(w12*w12*ZZ2->Integral());}
  double N_VV3_SB_err = w13; if(ZZ3->Integral()>0){N_VV3_SB_err=sqrt(w13*w13*ZZ3->Integral());}
  double N_VV4_SB_err = w14; if(WW1->Integral()>0){N_VV4_SB_err=sqrt(w14*w14*WW1->Integral());}
  double N_VV5_SB_err = w15; if(WW2->Integral()>0){N_VV5_SB_err=sqrt(w15*w15*WW2->Integral());}
  double N_VV6_SB_err = w16; if(WZ1->Integral()>0){N_VV6_SB_err=sqrt(w16*w16*WZ1->Integral());}
  double N_VV7_SB_err = w17; if(WZ2->Integral()>0){N_VV7_SB_err=sqrt(w17*w17*WZ2->Integral());}
  double N_VV8_SB_err = w18; if(WZ3->Integral()>0){N_VV8_SB_err=sqrt(w18*w18*WZ3->Integral());}
  double N_ST_SB_err  = sqrt(N_ST1_SB_err*N_ST1_SB_err+N_ST2_SB_err*N_ST2_SB_err); 
  double N_VV_SB_err  = sqrt(N_VV1_SB_err*N_VV1_SB_err+N_VV2_SB_err*N_VV2_SB_err+N_VV3_SB_err*N_VV3_SB_err+N_VV4_SB_err*N_VV4_SB_err+N_VV5_SB_err*N_VV5_SB_err+N_VV6_SB_err*N_VV6_SB_err+N_VV7_SB_err*N_VV7_SB_err+N_VV8_SB_err*N_VV8_SB_err); 
  double N_DY_SB_err  = sqrt(N_DY1_SB_err*N_DY1_SB_err+N_DY2_SB_err*N_DY2_SB_err+N_DY3_SB_err*N_DY3_SB_err+N_DY4_SB_err*N_DY4_SB_err);
  double N_TTV_SB_err = sqrt(N_TTZ_SB_err*N_TTZ_SB_err + N_TTW_SB_err*N_TTW_SB_err + N_tZq_SB_err*N_tZq_SB_err);
  double alpha_num     = N_DY_SR + N_VV_SR + N_TT_SR + N_TTV_SR + N_ST_SR;
  double alpha_num_err = sqrt(N_DY_SR_err*N_DY_SR_err + N_VV_SR_err*N_VV_SR_err + N_TT_SR_err*N_TT_SR_err + N_TTV_SR_err*N_TTV_SR_err + N_ST_SR_err*N_ST_SR_err);
  double alpha_den     = N_DY_SB + N_VV_SB + N_TT_SB + N_TTV_SB + N_ST_SB;
  double alpha_den_err = sqrt(N_DY_SB_err*N_DY_SB_err + N_VV_SB_err*N_VV_SB_err + N_TT_SB_err*N_TT_SB_err + N_TTV_SB_err*N_TTV_SB_err + N_ST_SB_err*N_ST_SB_err);
  if(alpha_den!=0) {
    alpha = alpha_num/alpha_den;
    alpha_err = sqrt(alpha_den*alpha_den*alpha_num_err*alpha_num_err + alpha_num*alpha_num*alpha_den_err*alpha_den_err)/(alpha_den*alpha_den);
  }
  double N_PRE      = N_sb * alpha;
  double N_PRE_err  = sqrt(/*N_sb_err*N_sb_err*alpha*alpha +*/ alpha_err*alpha_err*N_sb*N_sb);
  double N_PRE_errL = (N_sb==0) ? 0  : ((ROOT::Math::gamma_quantile((1 - 0.6827)/2,N_sb,1.)) * alpha);
  double N_PRE_errU = (ROOT::Math::gamma_quantile_c((1 - 0.6827)/2,N_sb+1,1)) * alpha;
  Nsb_func        ->SetBinContent(i+1,N_sb);
  Nsb_func        ->SetBinError(i+1,N_sb_err);
  Alpha_func      ->SetBinContent(i+1,alpha);
  Alpha_func      ->SetBinError(i+1,alpha_err);
  histo_PRE_func  ->SetBinContent(i+1, N_PRE);
  histo_PRE_func  ->SetBinError(  i+1, N_PRE_err);
  histo_PREup_func->SetBinContent(i+1, N_PRE_errU);
  histo_PREdo_func->SetBinContent(i+1, N_PRE_errL);
  histo_DAT_func  ->SetBinContent(i+1, data_SR->Integral());
  DY_func         ->SetBinContent(i+1, N_DY_SR);
  SINGLETOP_func  ->SetBinContent(i+1, N_ST_SR);
  TTbar_func      ->SetBinContent(i+1, N_TT_SR);
  TTV_func        ->SetBinContent(i+1, N_TTV_SR);
  DIBOSON_func    ->SetBinContent(i+1, N_VV_SR);
  DY_func         ->SetBinError(i+1, N_DY_SR_err);
  SINGLETOP_func  ->SetBinError(i+1, N_ST_SR_err);
  TTbar_func      ->SetBinError(i+1, N_TT_SR_err);
  TTV_func        ->SetBinError(i+1, N_TTV_SR_err);
  DIBOSON_func    ->SetBinError(i+1, N_VV_SR_err);
  tptzm0700lh_func->SetBinContent(i+1, w_SIG1 *SIG01 ->Integral());
  tptzm0800lh_func->SetBinContent(i+1, w_SIG2 *SIG02 ->Integral());
  tptzm0900lh_func->SetBinContent(i+1, w_SIG3 *SIG03 ->Integral());
  tptzm1000lh_func->SetBinContent(i+1, w_SIG4 *SIG04 ->Integral());
  tptzm1100lh_func->SetBinContent(i+1, w_SIG5 *SIG05 ->Integral());
  tptzm1200lh_func->SetBinContent(i+1, w_SIG6 *SIG06 ->Integral());
  tptzm1300lh_func->SetBinContent(i+1, w_SIG7 *SIG07 ->Integral());
  tptzm1400lh_func->SetBinContent(i+1, w_SIG8 *SIG08 ->Integral());
  tptzm1500lh_func->SetBinContent(i+1, w_SIG9 *SIG09 ->Integral());
  tptzm1600lh_func->SetBinContent(i+1, w_SIG10*SIG10 ->Integral());
  tptzm1700lh_func->SetBinContent(i+1, w_SIG11*SIG11 ->Integral());
  tptzm0700lh_func->SetBinError(i+1, w_SIG1 *sqrt(SIG01 ->Integral()));
  tptzm0800lh_func->SetBinError(i+1, w_SIG2 *sqrt(SIG02 ->Integral()));
  tptzm0900lh_func->SetBinError(i+1, w_SIG3 *sqrt(SIG03 ->Integral()));
  tptzm1000lh_func->SetBinError(i+1, w_SIG4 *sqrt(SIG04 ->Integral()));
  tptzm1100lh_func->SetBinError(i+1, w_SIG5 *sqrt(SIG05 ->Integral()));
  tptzm1200lh_func->SetBinError(i+1, w_SIG6 *sqrt(SIG06 ->Integral()));
  tptzm1300lh_func->SetBinError(i+1, w_SIG7 *sqrt(SIG07 ->Integral()));
  tptzm1400lh_func->SetBinError(i+1, w_SIG8 *sqrt(SIG08 ->Integral()));
  tptzm1500lh_func->SetBinError(i+1, w_SIG9 *sqrt(SIG09 ->Integral()));
  tptzm1600lh_func->SetBinError(i+1, w_SIG10*sqrt(SIG10->Integral()));
  tptzm1700lh_func->SetBinError(i+1, w_SIG11*sqrt(SIG11->Integral()));
  ERR_func        ->SetBinContent(i+1, alpha_num);
  ERR_func        ->SetBinError(  i+1, alpha_num_err);
  delete SIG01; delete SIG02; delete SIG03; delete SIG04; delete SIG05; delete SIG06; delete SIG07; delete SIG08; delete SIG09; delete SIG10; delete SIG11; delete data; delete DY1; delete DY2; delete DY3; delete DY4; delete TT; delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete ZZ1; delete ZZ2; delete ZZ3; delete ST1; delete ST2; delete ttZ; delete ttW; delete tZq; delete data_SR; delete DY1_SR; delete DY2_SR; delete DY3_SR; delete DY4_SR; delete TT_SR; delete WW1_SR; delete WW2_SR; delete WZ1_SR; delete WZ2_SR; delete WZ3_SR; delete ZZ1_SR; delete ZZ2_SR; delete ZZ3_SR; delete ST1_SR; delete ST2_SR; delete ttZ_SR; delete ttW_SR; delete tZq_SR;
}

void MakeHistosZjet(char CUT[1000],char CUT1[1000],char CUT2[1000],const char *plot,int BIN1,int BIN2,float MIN,float MAX, int category, TH1F* &DY_1_SR_func, TH1F* &DY_1_SB_func, 
		    TH1F* &DY_2_SR_func, TH1F* &DY_2_SB_func, TH1F* &data_SB_func, TH1F* &TTV_SB_func, TH1F* &TTbar_SB_func, TH1F* &DIBOSON_SB_func, TH1F* &SINGLETOP_SB_func){
  int i = BIN1;
  TH1F *DY1_1; TH1F *DY2_1; TH1F *DY3_1; TH1F *DY4_1; TH1F *DY1_1_SR; TH1F *DY2_1_SR; TH1F *DY3_1_SR; TH1F *DY4_1_SR;
  TH1F *DY1_2; TH1F *DY2_2; TH1F *DY3_2; TH1F *DY4_2; TH1F *DY1_2_SR; TH1F *DY2_2_SR; TH1F *DY3_2_SR; TH1F *DY4_2_SR;
  TH1F *TT; TH1F *WW1; TH1F *WW2; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *ST1; TH1F *ST2; TH1F *ttZ; TH1F *ttW; TH1F *tZq; TH1F *data;
  GetHisto(CUT,  Tree01_SB, data     ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree06_SB, ST1      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree07_SB, ST2      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree08_SB, TT       ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree09_SB, ttZ      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree10_SB, ttW      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree11_SB, tZq      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree12_SB, ZZ1      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree13_SB, ZZ2      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree14_SB, ZZ3      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree15_SB, WW1      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree16_SB, WW2      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree17_SB, WZ1      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree18_SB, WZ2      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT,  Tree19_SB, WZ3      ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree02_SB, DY1_1    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree03_SB, DY2_1    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree04_SB, DY3_1    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree05_SB, DY4_1    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree02_SR, DY1_1_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree03_SR, DY2_1_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree04_SR, DY3_1_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT1, Tree05_SR, DY4_1_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree02_SB, DY1_2    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree03_SB, DY2_2    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree04_SB, DY3_2    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree05_SB, DY4_2    ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree02_SR, DY1_2_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree03_SR, DY2_2_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree04_SR, DY3_2_SR ,plot,BIN2,MIN,MAX);
  GetHisto(CUT2, Tree05_SR, DY4_2_SR ,plot,BIN2,MIN,MAX);
  double N_DY1_1_SR     = w01*DY1_1_SR->Integral();
  double N_DY2_1_SR     = w02*DY2_1_SR->Integral();
  double N_DY3_1_SR     = w03*DY3_1_SR->Integral();
  double N_DY4_1_SR     = w04*DY4_1_SR->Integral();
  double N_DY1_2_SR     = w01*DY1_2_SR->Integral();
  double N_DY2_2_SR     = w02*DY2_2_SR->Integral();
  double N_DY3_2_SR     = w03*DY3_2_SR->Integral();
  double N_DY4_2_SR     = w04*DY4_2_SR->Integral();
  double N_DY1_1_SR_err = w01; if(DY1_1_SR->Integral()>0){N_DY1_1_SR_err=sqrt(w01*w01*DY1_1_SR->Integral());}
  double N_DY2_1_SR_err = w02; if(DY2_1_SR->Integral()>0){N_DY2_1_SR_err=sqrt(w02*w02*DY2_1_SR->Integral());}
  double N_DY3_1_SR_err = w03; if(DY3_1_SR->Integral()>0){N_DY3_1_SR_err=sqrt(w03*w03*DY3_1_SR->Integral());}
  double N_DY4_1_SR_err = w04; if(DY4_1_SR->Integral()>0){N_DY4_1_SR_err=sqrt(w04*w04*DY4_1_SR->Integral());}
  double N_DY1_2_SR_err = w01; if(DY1_2_SR->Integral()>0){N_DY1_2_SR_err=sqrt(w01*w01*DY1_2_SR->Integral());}
  double N_DY2_2_SR_err = w02; if(DY2_2_SR->Integral()>0){N_DY2_2_SR_err=sqrt(w02*w02*DY2_2_SR->Integral());}
  double N_DY3_2_SR_err = w03; if(DY3_2_SR->Integral()>0){N_DY3_2_SR_err=sqrt(w03*w03*DY3_2_SR->Integral());}
  double N_DY4_2_SR_err = w04; if(DY4_2_SR->Integral()>0){N_DY4_2_SR_err=sqrt(w04*w04*DY4_2_SR->Integral());}
  double N_DY1_1_SB     = w01*DY1_1->Integral();
  double N_DY2_1_SB     = w02*DY2_1->Integral();
  double N_DY3_1_SB     = w03*DY3_1->Integral();
  double N_DY4_1_SB     = w04*DY4_1->Integral();
  double N_DY1_2_SB     = w01*DY1_2->Integral();
  double N_DY2_2_SB     = w02*DY2_2->Integral();
  double N_DY3_2_SB     = w03*DY3_2->Integral();
  double N_DY4_2_SB     = w04*DY4_2->Integral();
  double N_DY1_1_SB_err = w01; if(DY1_1->Integral()>0){N_DY1_1_SB_err=sqrt(w01*w01*DY1_1->Integral());}
  double N_DY2_1_SB_err = w02; if(DY2_1->Integral()>0){N_DY2_1_SB_err=sqrt(w02*w02*DY2_1->Integral());}
  double N_DY3_1_SB_err = w03; if(DY3_1->Integral()>0){N_DY3_1_SB_err=sqrt(w03*w03*DY3_1->Integral());}
  double N_DY4_1_SB_err = w04; if(DY4_1->Integral()>0){N_DY4_1_SB_err=sqrt(w04*w04*DY4_1->Integral());}
  double N_DY1_2_SB_err = w01; if(DY1_2->Integral()>0){N_DY1_2_SB_err=sqrt(w01*w01*DY1_2->Integral());}
  double N_DY2_2_SB_err = w02; if(DY2_2->Integral()>0){N_DY2_2_SB_err=sqrt(w02*w02*DY2_2->Integral());}
  double N_DY3_2_SB_err = w03; if(DY3_2->Integral()>0){N_DY3_2_SB_err=sqrt(w03*w03*DY3_2->Integral());}
  double N_DY4_2_SB_err = w04; if(DY4_2->Integral()>0){N_DY4_2_SB_err=sqrt(w04*w04*DY4_2->Integral());}
  double N_DY_1_SR      = N_DY1_1_SR+N_DY2_1_SR+N_DY3_1_SR+N_DY4_1_SR;
  double N_DY_1_SR_err  = sqrt(N_DY1_1_SR_err*N_DY1_1_SR_err+N_DY2_1_SR_err*N_DY2_1_SR_err+N_DY3_1_SR_err*N_DY3_1_SR_err+N_DY4_1_SR_err*N_DY4_1_SR_err);
  double N_DY_1_SB      = N_DY1_1_SB+N_DY2_1_SB+N_DY3_1_SB+N_DY4_1_SB;
  double N_DY_1_SB_err  = sqrt(N_DY1_1_SB_err*N_DY1_1_SB_err+N_DY2_1_SB_err*N_DY2_1_SB_err+N_DY3_1_SB_err*N_DY3_1_SB_err+N_DY4_1_SB_err*N_DY4_1_SB_err);
  double N_DY_2_SR      = N_DY1_2_SR+N_DY2_2_SR+N_DY3_2_SR+N_DY4_2_SR;
  double N_DY_2_SR_err  = sqrt(N_DY1_2_SR_err*N_DY1_2_SR_err+N_DY2_2_SR_err*N_DY2_2_SR_err+N_DY3_2_SR_err*N_DY3_2_SR_err+N_DY4_2_SR_err*N_DY4_2_SR_err);
  double N_DY_2_SB      = N_DY1_2_SB+N_DY2_2_SB+N_DY3_2_SB+N_DY4_2_SB;
  double N_DY_2_SB_err  = sqrt(N_DY1_2_SB_err*N_DY1_2_SB_err+N_DY2_2_SB_err*N_DY2_2_SB_err+N_DY3_2_SB_err*N_DY3_2_SB_err+N_DY4_2_SB_err*N_DY4_2_SB_err);
  data_SB_func->SetBinContent(i+1, data->Integral());
  DY_1_SR_func->SetBinContent(i+1, N_DY_1_SR);
  DY_1_SR_func->SetBinError(  i+1, N_DY_1_SR_err);
  DY_1_SB_func->SetBinContent(i+1, N_DY_1_SB);
  DY_1_SB_func->SetBinError(  i+1, N_DY_1_SB_err);
  DY_2_SR_func->SetBinContent(i+1, N_DY_2_SR);
  DY_2_SR_func->SetBinError(  i+1, N_DY_2_SR_err);
  DY_2_SB_func->SetBinContent(i+1, N_DY_2_SB);
  DY_2_SB_func->SetBinError(  i+1, N_DY_2_SB_err);
  double N_ST1_SB     = 0; if(ST1->Integral()>0){N_ST1_SB =w05*ST1->Integral();}
  double N_ST2_SB     = 0; if(ST2->Integral()>0){N_ST2_SB =w06*ST2->Integral();}
  double N_TT_SB      = 0; if(TT ->Integral()>0){N_TT_SB  =w07*TT ->Integral();}
  double N_TTZ_SB     = 0; if(ttZ->Integral()>0){N_TTZ_SB =w08*ttZ->Integral();}
  double N_TTW_SB     = 0; if(ttW->Integral()>0){N_TTW_SB =w09*ttW->Integral();}
  double N_tZq_SB     = 0; if(tZq->Integral()>0){N_tZq_SB =w10*tZq->Integral();}
  double N_VV1_SB     = 0; if(ZZ1->Integral()>0){N_VV1_SB =w11*ZZ1->Integral();}
  double N_VV2_SB     = 0; if(ZZ2->Integral()>0){N_VV2_SB =w12*ZZ2->Integral();}
  double N_VV3_SB     = 0; if(ZZ3->Integral()>0){N_VV3_SB =w13*ZZ3->Integral();}
  double N_VV4_SB     = 0; if(WW1->Integral()>0){N_VV4_SB =w14*WW1->Integral();}
  double N_VV5_SB     = 0; if(WW2->Integral()>0){N_VV5_SB =w15*WW2->Integral();}
  double N_VV6_SB     = 0; if(WZ1->Integral()>0){N_VV6_SB =w16*WZ1->Integral();}
  double N_VV7_SB     = 0; if(WZ2->Integral()>0){N_VV7_SB =w17*WZ2->Integral();}
  double N_VV8_SB     = 0; if(WZ3->Integral()>0){N_VV8_SB =w18*WZ3->Integral();}
  double N_ST_SB      = N_ST1_SB+N_ST2_SB;
  double N_TTV_SB     = N_TTZ_SB + N_TTW_SB + N_tZq_SB;
  double N_VV_SB      = N_VV1_SB+N_VV2_SB+N_VV3_SB+N_VV4_SB+N_VV5_SB+N_VV6_SB+N_VV7_SB+N_VV8_SB;
  double N_ST1_SB_err = w05; if(ST1->Integral()>0){N_ST1_SB_err=sqrt(w05*w05*ST1->Integral());}
  double N_ST2_SB_err = w06; if(ST2->Integral()>0){N_ST2_SB_err=sqrt(w06*w06*ST2->Integral());}
  double N_TT_SB_err  = w07; if(TT ->Integral()>0){N_TT_SB_err =sqrt(w07*w07*TT ->Integral());}
  double N_TTZ_SB_err = w08; if(ttZ->Integral()>0){N_TTZ_SB_err=sqrt(w08*w08*ttZ->Integral());}
  double N_TTW_SB_err = w09; if(ttW->Integral()>0){N_TTW_SB_err=sqrt(w09*w09*ttW->Integral());}
  double N_tZq_SB_err = w10; if(tZq->Integral()>0){N_tZq_SB_err=sqrt(w10*w10*tZq->Integral());}
  double N_VV1_SB_err = w11; if(ZZ1->Integral()>0){N_VV1_SB_err=sqrt(w11*w11*ZZ1->Integral());}
  double N_VV2_SB_err = w12; if(ZZ2->Integral()>0){N_VV2_SB_err=sqrt(w12*w12*ZZ2->Integral());}
  double N_VV3_SB_err = w13; if(ZZ3->Integral()>0){N_VV3_SB_err=sqrt(w13*w13*ZZ3->Integral());}
  double N_VV4_SB_err = w14; if(WW1->Integral()>0){N_VV4_SB_err=sqrt(w14*w14*WW1->Integral());}
  double N_VV5_SB_err = w15; if(WW2->Integral()>0){N_VV5_SB_err=sqrt(w15*w15*WW2->Integral());}
  double N_VV6_SB_err = w16; if(WZ1->Integral()>0){N_VV6_SB_err=sqrt(w16*w16*WZ1->Integral());}
  double N_VV7_SB_err = w17; if(WZ2->Integral()>0){N_VV7_SB_err=sqrt(w17*w17*WZ2->Integral());}
  double N_VV8_SB_err = w18; if(WZ3->Integral()>0){N_VV8_SB_err=sqrt(w18*w18*WZ3->Integral());}
  double N_ST_SB_err  = sqrt(N_ST1_SB_err*N_ST1_SB_err+N_ST2_SB_err*N_ST2_SB_err); 
  double N_VV_SB_err  = sqrt(N_VV1_SB_err*N_VV1_SB_err+N_VV2_SB_err*N_VV2_SB_err+N_VV3_SB_err*N_VV3_SB_err+N_VV4_SB_err*N_VV4_SB_err+N_VV5_SB_err*N_VV5_SB_err+N_VV6_SB_err*N_VV6_SB_err+N_VV7_SB_err*N_VV7_SB_err+N_VV8_SB_err*N_VV8_SB_err); 
  double N_TTV_SB_err = sqrt(N_TTZ_SB_err*N_TTZ_SB_err + N_TTW_SB_err*N_TTW_SB_err + N_tZq_SB_err*N_tZq_SB_err);
  TTbar_SB_func      ->SetBinContent(i+1, N_TT_SB);
  TTV_SB_func        ->SetBinContent(i+1, N_TTV_SB);
  DIBOSON_SB_func    ->SetBinContent(i+1, N_VV_SB);
  SINGLETOP_SB_func  ->SetBinContent(i+1, N_ST_SB);
  TTbar_SB_func      ->SetBinError(i+1, N_TT_SB_err);
  TTV_SB_func        ->SetBinError(i+1, N_TTV_SB_err);
  DIBOSON_SB_func    ->SetBinError(i+1, N_VV_SB_err);
  SINGLETOP_SB_func  ->SetBinError(i+1, N_ST_SB_err);
  delete DY1_1; delete DY2_1; delete DY3_1; delete DY4_1; delete DY1_1_SR; delete DY2_1_SR; delete DY3_1_SR; delete DY4_1_SR;
  delete DY1_2; delete DY2_2; delete DY3_2; delete DY4_2; delete DY1_2_SR; delete DY2_2_SR; delete DY3_2_SR; delete DY4_2_SR;
  delete data; delete TT; delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete ZZ1; delete ZZ2; delete ZZ3; delete ST1; delete ST2; delete ttZ; delete ttW; delete tZq;
}

void MakeHistoErrors(int m, TH1F* &histo_SR, TH1F* histo_SRup, TH1F* histo_SRdo, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_Z1, TH1F* histo_Z2, TH1F* histo_C1, TH1F* histo_C2){
  float ErrMc = histo_SR->GetBinError(m); 
  float ErrCS = ((histo_SRup->GetBinContent(m)-histo_SR->GetBinContent(m)) + (histo_SR->GetBinContent(m)-histo_SRdo->GetBinContent(m)))/2;
  float ErrBT = max(fabs(histo_SR->GetBinContent(m)-histo_B1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_B2->GetBinContent(m)));
  float ErrZJ = max(fabs(histo_SR->GetBinContent(m)-histo_Z1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_Z2->GetBinContent(m)));
  float ErrCL = max(fabs(histo_SR->GetBinContent(m)-histo_C1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_C2->GetBinContent(m)));
  float TOTAL = sqrt(ErrMc*ErrMc + ErrCS*ErrCS + ErrBT*ErrBT + ErrZJ*ErrZJ + ErrCL*ErrCL);
  //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrBT<<" "<<ErrZJ<<" "<<ErrCL<<" "<<TOTAL<<" "<<endl;
  histo_SR ->SetBinError(m,TOTAL);
}

void MakeHistoErrorsMC(int m, TH1F* &histo_SR, TH1F* histo_M1, TH1F* histo_M2, TH1F* histo_E1, TH1F* histo_E2, TH1F* histo_R1, TH1F* histo_R2, TH1F* histo_R3, TH1F* histo_R4, TH1F* histo_P1, TH1F* histo_P2, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_W1, TH1F* histo_W2, TH1F* histo_T1, TH1F* histo_T2, TH1F* histo_F1, TH1F* histo_F2, TH1F* histo_J1, TH1F* histo_J2, TH1F* histo_J3, TH1F* histo_J4){
  float ErrMc = histo_SR->GetBinError(m); 
  float ErrLU = 0.026*histo_SR->GetBinContent(m);
  float ErrMU = max(fabs(histo_SR->GetBinContent(m)-histo_M1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_M2->GetBinContent(m)));
  float ErrEL = max(fabs(histo_SR->GetBinContent(m)-histo_E1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_E2->GetBinContent(m)));
  float ErrTM = max(fabs(histo_SR->GetBinContent(m)-histo_R1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_R2->GetBinContent(m)));
  float ErrTE = max(fabs(histo_SR->GetBinContent(m)-histo_R3->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_R4->GetBinContent(m)));
  float ErrPU = max(fabs(histo_SR->GetBinContent(m)-histo_P1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_P2->GetBinContent(m)));
  float ErrBT = max(fabs(histo_SR->GetBinContent(m)-histo_B1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_B2->GetBinContent(m))); 
  float ErrTO = max(fabs(histo_SR->GetBinContent(m)-histo_T1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_T2->GetBinContent(m))); 
  float ErrFO = max(fabs(histo_SR->GetBinContent(m)-histo_F1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_F2->GetBinContent(m))); 
  float ErrWJ = max(fabs(histo_SR->GetBinContent(m)-histo_W1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_W2->GetBinContent(m))); 
  float ErrJS = max(fabs(histo_SR->GetBinContent(m)-histo_J1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J2->GetBinContent(m))); 
  float ErrJR = max(fabs(histo_SR->GetBinContent(m)-histo_J3->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J4->GetBinContent(m))); 
  float TOTAL = sqrt(ErrMc*ErrMc + ErrLU*ErrLU + ErrMU*ErrMU + ErrEL*ErrEL + ErrTM*ErrTM + ErrTE*ErrTE + ErrPU*ErrPU + ErrBT*ErrBT + ErrTO*ErrTO + ErrFO*ErrFO + ErrWJ*ErrWJ + ErrJS*ErrJS + ErrJR*ErrJR);
  //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrLU<<" "<<ErrMU<<" "<<ErrEL<<" "<<ErrTM<<" "<<ErrTE<<" "<<ErrPU<<" "<<ErrBT<<" "<<ErrTO<<" "<<ErrFO<<" "<<ErrWJ<<" "<<ErrJS<<" "<<ErrJR<<endl;
  histo_SR ->SetBinError(m,TOTAL);
}

void ZjetSYST(){
  //DY_SR_zje1, DY_SB_zje1, DY_SR_zje2, DY_SB_zje2
  float SYST = 0.1;
  TH1F* DY_SR_zje1_new = (TH1F*)DY_SR_zje1->Clone();
  TH1F* DY_SR_zje2_new = (TH1F*)DY_SR_zje2->Clone();
  DY_SR_zje1->Scale((DY_SR_zje1->Integral()+SYST*DY_SR_zje2->Integral())/DY_SR_zje1->Integral());
  DY_SR_zje2->Scale(1.0-SYST);
  DY_SR_zje1->Add(DY_SR_zje2);
  DY_SR_zje1_new->Scale((DY_SR_zje1_new->Integral()-SYST*DY_SR_zje2_new->Integral())/DY_SR_zje1_new->Integral());
  DY_SR_zje2_new->Scale(1.0+SYST);
  DY_SR_zje1_new->Add(DY_SR_zje2_new);
  DY_SR_zje2 = (TH1F*)DY_SR_zje1_new->Clone();
  TH1F* DY_SB_zje1_new = (TH1F*)DY_SB_zje1->Clone();
  TH1F* DY_SB_zje2_new = (TH1F*)DY_SB_zje2->Clone();
  DY_SB_zje1->Scale((DY_SB_zje1->Integral()+SYST*DY_SB_zje2->Integral())/DY_SB_zje1->Integral());
  DY_SB_zje2->Scale(1.0-SYST);
  DY_SB_zje1->Add(DY_SB_zje2);
  DY_SB_zje1_new->Scale((DY_SB_zje1_new->Integral()-SYST*DY_SB_zje2_new->Integral())/DY_SB_zje1_new->Integral());
  DY_SB_zje2_new->Scale(1.0+SYST);
  DY_SB_zje1_new->Add(DY_SB_zje2_new);
  DY_SB_zje2 = (TH1F*)DY_SB_zje1_new->Clone();
  for(int i=0; i<N-1; i++){  
    double N_sb         = data_SB_zjet->GetBinContent(i+1);
    double N_sb_err     = sqrt(data_SB_zjet->GetBinContent(i+1));
    double f_sb_err     = 0;  
    double f_sb         = 0; 
    double alpha        = 0; 
    double alpha_err    = 0;
    double N_DY_SR      = DY_SR_zje1->GetBinContent(i+1);
    double N_TT_SR      = TTbar->GetBinContent(i+1);
    double N_ST_SR      = SINGLETOP->GetBinContent(i+1);
    double N_TTV_SR     = TTV->GetBinContent(i+1);
    double N_VV_SR      = DIBOSON->GetBinContent(i+1);
    double N_TT_SR_err  = TTbar->GetBinError(i+1);
    double N_ST_SR_err  = SINGLETOP->GetBinError(i+1);
    double N_TTV_SR_err = TTV->GetBinError(i+1);
    double N_VV_SR_err  = DIBOSON->GetBinError(i+1); 
    double N_DY_SR_err  = DY_SR_zje1->GetBinError(i+1);
    double N_DY_SB      = DY_SB_zje1->GetBinContent(i+1);
    double N_TT_SB      = TTbar_SB_zjet->GetBinContent(i+1);
    double N_ST_SB      = SINGLETOP_SB_zjet->GetBinContent(i+1);
    double N_TTV_SB     = TTV_SB_zjet->GetBinContent(i+1);
    double N_VV_SB      = DIBOSON_SB_zjet->GetBinContent(i+1);
    double N_TT_SB_err  = TTbar_SB_zjet->GetBinError(i+1);
    double N_ST_SB_err  = SINGLETOP_SB_zjet->GetBinError(i+1);
    double N_TTV_SB_err = TTV_SB_zjet->GetBinError(i+1);
    double N_VV_SB_err  = DIBOSON_SB_zjet->GetBinError(i+1); 
    double N_DY_SB_err  = DY_SB_zje1->GetBinError(i+1);
    double alpha_num     = N_DY_SR + N_VV_SR + N_TT_SR + N_TTV_SR + N_ST_SR;
    double alpha_num_err = sqrt(N_DY_SR_err*N_DY_SR_err + N_VV_SR_err*N_VV_SR_err + N_TT_SR_err*N_TT_SR_err + N_TTV_SR_err*N_TTV_SR_err + N_ST_SR_err*N_ST_SR_err);
    double alpha_den     = N_DY_SB + N_VV_SB + N_TT_SB + N_TTV_SB + N_ST_SB;
    double alpha_den_err = sqrt(N_DY_SB_err*N_DY_SB_err + N_VV_SB_err*N_VV_SB_err + N_TT_SB_err*N_TT_SB_err + N_TTV_SB_err*N_TTV_SB_err + N_ST_SB_err*N_ST_SB_err);
    if(alpha_den!=0) {
      alpha = alpha_num/alpha_den;
      alpha_err = sqrt(alpha_den*alpha_den*alpha_num_err*alpha_num_err + alpha_num*alpha_num*alpha_den_err*alpha_den_err)/(alpha_den*alpha_den);
    }
    double N_PRE      = N_sb * alpha;
    double N_PRE_err  = sqrt(/*N_sb_err*N_sb_err*alpha*alpha +*/ alpha_err*alpha_err*N_sb*N_sb);
    histo_PRE_zje1  ->SetBinContent(i+1, N_PRE);
    histo_PRE_zje1  ->SetBinError(  i+1, N_PRE_err);
    N_DY_SR      = DY_SR_zje2->GetBinContent(i+1);
    N_DY_SR_err  = DY_SR_zje2->GetBinError(i+1);
    N_DY_SB      = DY_SB_zje2->GetBinContent(i+1);
    N_DY_SB_err  = DY_SB_zje2->GetBinError(i+1);
    alpha_num     = N_DY_SR + N_VV_SR + N_TT_SR + N_TTV_SR + N_ST_SR;
    alpha_num_err = sqrt(N_DY_SR_err*N_DY_SR_err + N_VV_SR_err*N_VV_SR_err + N_TT_SR_err*N_TT_SR_err + N_TTV_SR_err*N_TTV_SR_err + N_ST_SR_err*N_ST_SR_err);
    alpha_den     = N_DY_SB + N_VV_SB + N_TT_SB + N_TTV_SB + N_ST_SB;
    alpha_den_err = sqrt(N_DY_SB_err*N_DY_SB_err + N_VV_SB_err*N_VV_SB_err + N_TT_SB_err*N_TT_SB_err + N_TTV_SB_err*N_TTV_SB_err + N_ST_SB_err*N_ST_SB_err);
    if(alpha_den!=0) {
      alpha = alpha_num/alpha_den;
      alpha_err = sqrt(alpha_den*alpha_den*alpha_num_err*alpha_num_err + alpha_num*alpha_num*alpha_den_err*alpha_den_err)/(alpha_den*alpha_den);
    }
    N_PRE      = N_sb * alpha;
    N_PRE_err  = sqrt(/*N_sb_err*N_sb_err*alpha*alpha +*/ alpha_err*alpha_err*N_sb*N_sb);
    histo_PRE_zje2  ->SetBinContent(i+1, N_PRE);
    histo_PRE_zje2  ->SetBinError(  i+1, N_PRE_err);
  }
}

void ClosureTestSYST(){
  for(int m=1; m<ERR->GetNbinsX()+1; m++){ 
    histo_PRE_clo2->SetBinContent(m, histo_PRE->GetBinContent(m) * (1 - fabs(histo_PRE_clo1->GetBinContent(m)-histo_DAT_clo1->GetBinContent(m))/histo_PRE_clo1->GetBinContent(m)));
    histo_PRE_clo1->SetBinContent(m, histo_PRE->GetBinContent(m) * (1 + fabs(histo_PRE_clo1->GetBinContent(m)-histo_DAT_clo1->GetBinContent(m))/histo_PRE_clo1->GetBinContent(m)));
  }
}

void MakeHistosPdfQcd(char CUTinit[1000],const char *plot,int BIN1,int BIN2,float MIN,float MAX,int category,int imin,int imax,TH1F* &tptzm0700lh_func1,TH1F* &tptzm0800lh_func1,
		      TH1F* &tptzm0900lh_func1,TH1F* &tptzm1000lh_func1,TH1F* &tptzm1100lh_func1,TH1F* &tptzm1200lh_func1,TH1F* &tptzm1300lh_func1,TH1F* &tptzm1400lh_func1,
		      TH1F* &tptzm1500lh_func1,TH1F* &tptzm1600lh_func1,TH1F* &tptzm1700lh_func1,TH1F* &tptzm0700lh_func2,TH1F* &tptzm0800lh_func2,TH1F* &tptzm0900lh_func2,
		      TH1F* &tptzm1000lh_func2,TH1F* &tptzm1100lh_func2,TH1F* &tptzm1200lh_func2,TH1F* &tptzm1300lh_func2,TH1F* &tptzm1400lh_func2,TH1F* &tptzm1500lh_func2,
		      TH1F* &tptzm1600lh_func2,TH1F* &tptzm1700lh_func2){
  BIN1 = BIN1 + 1;
  TH1F *RMS0700 = new TH1F("RMS0700", "RMS0700", 100,-0.5,0.5); TH1F *RMS0800 = new TH1F("RMS0800", "RMS0800", 100,-0.5,0.5);
  TH1F *RMS0900 = new TH1F("RMS0900", "RMS0900", 100,-0.5,0.5); TH1F *RMS1000 = new TH1F("RMS1000", "RMS1000", 100,-0.5,0.5);
  TH1F *RMS1100 = new TH1F("RMS1100", "RMS1100", 100,-0.5,0.5); TH1F *RMS1200 = new TH1F("RMS1200", "RMS1200", 100,-0.5,0.5);
  TH1F *RMS1300 = new TH1F("RMS1300", "RMS1300", 100,-0.5,0.5); TH1F *RMS1400 = new TH1F("RMS1400", "RMS1400", 100,-0.5,0.5);
  TH1F *RMS1500 = new TH1F("RMS1500", "RMS1500", 100,-0.5,0.5); TH1F *RMS1600 = new TH1F("RMS1600", "RMS1600", 100,-0.5,0.5);
  TH1F *RMS1700 = new TH1F("RMS1700", "RMS1700", 100,-0.5,0.5);
  float INIT1=1; float INIT2=1; float INIT3=1; float INIT4=1; float INIT5=1; float INIT6=1; float INIT7=1; float INIT8=1; float INIT9=1; float INIT10=1; float INIT11=1;
  for(int i=imin; i<imax; i++){
    if(i==5) continue;
    if(i==7) continue;
    int I = 0;
    if(i==111) I=0;
    else       I=i;
    char CUT[1000];
    sprintf(CUT,"(genWeights%i/genWeights0)*%s",I,CUTinit);
    TH1F *SIG01; TH1F *SIG02; TH1F *SIG03; TH1F *SIG04; TH1F *SIG05; TH1F *SIG06; TH1F *SIG07; TH1F *SIG08; TH1F *SIG09; TH1F *SIG10; TH1F *SIG11;
    GetHisto(CUT, TreeS1,  SIG01  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS2,  SIG02  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS3,  SIG03  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS4,  SIG04  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS5,  SIG05  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS6,  SIG06  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS7,  SIG07  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS8,  SIG08  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS9,  SIG09  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS10, SIG10  ,plot,BIN2,MIN,MAX);
    GetHisto(CUT, TreeS11, SIG11  ,plot,BIN2,MIN,MAX);
    if(I==0){ 
      INIT1  = SIG01 ->Integral();
      INIT2  = SIG02 ->Integral();
      INIT3  = SIG03 ->Integral();
      INIT4  = SIG04 ->Integral();
      INIT5  = SIG05 ->Integral();
      INIT6  = SIG06 ->Integral();
      INIT7  = SIG07 ->Integral();
      INIT8  = SIG08 ->Integral();
      INIT9  = SIG09 ->Integral();
      INIT10 = SIG10->Integral();
      INIT11 = SIG11->Integral();
    } else {
      RMS0700->Fill((INIT1 -SIG01->Integral())/INIT1 );
      RMS0800->Fill((INIT2 -SIG02->Integral())/INIT2 );
      RMS0900->Fill((INIT3 -SIG03->Integral())/INIT3 );
      RMS1000->Fill((INIT4 -SIG04->Integral())/INIT4 );
      RMS1100->Fill((INIT5 -SIG05->Integral())/INIT5 );
      RMS1200->Fill((INIT6 -SIG06->Integral())/INIT6 );
      RMS1300->Fill((INIT7 -SIG07->Integral())/INIT7 );
      RMS1400->Fill((INIT8 -SIG08->Integral())/INIT8 );
      RMS1500->Fill((INIT9 -SIG09->Integral())/INIT9 );
      RMS1600->Fill((INIT10-SIG10->Integral())/INIT10);
      RMS1700->Fill((INIT11-SIG11->Integral())/INIT11); 
    }
  }
  tptzm0700lh_func1->SetBinContent(BIN1,tptzm0700lh->GetBinContent(BIN1) + RMS0700->GetRMS());
  tptzm0800lh_func1->SetBinContent(BIN1,tptzm0800lh->GetBinContent(BIN1) + RMS0800->GetRMS());
  tptzm0900lh_func1->SetBinContent(BIN1,tptzm0900lh->GetBinContent(BIN1) + RMS0900->GetRMS());
  tptzm1000lh_func1->SetBinContent(BIN1,tptzm1000lh->GetBinContent(BIN1) + RMS1000->GetRMS());
  tptzm1100lh_func1->SetBinContent(BIN1,tptzm1100lh->GetBinContent(BIN1) + RMS1100->GetRMS());
  tptzm1200lh_func1->SetBinContent(BIN1,tptzm1200lh->GetBinContent(BIN1) + RMS1200->GetRMS());
  tptzm1300lh_func1->SetBinContent(BIN1,tptzm1300lh->GetBinContent(BIN1) + RMS1300->GetRMS());
  tptzm1400lh_func1->SetBinContent(BIN1,tptzm1400lh->GetBinContent(BIN1) + RMS1400->GetRMS());
  tptzm1500lh_func1->SetBinContent(BIN1,tptzm1500lh->GetBinContent(BIN1) + RMS1500->GetRMS());
  tptzm1600lh_func1->SetBinContent(BIN1,tptzm1600lh->GetBinContent(BIN1) + RMS1600->GetRMS());
  tptzm1700lh_func1->SetBinContent(BIN1,tptzm1700lh->GetBinContent(BIN1) + RMS1700->GetRMS());
  tptzm0700lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm0700lh->GetBinContent(BIN1) - RMS0700->GetRMS()));
  tptzm0800lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm0800lh->GetBinContent(BIN1) - RMS0800->GetRMS()));
  tptzm0900lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm0900lh->GetBinContent(BIN1) - RMS0900->GetRMS()));
  tptzm1000lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1000lh->GetBinContent(BIN1) - RMS1000->GetRMS()));
  tptzm1100lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1100lh->GetBinContent(BIN1) - RMS1100->GetRMS()));
  tptzm1200lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1200lh->GetBinContent(BIN1) - RMS1200->GetRMS()));
  tptzm1300lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1300lh->GetBinContent(BIN1) - RMS1300->GetRMS()));
  tptzm1400lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1400lh->GetBinContent(BIN1) - RMS1400->GetRMS()));
  tptzm1500lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1500lh->GetBinContent(BIN1) - RMS1500->GetRMS()));
  tptzm1600lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1600lh->GetBinContent(BIN1) - RMS1600->GetRMS()));
  tptzm1700lh_func2->SetBinContent(BIN1,TMath::Max(0., tptzm1700lh->GetBinContent(BIN1) - RMS1700->GetRMS()));
  delete RMS0700; delete RMS0800; delete RMS0900; delete RMS1000; delete RMS1100; delete RMS1200; delete RMS1300; delete RMS1400; delete RMS1500; delete RMS1600; delete RMS1700;
}
