package com.example.zhineng_jiaju;

/*
    照明界面
 */

import android.content.Context;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.CompoundButton;

import com.chaquo.python.PyObject;
import com.chaquo.python.Python;

public class fragment_zhao_ming extends Fragment implements CompoundButton.OnCheckedChangeListener {

    private CheckBox ck_KeTing_DengYuan1;
    private CheckBox ck_KeTing_DengYuan2;
    private CheckBox ck_CanTing_DengYuan1;
    private CheckBox ck_CanTing_DengYuan2;
    private CheckBox ck_ZhuWo_DengYuan1;
    private CheckBox ck_ZhuWo_DengYuan2;
    private CheckBox ck_CiWo_DengYuan1;
    private CheckBox ck_CiWo_DengYuan2;
    private CheckBox ck_ShuFang_DengYuan1;
    private CheckBox ck_ShuFang_DengYuan2;
    private CheckBox ck_ChuFang_DengYuan1;
    private CheckBox ck_ChuFang_DengYuan2;
    private CheckBox ck_WeiShengJian_DengYuan1;
    private CheckBox ck_WeiShengJian_DengYuan2;
    private CheckBox ck_ZhaoMing_YiJian_KaiGuan;
    private int KeTing_DengYuan_ZhuangTai;
    private int CanTing_DengYuan_ZhuangTai;
    private int ZhuWo_DengYuan_ZhuangTai;
    private int CiWo_DengYuan_ZhuangTai;
    private int ShuFang_DengYuan_ZhuangTai;
    private int ChuFang_DengYuan_ZhuangTai;
    private int WeiShengJian_DengYuan_ZhuangTai;
    private PyObject pyObject;
    String ZhaoMing_ShuJu;

    public fragment_zhao_ming() {

    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        Context context = getContext();
        View view = LayoutInflater.from(context).inflate(R.layout.fragment_zhao_ming, container, false);

        Python python = Python.getInstance(); // 初始化Python环境
        pyObject = python.getModule("Python_API");//"Python_API"为需要调用的Python文件名

        //客厅
        ck_KeTing_DengYuan1 = view.findViewById(R.id.ck_KeTing_DengYuan1);
        ck_KeTing_DengYuan2 = view.findViewById(R.id.ck_KeTing_DengYuan2);
        //餐厅
        ck_CanTing_DengYuan1 = view.findViewById(R.id.ck_CanTing_DengYuan1);
        ck_CanTing_DengYuan2 = view.findViewById(R.id.ck_CanTing_DengYuan2);
        //主卧
        ck_ZhuWo_DengYuan1 = view.findViewById(R.id.ck_ZhuWo_DengYuan1);
        ck_ZhuWo_DengYuan2 = view.findViewById(R.id.ck_ZhuWo_DengYuan2);
        //次卧
        ck_CiWo_DengYuan1 = view.findViewById(R.id.ck_CiWo_DengYuan1);
        ck_CiWo_DengYuan2 = view.findViewById(R.id.ck_CiWo_DengYuan2);
        //书房
        ck_ShuFang_DengYuan1 = view.findViewById(R.id.ck_ShuFang_DengYuan1);
        ck_ShuFang_DengYuan2 = view.findViewById(R.id.ck_ShuFang_DengYuan2);
        //厨房
        ck_ChuFang_DengYuan1 = view.findViewById(R.id.ck_ChuFang_DengYuan1);
        ck_ChuFang_DengYuan2 = view.findViewById(R.id.ck_ChuFang_DengYuan2);
        //卫生间
        ck_WeiShengJian_DengYuan1 = view.findViewById(R.id.ck_WeiShengJian_DengYuan1);
        ck_WeiShengJian_DengYuan2 = view.findViewById(R.id.ck_WeiShengJian_DengYuan2);
        //一键开关
        ck_ZhaoMing_YiJian_KaiGuan = view.findViewById(R.id.ck_ZhaoMing_YiJian_KaiGuan);

        ck_KeTing_DengYuan1.setOnCheckedChangeListener(this);
        ck_KeTing_DengYuan2.setOnCheckedChangeListener(this);
        ck_CanTing_DengYuan1.setOnCheckedChangeListener(this);
        ck_CanTing_DengYuan2.setOnCheckedChangeListener(this);
        ck_ZhuWo_DengYuan1.setOnCheckedChangeListener(this);
        ck_ZhuWo_DengYuan2.setOnCheckedChangeListener(this);
        ck_CiWo_DengYuan1.setOnCheckedChangeListener(this);
        ck_CiWo_DengYuan2.setOnCheckedChangeListener(this);
        ck_ShuFang_DengYuan1.setOnCheckedChangeListener(this);
        ck_ShuFang_DengYuan2.setOnCheckedChangeListener(this);
        ck_ChuFang_DengYuan1.setOnCheckedChangeListener(this);
        ck_ChuFang_DengYuan2.setOnCheckedChangeListener(this);
        ck_WeiShengJian_DengYuan1.setOnCheckedChangeListener(this);
        ck_WeiShengJian_DengYuan2.setOnCheckedChangeListener(this);
        ck_ZhaoMing_YiJian_KaiGuan.setOnCheckedChangeListener(this);


        //获取云数据的照明表数据
        PyObject ret = pyObject.callAttr("get_ZhaoMing_ShuJu");//"get_ZhaoMing_ShuJu"为需要调用的函数名
        ZhaoMing_ShuJu = String.valueOf(ret);
        String[] strs = ZhaoMing_ShuJu.split(",");//分割数据
        KeTing_DengYuan_ZhuangTai = Integer.parseInt(strs[0]);
        CanTing_DengYuan_ZhuangTai = Integer.parseInt(strs[1]);
        ZhuWo_DengYuan_ZhuangTai = Integer.parseInt(strs[2]);
        CiWo_DengYuan_ZhuangTai = Integer.parseInt(strs[3]);
        ShuFang_DengYuan_ZhuangTai = Integer.parseInt(strs[4]);
        ChuFang_DengYuan_ZhuangTai = Integer.parseInt(strs[5]);
        WeiShengJian_DengYuan_ZhuangTai = Integer.parseInt(strs[6]);

        //将获取到的数据设置到界面上
        switch (KeTing_DengYuan_ZhuangTai) {
            case 0: {
                ck_KeTing_DengYuan1.setChecked(false);
                ck_KeTing_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_KeTing_DengYuan1.setChecked(false);
                ck_KeTing_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_KeTing_DengYuan1.setChecked(true);
                ck_KeTing_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_KeTing_DengYuan1.setChecked(true);
                ck_KeTing_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (CanTing_DengYuan_ZhuangTai) {
            case 0: {
                ck_CanTing_DengYuan1.setChecked(false);
                ck_CanTing_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_CanTing_DengYuan1.setChecked(false);
                ck_CanTing_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_CanTing_DengYuan1.setChecked(true);
                ck_CanTing_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_CanTing_DengYuan1.setChecked(true);
                ck_CanTing_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (ZhuWo_DengYuan_ZhuangTai) {
            case 0: {
                ck_ZhuWo_DengYuan1.setChecked(false);
                ck_ZhuWo_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_ZhuWo_DengYuan1.setChecked(false);
                ck_ZhuWo_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_ZhuWo_DengYuan1.setChecked(true);
                ck_ZhuWo_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_ZhuWo_DengYuan1.setChecked(true);
                ck_ZhuWo_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (CiWo_DengYuan_ZhuangTai) {
            case 0: {
                ck_CiWo_DengYuan1.setChecked(false);
                ck_CiWo_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_CiWo_DengYuan1.setChecked(false);
                ck_CiWo_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_CiWo_DengYuan1.setChecked(true);
                ck_CiWo_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_CiWo_DengYuan1.setChecked(true);
                ck_CiWo_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (ShuFang_DengYuan_ZhuangTai) {
            case 0: {
                ck_ShuFang_DengYuan1.setChecked(false);
                ck_ShuFang_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_ShuFang_DengYuan1.setChecked(false);
                ck_ShuFang_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_ShuFang_DengYuan1.setChecked(true);
                ck_ShuFang_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_ShuFang_DengYuan1.setChecked(true);
                ck_ShuFang_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (ChuFang_DengYuan_ZhuangTai) {
            case 0: {
                ck_ChuFang_DengYuan1.setChecked(false);
                ck_ChuFang_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_ChuFang_DengYuan1.setChecked(false);
                ck_ChuFang_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_ChuFang_DengYuan1.setChecked(true);
                ck_ChuFang_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_ChuFang_DengYuan1.setChecked(true);
                ck_ChuFang_DengYuan2.setChecked(true);
                break;
            }
        }
        switch (WeiShengJian_DengYuan_ZhuangTai) {
            case 0: {
                ck_WeiShengJian_DengYuan1.setChecked(false);
                ck_WeiShengJian_DengYuan2.setChecked(false);
                break;
            }
            case 1: {
                ck_WeiShengJian_DengYuan1.setChecked(false);
                ck_WeiShengJian_DengYuan2.setChecked(true);
                break;
            }
            case 2: {
                ck_WeiShengJian_DengYuan1.setChecked(true);
                ck_WeiShengJian_DengYuan2.setChecked(false);
                break;
            }
            case 3: {
                ck_WeiShengJian_DengYuan1.setChecked(true);
                ck_WeiShengJian_DengYuan2.setChecked(true);
                break;
            }
        }

        return view;
    }

    @Override
    public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
        switch (compoundButton.getId()) {
            case R.id.ck_KeTing_DengYuan1: {
                if (isChecked) {
                    KeTing_DengYuan_ZhuangTai = KeTing_DengYuan_ZhuangTai | 2;
                } else {
                    KeTing_DengYuan_ZhuangTai = KeTing_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "KeTing", KeTing_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_KeTing_DengYuan2: {
                if (isChecked) {
                    KeTing_DengYuan_ZhuangTai = KeTing_DengYuan_ZhuangTai | 1;
                } else {
                    KeTing_DengYuan_ZhuangTai = KeTing_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "KeTing", KeTing_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_CanTing_DengYuan1: {
                if (isChecked) {
                    CanTing_DengYuan_ZhuangTai = CanTing_DengYuan_ZhuangTai | 2;
                } else {
                    CanTing_DengYuan_ZhuangTai = CanTing_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "CanTing", CanTing_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_CanTing_DengYuan2: {
                if (isChecked) {
                    CanTing_DengYuan_ZhuangTai = CanTing_DengYuan_ZhuangTai | 1;
                } else {
                    CanTing_DengYuan_ZhuangTai = CanTing_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "CanTing", CanTing_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ZhuWo_DengYuan1: {
                if (isChecked) {
                    ZhuWo_DengYuan_ZhuangTai = ZhuWo_DengYuan_ZhuangTai | 2;
                } else {
                    ZhuWo_DengYuan_ZhuangTai = ZhuWo_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ZhuWo", ZhuWo_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ZhuWo_DengYuan2: {
                if (isChecked) {
                    ZhuWo_DengYuan_ZhuangTai = ZhuWo_DengYuan_ZhuangTai | 1;
                } else {
                    ZhuWo_DengYuan_ZhuangTai = ZhuWo_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ZhuWo", ZhuWo_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_CiWo_DengYuan1: {
                if (isChecked) {
                    CiWo_DengYuan_ZhuangTai = CiWo_DengYuan_ZhuangTai | 2;
                } else {
                    CiWo_DengYuan_ZhuangTai = CiWo_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "CiWo", CiWo_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_CiWo_DengYuan2: {
                if (isChecked) {
                    CiWo_DengYuan_ZhuangTai = CiWo_DengYuan_ZhuangTai | 1;
                } else {
                    CiWo_DengYuan_ZhuangTai = CiWo_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "CiWo", CiWo_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ShuFang_DengYuan1: {
                if (isChecked) {
                    ShuFang_DengYuan_ZhuangTai = ShuFang_DengYuan_ZhuangTai | 2;
                } else {
                    ShuFang_DengYuan_ZhuangTai = ShuFang_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ShuFang", ShuFang_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ShuFang_DengYuan2: {
                if (isChecked) {
                    ShuFang_DengYuan_ZhuangTai = ShuFang_DengYuan_ZhuangTai | 1;
                } else {
                    ShuFang_DengYuan_ZhuangTai = ShuFang_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ShuFang", ShuFang_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ChuFang_DengYuan1: {
                if (isChecked) {
                    ChuFang_DengYuan_ZhuangTai = ChuFang_DengYuan_ZhuangTai | 2;
                } else {
                    ChuFang_DengYuan_ZhuangTai = ChuFang_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ChuFang", ChuFang_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ChuFang_DengYuan2: {
                if (isChecked) {
                    ChuFang_DengYuan_ZhuangTai = ChuFang_DengYuan_ZhuangTai | 1;
                } else {
                    ChuFang_DengYuan_ZhuangTai = ChuFang_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "ChuFang", ChuFang_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_WeiShengJian_DengYuan1: {
                if (isChecked) {
                    WeiShengJian_DengYuan_ZhuangTai = WeiShengJian_DengYuan_ZhuangTai | 2;
                } else {
                    WeiShengJian_DengYuan_ZhuangTai = WeiShengJian_DengYuan_ZhuangTai & 1;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "WeiShengJian", WeiShengJian_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_WeiShengJian_DengYuan2: {
                if (isChecked) {
                    WeiShengJian_DengYuan_ZhuangTai = WeiShengJian_DengYuan_ZhuangTai | 1;
                } else {
                    WeiShengJian_DengYuan_ZhuangTai = WeiShengJian_DengYuan_ZhuangTai & 2;
                }
                ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi();
                pyObject.callAttr("ZhaoMing_DengYuan_DuLi_KaiGuan", "WeiShengJian", WeiShengJian_DengYuan_ZhuangTai);//"ZhaoMing_DengYuan_DuLi_KaiGuan"为需要调用的函数名
                break;
            }
            case R.id.ck_ZhaoMing_YiJian_KaiGuan: {
                if (isChecked) {
                    KeTing_DengYuan_ZhuangTai = 3;
                    CanTing_DengYuan_ZhuangTai = 3;
                    ZhuWo_DengYuan_ZhuangTai = 3;
                    CiWo_DengYuan_ZhuangTai = 3;
                    ShuFang_DengYuan_ZhuangTai = 3;
                    ChuFang_DengYuan_ZhuangTai = 3;
                    WeiShengJian_DengYuan_ZhuangTai = 3;

                    ck_KeTing_DengYuan1.setChecked(true);
                    ck_KeTing_DengYuan2.setChecked(true);
                    ck_CanTing_DengYuan1.setChecked(true);
                    ck_CanTing_DengYuan2.setChecked(true);
                    ck_ZhuWo_DengYuan1.setChecked(true);
                    ck_ZhuWo_DengYuan2.setChecked(true);
                    ck_CiWo_DengYuan1.setChecked(true);
                    ck_CiWo_DengYuan2.setChecked(true);
                    ck_ShuFang_DengYuan1.setChecked(true);
                    ck_ShuFang_DengYuan2.setChecked(true);
                    ck_ChuFang_DengYuan1.setChecked(true);
                    ck_ChuFang_DengYuan2.setChecked(true);
                    ck_WeiShengJian_DengYuan1.setChecked(true);
                    ck_WeiShengJian_DengYuan2.setChecked(true);

                    pyObject.callAttr("ZhaoMing_DengYuan_YiJian_KaiGuan", "3");//"ZhaoMing_DengYuan_YiJian_KaiGuan"为需要调用的函数名
                } else {
                    KeTing_DengYuan_ZhuangTai = 0;
                    CanTing_DengYuan_ZhuangTai = 0;
                    ZhuWo_DengYuan_ZhuangTai = 0;
                    CiWo_DengYuan_ZhuangTai = 0;
                    ShuFang_DengYuan_ZhuangTai = 0;
                    ChuFang_DengYuan_ZhuangTai = 0;
                    WeiShengJian_DengYuan_ZhuangTai = 0;

                    ck_KeTing_DengYuan1.setChecked(false);
                    ck_KeTing_DengYuan2.setChecked(false);
                    ck_CanTing_DengYuan1.setChecked(false);
                    ck_CanTing_DengYuan2.setChecked(false);
                    ck_ZhuWo_DengYuan1.setChecked(false);
                    ck_ZhuWo_DengYuan2.setChecked(false);
                    ck_CiWo_DengYuan1.setChecked(false);
                    ck_CiWo_DengYuan2.setChecked(false);
                    ck_ShuFang_DengYuan1.setChecked(false);
                    ck_ShuFang_DengYuan2.setChecked(false);
                    ck_ChuFang_DengYuan1.setChecked(false);
                    ck_ChuFang_DengYuan2.setChecked(false);
                    ck_WeiShengJian_DengYuan1.setChecked(false);
                    ck_WeiShengJian_DengYuan2.setChecked(false);

                    pyObject.callAttr("ZhaoMing_DengYuan_YiJian_KaiGuan", "0");//"ZhaoMing_DengYuan_YiJian_KaiGuan"为需要调用的函数名
                }
                break;
            }
        }
    }

    //照明一键开关状态设置
    public void ZhaoMing_YiJian_KaiGuan_ZhuangTai_SheZhi() {
        if (KeTing_DengYuan_ZhuangTai == 3 && CanTing_DengYuan_ZhuangTai == 3 && ZhuWo_DengYuan_ZhuangTai == 3 && CiWo_DengYuan_ZhuangTai == 3 && ShuFang_DengYuan_ZhuangTai == 3 && ChuFang_DengYuan_ZhuangTai == 3 && WeiShengJian_DengYuan_ZhuangTai == 3) {
            ck_ZhaoMing_YiJian_KaiGuan.setChecked(true);
        } else if (KeTing_DengYuan_ZhuangTai == 0 && CanTing_DengYuan_ZhuangTai == 0 && ZhuWo_DengYuan_ZhuangTai == 0 && CiWo_DengYuan_ZhuangTai == 0 && ShuFang_DengYuan_ZhuangTai == 0 && ChuFang_DengYuan_ZhuangTai == 0 && WeiShengJian_DengYuan_ZhuangTai == 0) {
            ck_ZhaoMing_YiJian_KaiGuan.setChecked(false);
        }
    }
}