package com.example.zhineng_jiaju;

import android.annotation.SuppressLint;
import android.content.Context;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageButton;
import android.widget.TextView;

import com.chaquo.python.PyObject;
import com.chaquo.python.Python;

public class fragment_NuanTong extends Fragment implements View.OnClickListener, CompoundButton.OnCheckedChangeListener {

    private PyObject pyObject;
    private TextView tv_NuanTong_KeTing_WenDu;
    private TextView tv_NuanTong_KeTing_FengSu;
    private TextView tv_NuanTong_KeTing_MoShi;
    private TextView tv_NuanTong_ZhuWo_WenDu;
    private TextView tv_NuanTong_ZhuWo_FengSu;
    private TextView tv_NuanTong_ZhuWo_MoShi;
    private TextView tv_NuanTong_CiWo_WenDu;
    private TextView tv_NuanTong_CiWo_FengSu;
    private TextView tv_NuanTong_CiWo_MoShi;
    private TextView tv_NuanTong_ShuFang_WenDu;
    private TextView tv_NuanTong_ShuFang_FengSu;
    private TextView tv_NuanTong_ShuFang_MoShi;
    private ImageButton Ibtn_NuanTong_KeTing_Jian;
    private CheckBox ck_NuanTong_KeTing_KaiGuan;
    private ImageButton Ibtn_NuanTong_KeTing_Jia;
    private Button btn_NuanTong_KeTing_FengSu;
    private Button btn_NuanTong_KeTing_MoShi;
    private ImageButton Ibtn_NuanTong_ZhuWo_Jian;
    private CheckBox ck_NuanTong_ZhuWo_KaiGuan;
    private ImageButton Ibtn_NuanTong_ZhuWo_Jia;
    private Button btn_NuanTong_ZhuWo_FengSu;
    private Button btn_NuanTong_ZhuWo_MoShi;
    private ImageButton Ibtn_NuanTong_CiWo_Jian;
    private CheckBox ck_NuanTong_CiWo_KaiGuan;
    private ImageButton Ibtn_NuanTong_CiWo_Jia;
    private Button btn_NuanTong_CiWo_FengSu;
    private Button btn_NuanTong_CiWo_MoShi;
    private ImageButton Ibtn_NuanTong_ShuFang_Jian;
    private CheckBox ck_NuanTong_ShuFang_KaiGuan;
    private ImageButton Ibtn_NuanTong_ShuFang_Jia;
    private Button btn_NuanTong_ShuFang_FengSu;
    private Button btn_NuanTong_ShuFang_MoShi;
    private CheckBox ck_NuanTong_YiJian_KaiGuan;
    String NuanTong_ShuJu;
    private int NuanTong_KeTing_ShuJu;
    private int NuanTong_ZhuWo_ShuJu;
    private int NuanTong_CiWo_ShuJu;
    private int NuanTong_ShuFang_ShuJu;
    private int NuanTong_KeTing_WenDu;
    private int NuanTong_KeTing_MoShi;
    private int NuanTong_KeTing_FengSu;
    private int NuanTong_KeTing_KaiGuan;
    private int NuanTong_ZhuWo_WenDu;
    private int NuanTong_ZhuWo_MoShi;
    private int NuanTong_ZhuWo_FengSu;
    private int NuanTong_ZhuWo_KaiGuan;
    private int NuanTong_CiWo_WenDu;
    private int NuanTong_CiWo_MoShi;
    private int NuanTong_CiWo_FengSu;
    private int NuanTong_CiWo_KaiGuan;
    private int NuanTong_ShuFang_WenDu;
    private int NuanTong_ShuFang_MoShi;
    private int NuanTong_ShuFang_FengSu;
    private int NuanTong_ShuFang_KaiGuan;
    String WenDu_FuHao = "℃";
    String[] NuanTong_MoShi = {"模式：制冷", "模式：制热", "模式：通风"};//暖通模式
    String[] NuanTong_FengSu = {"风速：低风", "风速：中风", "风速：高风"};//暖通风速
    private int NuanTong_KeTing_ShuJu_int;
    private int NuanTong_ZhuWo_ShuJu_int;
    private int NuanTong_CiWo_ShuJu_int;
    private int NuanTong_ShuFang_ShuJu_int;

    public fragment_NuanTong() {

    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @SuppressLint("SetTextI18n")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        Context context = getContext();
        View view = LayoutInflater.from(context).inflate(R.layout.fragment_nuan_tong, container, false);

        Python python = Python.getInstance(); // 初始化Python环境
        pyObject = python.getModule("Python_API");//"Python_API"为需要调用的Python文件名

        tv_NuanTong_KeTing_WenDu = view.findViewById(R.id.tv_NuanTong_KeTing_WenDu);
        tv_NuanTong_KeTing_FengSu = view.findViewById(R.id.tv_NuanTong_KeTing_FengSu);
        tv_NuanTong_KeTing_MoShi = view.findViewById(R.id.tv_NuanTong_KeTing_MoShi);
        Ibtn_NuanTong_KeTing_Jian = view.findViewById(R.id.Ibtn_NuanTong_KeTing_Jian);
        ck_NuanTong_KeTing_KaiGuan = view.findViewById(R.id.ck_NuanTong_KeTing_KaiGuan);
        Ibtn_NuanTong_KeTing_Jia = view.findViewById(R.id.Ibtn_NuanTong_KeTing_Jia);
        btn_NuanTong_KeTing_FengSu = view.findViewById(R.id.btn_NuanTong_KeTing_FengSu);
        btn_NuanTong_KeTing_MoShi = view.findViewById(R.id.btn_NuanTong_KeTing_MoShi);

        tv_NuanTong_ZhuWo_WenDu = view.findViewById(R.id.tv_NuanTong_ZhuWo_WenDu);
        tv_NuanTong_ZhuWo_FengSu = view.findViewById(R.id.tv_NuanTong_ZhuWo_FengSu);
        tv_NuanTong_ZhuWo_MoShi = view.findViewById(R.id.tv_NuanTong_ZhuWo_MoShi);
        Ibtn_NuanTong_ZhuWo_Jian = view.findViewById(R.id.Ibtn_NuanTong_ZhuWo_Jian);
        ck_NuanTong_ZhuWo_KaiGuan = view.findViewById(R.id.ck_NuanTong_ZhuWo_KaiGuan);
        Ibtn_NuanTong_ZhuWo_Jia = view.findViewById(R.id.Ibtn_NuanTong_ZhuWo_Jia);
        btn_NuanTong_ZhuWo_FengSu = view.findViewById(R.id.btn_NuanTong_ZhuWo_FengSu);
        btn_NuanTong_ZhuWo_MoShi = view.findViewById(R.id.btn_NuanTong_ZhuWo_MoShi);

        tv_NuanTong_CiWo_WenDu = view.findViewById(R.id.tv_NuanTong_CiWo_WenDu);
        tv_NuanTong_CiWo_FengSu = view.findViewById(R.id.tv_NuanTong_CiWo_FengSu);
        tv_NuanTong_CiWo_MoShi = view.findViewById(R.id.tv_NuanTong_CiWo_MoShi);
        Ibtn_NuanTong_CiWo_Jian = view.findViewById(R.id.Ibtn_NuanTong_CiWo_Jian);
        ck_NuanTong_CiWo_KaiGuan = view.findViewById(R.id.ck_NuanTong_CiWo_KaiGuan);
        Ibtn_NuanTong_CiWo_Jia = view.findViewById(R.id.Ibtn_NuanTong_CiWo_Jia);
        btn_NuanTong_CiWo_FengSu = view.findViewById(R.id.btn_NuanTong_CiWo_FengSu);
        btn_NuanTong_CiWo_MoShi = view.findViewById(R.id.btn_NuanTong_CiWo_MoShi);

        tv_NuanTong_ShuFang_WenDu = view.findViewById(R.id.tv_NuanTong_ShuFang_WenDu);
        tv_NuanTong_ShuFang_FengSu = view.findViewById(R.id.tv_NuanTong_ShuFang_FengSu);
        tv_NuanTong_ShuFang_MoShi = view.findViewById(R.id.tv_NuanTong_ShuFang_MoShi);
        Ibtn_NuanTong_ShuFang_Jian = view.findViewById(R.id.Ibtn_NuanTong_ShuFang_Jian);
        ck_NuanTong_ShuFang_KaiGuan = view.findViewById(R.id.ck_NuanTong_ShuFang_KaiGuan);
        Ibtn_NuanTong_ShuFang_Jia = view.findViewById(R.id.Ibtn_NuanTong_ShuFang_Jia);
        btn_NuanTong_ShuFang_FengSu = view.findViewById(R.id.btn_NuanTong_ShuFang_FengSu);
        btn_NuanTong_ShuFang_MoShi = view.findViewById(R.id.btn_NuanTong_ShuFang_MoShi);

        ck_NuanTong_YiJian_KaiGuan = view.findViewById(R.id.ck_NuanTong_YiJian_KaiGuan);

        Ibtn_NuanTong_KeTing_Jian.setOnClickListener(this);
        ck_NuanTong_KeTing_KaiGuan.setOnCheckedChangeListener(this);
        Ibtn_NuanTong_KeTing_Jia.setOnClickListener(this);
        btn_NuanTong_KeTing_FengSu.setOnClickListener(this);
        btn_NuanTong_KeTing_MoShi.setOnClickListener(this);

        Ibtn_NuanTong_ZhuWo_Jian.setOnClickListener(this);
        ck_NuanTong_ZhuWo_KaiGuan.setOnCheckedChangeListener(this);
        Ibtn_NuanTong_ZhuWo_Jia.setOnClickListener(this);
        btn_NuanTong_ZhuWo_FengSu.setOnClickListener(this);
        btn_NuanTong_ZhuWo_MoShi.setOnClickListener(this);

        Ibtn_NuanTong_CiWo_Jian.setOnClickListener(this);
        ck_NuanTong_CiWo_KaiGuan.setOnCheckedChangeListener(this);
        Ibtn_NuanTong_CiWo_Jia.setOnClickListener(this);
        btn_NuanTong_CiWo_FengSu.setOnClickListener(this);
        btn_NuanTong_CiWo_MoShi.setOnClickListener(this);

        Ibtn_NuanTong_ShuFang_Jian.setOnClickListener(this);
        ck_NuanTong_ShuFang_KaiGuan.setOnCheckedChangeListener(this);
        Ibtn_NuanTong_ShuFang_Jia.setOnClickListener(this);
        btn_NuanTong_ShuFang_FengSu.setOnClickListener(this);
        btn_NuanTong_ShuFang_MoShi.setOnClickListener(this);

        ck_NuanTong_YiJian_KaiGuan.setOnCheckedChangeListener(this);

        //获取云数据的暖通表数据
        PyObject ret = pyObject.callAttr("get_NuanTong_ShuJu");//"get_NuanTong_ShuJu"为需要调用的函数名
        NuanTong_ShuJu = String.valueOf(ret);
        String[] strs = NuanTong_ShuJu.split(",");//分割数据
        NuanTong_KeTing_ShuJu = Integer.parseInt(strs[0]);
        NuanTong_ZhuWo_ShuJu = Integer.parseInt(strs[1]);
        NuanTong_CiWo_ShuJu = Integer.parseInt(strs[2]);
        NuanTong_ShuFang_ShuJu = Integer.parseInt(strs[3]);

        //数据解释
        NuanTong_KeTing_WenDu = NuanTong_KeTing_ShuJu / 1000;
        NuanTong_KeTing_MoShi = NuanTong_KeTing_ShuJu / 100 % 10;
        NuanTong_KeTing_FengSu = NuanTong_KeTing_ShuJu / 10 % 10;
        NuanTong_KeTing_KaiGuan = NuanTong_KeTing_ShuJu % 10;

        NuanTong_ZhuWo_WenDu = NuanTong_ZhuWo_ShuJu / 1000;
        NuanTong_ZhuWo_MoShi = NuanTong_ZhuWo_ShuJu / 100 % 10;
        NuanTong_ZhuWo_FengSu = NuanTong_ZhuWo_ShuJu / 10 % 10;
        NuanTong_ZhuWo_KaiGuan = NuanTong_ZhuWo_ShuJu % 10;

        NuanTong_CiWo_WenDu = NuanTong_CiWo_ShuJu / 1000;
        NuanTong_CiWo_MoShi = NuanTong_CiWo_ShuJu / 100 % 10;
        NuanTong_CiWo_FengSu = NuanTong_CiWo_ShuJu / 10 % 10;
        NuanTong_CiWo_KaiGuan = NuanTong_CiWo_ShuJu % 10;

        NuanTong_ShuFang_WenDu = NuanTong_ShuFang_ShuJu / 1000;
        NuanTong_ShuFang_MoShi = NuanTong_ShuFang_ShuJu / 100 % 10;
        NuanTong_ShuFang_FengSu = NuanTong_ShuFang_ShuJu / 10 % 10;
        NuanTong_ShuFang_KaiGuan = NuanTong_ShuFang_ShuJu % 10;

        //将获取到的数据设置到界面上
        if (NuanTong_KeTing_KaiGuan == 1) {
            ck_NuanTong_KeTing_KaiGuan.setChecked(true);
            tv_NuanTong_KeTing_WenDu.setText(NuanTong_KeTing_WenDu + WenDu_FuHao);
            tv_NuanTong_KeTing_FengSu.setText(NuanTong_FengSu[NuanTong_KeTing_FengSu]);
            tv_NuanTong_KeTing_MoShi.setText(NuanTong_MoShi[NuanTong_KeTing_MoShi]);
        } else {
            ck_NuanTong_KeTing_KaiGuan.setChecked(false);
            tv_NuanTong_KeTing_WenDu.setText("");
            tv_NuanTong_KeTing_FengSu.setText("");
            tv_NuanTong_KeTing_MoShi.setText("");
        }
        if (NuanTong_ZhuWo_KaiGuan == 1) {
            ck_NuanTong_ZhuWo_KaiGuan.setChecked(true);
            tv_NuanTong_ZhuWo_WenDu.setText(NuanTong_ZhuWo_WenDu + WenDu_FuHao);
            tv_NuanTong_ZhuWo_FengSu.setText(NuanTong_FengSu[NuanTong_ZhuWo_FengSu]);
            tv_NuanTong_ZhuWo_MoShi.setText(NuanTong_MoShi[NuanTong_ZhuWo_MoShi]);
        } else {
            ck_NuanTong_ZhuWo_KaiGuan.setChecked(false);
            tv_NuanTong_ZhuWo_WenDu.setText("");
            tv_NuanTong_ZhuWo_FengSu.setText("");
            tv_NuanTong_ZhuWo_MoShi.setText("");
        }
        if (NuanTong_CiWo_KaiGuan == 1) {
            ck_NuanTong_CiWo_KaiGuan.setChecked(true);
            tv_NuanTong_CiWo_WenDu.setText(NuanTong_CiWo_WenDu + WenDu_FuHao);
            tv_NuanTong_CiWo_FengSu.setText(NuanTong_FengSu[NuanTong_CiWo_FengSu]);
            tv_NuanTong_CiWo_MoShi.setText(NuanTong_MoShi[NuanTong_CiWo_MoShi]);
        } else {
            ck_NuanTong_CiWo_KaiGuan.setChecked(false);
            tv_NuanTong_CiWo_WenDu.setText("");
            tv_NuanTong_CiWo_FengSu.setText("");
            tv_NuanTong_CiWo_MoShi.setText("");
        }
        if (NuanTong_ShuFang_KaiGuan == 1) {
            ck_NuanTong_ShuFang_KaiGuan.setChecked(true);
            tv_NuanTong_ShuFang_WenDu.setText(NuanTong_ShuFang_WenDu + WenDu_FuHao);
            tv_NuanTong_ShuFang_FengSu.setText(NuanTong_FengSu[NuanTong_ShuFang_FengSu]);
            tv_NuanTong_ShuFang_MoShi.setText(NuanTong_MoShi[NuanTong_ShuFang_MoShi]);
        } else {
            ck_NuanTong_ShuFang_KaiGuan.setChecked(false);
            tv_NuanTong_ShuFang_WenDu.setText("");
            tv_NuanTong_ShuFang_FengSu.setText("");
            tv_NuanTong_ShuFang_MoShi.setText("");
        }
        NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi();

        return view;
    }

    @SuppressLint("SetTextI18n")
    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            //客厅
            case R.id.Ibtn_NuanTong_KeTing_Jian: {
                if (ck_NuanTong_KeTing_KaiGuan.isChecked()) {
                    NuanTong_KeTing_WenDu--;
                    if (NuanTong_KeTing_WenDu <= 16) {
                        NuanTong_KeTing_WenDu = 16;
                    }
                    NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "KeTing", NuanTong_KeTing_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_KeTing_WenDu.setText(NuanTong_KeTing_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.Ibtn_NuanTong_KeTing_Jia: {
                if (ck_NuanTong_KeTing_KaiGuan.isChecked()) {
                    NuanTong_KeTing_WenDu++;
                    if (NuanTong_KeTing_WenDu >= 30) {
                        NuanTong_KeTing_WenDu = 30;
                    }
                    NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "KeTing", NuanTong_KeTing_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_KeTing_WenDu.setText(NuanTong_KeTing_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.btn_NuanTong_KeTing_FengSu: {
                if (ck_NuanTong_KeTing_KaiGuan.isChecked()) {
                    NuanTong_KeTing_FengSu++;
                    NuanTong_KeTing_FengSu = NuanTong_KeTing_FengSu % 3;
                    NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "KeTing", NuanTong_KeTing_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_KeTing_FengSu.setText(NuanTong_FengSu[NuanTong_KeTing_FengSu]);
                }
                break;
            }
            case R.id.btn_NuanTong_KeTing_MoShi: {
                if (ck_NuanTong_KeTing_KaiGuan.isChecked()) {
                    NuanTong_KeTing_MoShi++;
                    NuanTong_KeTing_MoShi = NuanTong_KeTing_MoShi % 3;
                    NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "KeTing", NuanTong_KeTing_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_KeTing_MoShi.setText(NuanTong_MoShi[NuanTong_KeTing_MoShi]);
                }
                break;
            }
            //主卧
            case R.id.Ibtn_NuanTong_ZhuWo_Jian: {
                if (ck_NuanTong_ZhuWo_KaiGuan.isChecked()) {
                    NuanTong_ZhuWo_WenDu--;
                    if (NuanTong_ZhuWo_WenDu <= 16) {
                        NuanTong_ZhuWo_WenDu = 16;
                    }
                    NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ZhuWo", NuanTong_ZhuWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ZhuWo_WenDu.setText(NuanTong_ZhuWo_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.Ibtn_NuanTong_ZhuWo_Jia: {
                if (ck_NuanTong_ZhuWo_KaiGuan.isChecked()) {
                    NuanTong_ZhuWo_WenDu++;
                    if (NuanTong_ZhuWo_WenDu >= 30) {
                        NuanTong_ZhuWo_WenDu = 30;
                    }
                    NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ZhuWo", NuanTong_ZhuWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ZhuWo_WenDu.setText(NuanTong_ZhuWo_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.btn_NuanTong_ZhuWo_FengSu: {
                if (ck_NuanTong_ZhuWo_KaiGuan.isChecked()) {
                    NuanTong_ZhuWo_FengSu++;
                    NuanTong_ZhuWo_FengSu = NuanTong_ZhuWo_FengSu % 3;
                    NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ZhuWo", NuanTong_ZhuWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ZhuWo_FengSu.setText(NuanTong_FengSu[NuanTong_ZhuWo_FengSu]);
                }
                break;
            }
            case R.id.btn_NuanTong_ZhuWo_MoShi: {
                if (ck_NuanTong_ZhuWo_KaiGuan.isChecked()) {
                    NuanTong_ZhuWo_MoShi++;
                    NuanTong_ZhuWo_MoShi = NuanTong_ZhuWo_MoShi % 3;
                    NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ZhuWo", NuanTong_ZhuWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ZhuWo_MoShi.setText(NuanTong_MoShi[NuanTong_ZhuWo_MoShi]);
                }
                break;
            }
            //次卧
            case R.id.Ibtn_NuanTong_CiWo_Jian: {
                if (ck_NuanTong_CiWo_KaiGuan.isChecked()) {
                    NuanTong_CiWo_WenDu--;
                    if (NuanTong_CiWo_WenDu <= 16) {
                        NuanTong_CiWo_WenDu = 16;
                    }
                    NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "CiWo", NuanTong_CiWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_CiWo_WenDu.setText(NuanTong_CiWo_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.Ibtn_NuanTong_CiWo_Jia: {
                if (ck_NuanTong_CiWo_KaiGuan.isChecked()) {
                    NuanTong_CiWo_WenDu++;
                    if (NuanTong_CiWo_WenDu >= 30) {
                        NuanTong_CiWo_WenDu = 30;
                    }
                    NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "CiWo", NuanTong_CiWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_CiWo_WenDu.setText(NuanTong_CiWo_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.btn_NuanTong_CiWo_FengSu: {
                if (ck_NuanTong_CiWo_KaiGuan.isChecked()) {
                    NuanTong_CiWo_FengSu++;
                    NuanTong_CiWo_FengSu = NuanTong_CiWo_FengSu % 3;
                    NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "CiWo", NuanTong_CiWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_CiWo_FengSu.setText(NuanTong_FengSu[NuanTong_CiWo_FengSu]);
                }
                break;
            }
            case R.id.btn_NuanTong_CiWo_MoShi: {
                if (ck_NuanTong_CiWo_KaiGuan.isChecked()) {
                    NuanTong_CiWo_MoShi++;
                    NuanTong_CiWo_MoShi = NuanTong_CiWo_MoShi % 3;
                    NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "CiWo", NuanTong_CiWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_CiWo_MoShi.setText(NuanTong_MoShi[NuanTong_CiWo_MoShi]);
                }
                break;
            }
            //书房
            case R.id.Ibtn_NuanTong_ShuFang_Jian: {
                if (ck_NuanTong_ShuFang_KaiGuan.isChecked()) {
                    NuanTong_ShuFang_WenDu--;
                    if (NuanTong_ShuFang_WenDu <= 16) {
                        NuanTong_ShuFang_WenDu = 16;
                    }
                    NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ShuFang", NuanTong_ShuFang_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ShuFang_WenDu.setText(NuanTong_ShuFang_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.Ibtn_NuanTong_ShuFang_Jia: {
                if (ck_NuanTong_ShuFang_KaiGuan.isChecked()) {
                    NuanTong_ShuFang_WenDu++;
                    if (NuanTong_ShuFang_WenDu >= 30) {
                        NuanTong_ShuFang_WenDu = 30;
                    }
                    NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ShuFang", NuanTong_ShuFang_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ShuFang_WenDu.setText(NuanTong_ShuFang_WenDu + WenDu_FuHao);
                }
                break;
            }
            case R.id.btn_NuanTong_ShuFang_FengSu: {
                if (ck_NuanTong_ShuFang_KaiGuan.isChecked()) {
                    NuanTong_ShuFang_FengSu++;
                    NuanTong_ShuFang_FengSu = NuanTong_ShuFang_FengSu % 3;
                    NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ShuFang", NuanTong_ShuFang_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ShuFang_FengSu.setText(NuanTong_FengSu[NuanTong_ShuFang_FengSu]);
                }
                break;
            }
            case R.id.btn_NuanTong_ShuFang_MoShi: {
                if (ck_NuanTong_ShuFang_KaiGuan.isChecked()) {
                    NuanTong_ShuFang_MoShi++;
                    NuanTong_ShuFang_MoShi = NuanTong_ShuFang_MoShi % 3;
                    NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                    pyObject.callAttr("NuanTong_DuLi_KongZhi", "ShuFang", NuanTong_ShuFang_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                    tv_NuanTong_ShuFang_MoShi.setText(NuanTong_MoShi[NuanTong_ShuFang_MoShi]);
                }
                break;
            }
        }
    }

    @SuppressLint("SetTextI18n")
    @Override
    public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
        switch (compoundButton.getId()) {
            case R.id.ck_NuanTong_KeTing_KaiGuan: {
                if (isChecked) {
                    NuanTong_KeTing_KaiGuan = 1;
                    tv_NuanTong_KeTing_WenDu.setText(NuanTong_KeTing_WenDu + WenDu_FuHao);
                    tv_NuanTong_KeTing_FengSu.setText(NuanTong_FengSu[NuanTong_KeTing_FengSu]);
                    tv_NuanTong_KeTing_MoShi.setText(NuanTong_MoShi[NuanTong_KeTing_MoShi]);
                } else {
                    NuanTong_KeTing_KaiGuan = 0;
                    tv_NuanTong_KeTing_WenDu.setText("");
                    tv_NuanTong_KeTing_FengSu.setText("");
                    tv_NuanTong_KeTing_MoShi.setText("");
                }
                NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi();
                NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                pyObject.callAttr("NuanTong_DuLi_KongZhi", "KeTing", NuanTong_KeTing_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_NuanTong_ZhuWo_KaiGuan: {
                if (isChecked) {
                    NuanTong_ZhuWo_KaiGuan = 1;
                    tv_NuanTong_ZhuWo_WenDu.setText(NuanTong_ZhuWo_WenDu + WenDu_FuHao);
                    tv_NuanTong_ZhuWo_FengSu.setText(NuanTong_FengSu[NuanTong_ZhuWo_FengSu]);
                    tv_NuanTong_ZhuWo_MoShi.setText(NuanTong_MoShi[NuanTong_ZhuWo_MoShi]);
                } else {
                    NuanTong_ZhuWo_KaiGuan = 0;
                    tv_NuanTong_ZhuWo_WenDu.setText("");
                    tv_NuanTong_ZhuWo_FengSu.setText("");
                    tv_NuanTong_ZhuWo_MoShi.setText("");
                }
                NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi();
                NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                pyObject.callAttr("NuanTong_DuLi_KongZhi", "ZhuWo", NuanTong_ZhuWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_NuanTong_CiWo_KaiGuan: {
                if (isChecked) {
                    NuanTong_CiWo_KaiGuan = 1;
                    tv_NuanTong_CiWo_WenDu.setText(NuanTong_CiWo_WenDu + WenDu_FuHao);
                    tv_NuanTong_CiWo_FengSu.setText(NuanTong_FengSu[NuanTong_CiWo_FengSu]);
                    tv_NuanTong_CiWo_MoShi.setText(NuanTong_MoShi[NuanTong_CiWo_MoShi]);
                } else {
                    NuanTong_CiWo_KaiGuan = 0;
                    tv_NuanTong_CiWo_WenDu.setText("");
                    tv_NuanTong_CiWo_FengSu.setText("");
                    tv_NuanTong_CiWo_MoShi.setText("");
                }
                NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi();
                NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                pyObject.callAttr("NuanTong_DuLi_KongZhi", "CiWo", NuanTong_CiWo_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_NuanTong_ShuFang_KaiGuan: {
                if (isChecked) {
                    NuanTong_ShuFang_KaiGuan = 1;
                    tv_NuanTong_ShuFang_WenDu.setText(NuanTong_ShuFang_WenDu + WenDu_FuHao);
                    tv_NuanTong_ShuFang_FengSu.setText(NuanTong_FengSu[NuanTong_ShuFang_FengSu]);
                    tv_NuanTong_ShuFang_MoShi.setText(NuanTong_MoShi[NuanTong_ShuFang_MoShi]);
                } else {
                    NuanTong_ShuFang_KaiGuan = 0;
                    tv_NuanTong_ShuFang_WenDu.setText("");
                    tv_NuanTong_ShuFang_FengSu.setText("");
                    tv_NuanTong_ShuFang_MoShi.setText("");
                }
                NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi();
                NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                pyObject.callAttr("NuanTong_DuLi_KongZhi", "ShuFang", NuanTong_ShuFang_ShuJu_int);//"NuanTong_DuLi_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_NuanTong_YiJian_KaiGuan: {
                if (isChecked) {
                    NuanTong_KeTing_KaiGuan = 1;
                    tv_NuanTong_KeTing_WenDu.setText(NuanTong_KeTing_WenDu + WenDu_FuHao);
                    tv_NuanTong_KeTing_FengSu.setText(NuanTong_FengSu[NuanTong_KeTing_FengSu]);
                    tv_NuanTong_KeTing_MoShi.setText(NuanTong_MoShi[NuanTong_KeTing_MoShi]);
                    ck_NuanTong_KeTing_KaiGuan.setChecked(true);

                    NuanTong_ZhuWo_KaiGuan = 1;
                    tv_NuanTong_ZhuWo_WenDu.setText(NuanTong_ZhuWo_WenDu + WenDu_FuHao);
                    tv_NuanTong_ZhuWo_FengSu.setText(NuanTong_FengSu[NuanTong_ZhuWo_FengSu]);
                    tv_NuanTong_ZhuWo_MoShi.setText(NuanTong_MoShi[NuanTong_ZhuWo_MoShi]);
                    ck_NuanTong_ZhuWo_KaiGuan.setChecked(true);

                    NuanTong_CiWo_KaiGuan = 1;
                    tv_NuanTong_CiWo_WenDu.setText(NuanTong_CiWo_WenDu + WenDu_FuHao);
                    tv_NuanTong_CiWo_FengSu.setText(NuanTong_FengSu[NuanTong_CiWo_FengSu]);
                    tv_NuanTong_CiWo_MoShi.setText(NuanTong_MoShi[NuanTong_CiWo_MoShi]);
                    ck_NuanTong_CiWo_KaiGuan.setChecked(true);

                    NuanTong_ShuFang_KaiGuan = 1;
                    tv_NuanTong_ShuFang_WenDu.setText(NuanTong_ShuFang_WenDu + WenDu_FuHao);
                    tv_NuanTong_ShuFang_FengSu.setText(NuanTong_FengSu[NuanTong_ShuFang_FengSu]);
                    tv_NuanTong_ShuFang_MoShi.setText(NuanTong_MoShi[NuanTong_ShuFang_MoShi]);
                    ck_NuanTong_ShuFang_KaiGuan.setChecked(true);
                } else {
                    NuanTong_KeTing_KaiGuan = 0;
                    tv_NuanTong_KeTing_WenDu.setText("");
                    tv_NuanTong_KeTing_FengSu.setText("");
                    tv_NuanTong_KeTing_MoShi.setText("");
                    ck_NuanTong_KeTing_KaiGuan.setChecked(false);

                    NuanTong_ZhuWo_KaiGuan = 0;
                    tv_NuanTong_ZhuWo_WenDu.setText("");
                    tv_NuanTong_ZhuWo_FengSu.setText("");
                    tv_NuanTong_ZhuWo_MoShi.setText("");
                    ck_NuanTong_ZhuWo_KaiGuan.setChecked(false);

                    NuanTong_CiWo_KaiGuan = 0;
                    tv_NuanTong_CiWo_WenDu.setText("");
                    tv_NuanTong_CiWo_FengSu.setText("");
                    tv_NuanTong_CiWo_MoShi.setText("");
                    ck_NuanTong_CiWo_KaiGuan.setChecked(false);

                    NuanTong_ShuFang_KaiGuan = 0;
                    tv_NuanTong_ShuFang_WenDu.setText("");
                    tv_NuanTong_ShuFang_FengSu.setText("");
                    tv_NuanTong_ShuFang_MoShi.setText("");
                    ck_NuanTong_ShuFang_KaiGuan.setChecked(false);
                }

                NuanTong_KeTing_ShuJu_int = NuanTong_KeTing_WenDu * 1000 + NuanTong_KeTing_MoShi * 100 + NuanTong_KeTing_FengSu * 10 + NuanTong_KeTing_KaiGuan;
                NuanTong_ZhuWo_ShuJu_int = NuanTong_ZhuWo_WenDu * 1000 + NuanTong_ZhuWo_MoShi * 100 + NuanTong_ZhuWo_FengSu * 10 + NuanTong_ZhuWo_KaiGuan;
                NuanTong_CiWo_ShuJu_int = NuanTong_CiWo_WenDu * 1000 + NuanTong_CiWo_MoShi * 100 + NuanTong_CiWo_FengSu * 10 + NuanTong_CiWo_KaiGuan;
                NuanTong_ShuFang_ShuJu_int = NuanTong_ShuFang_WenDu * 1000 + NuanTong_ShuFang_MoShi * 100 + NuanTong_ShuFang_FengSu * 10 + NuanTong_ShuFang_KaiGuan;
                pyObject.callAttr("NuanTong_YiJian_KongZhi", NuanTong_KeTing_ShuJu_int, NuanTong_ZhuWo_ShuJu_int, NuanTong_CiWo_ShuJu_int, NuanTong_ShuFang_ShuJu_int);//"NuanTong_YiJian_KongZhi"为需要调用的函数名
                break;
            }
        }
    }

    //暖通一键开关状态设置
    public void NuanTong_YiJian_KaiGuan_ZhuangTai_SheZhi() {
        if (NuanTong_KeTing_KaiGuan == 1 && NuanTong_ZhuWo_KaiGuan == 1 && NuanTong_CiWo_KaiGuan == 1 && NuanTong_ShuFang_KaiGuan == 1) {
            ck_NuanTong_YiJian_KaiGuan.setChecked(true);
        } else if (NuanTong_KeTing_KaiGuan == 0 && NuanTong_ZhuWo_KaiGuan == 0 && NuanTong_CiWo_KaiGuan == 0 && NuanTong_ShuFang_KaiGuan == 0) {
            ck_NuanTong_YiJian_KaiGuan.setChecked(false);
        }
    }
}