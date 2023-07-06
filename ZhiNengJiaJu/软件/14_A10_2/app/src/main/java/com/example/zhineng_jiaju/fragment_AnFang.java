package com.example.zhineng_jiaju;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.os.CountDownTimer;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;

import com.chaquo.python.PyObject;
import com.chaquo.python.Python;

public class fragment_AnFang extends Fragment implements View.OnClickListener, CompoundButton.OnCheckedChangeListener {

    private PyObject pyObject;
    private TextView tv_AnFang_MenSuo_ZhuangTai;
    private Button btn_AnFang_YiJian_KaiMen;
    private TextView tv_AnFang_CO_ZhuangTai;
    private TextView tv_AnFang_PaiQiShan_ZhuangTai;
    private TextView tv_AnFang_YuDi_ZhuangTai;
    private TextView tv_AnFang_ChuangHu_ZhuangTai;
    private CheckBox ck_AnFang_ChuangHu_KaiGuan;
    private TextView tv_AnFang_HuoYan_ZhuangTai;
    private TextView tv_AnFang_MieHuoQi_ZhuangTai;
    private TextView tv_AnFang_ShiNei_WenDu;
    private TextView tv_AnFang_ShiNei_ShiDu;
    String AnFang_ShuJu;
    private int AnFang_MenSuo_ZhuangTai;
    private int AnFang_CO_ZhuangTai;
    private int AnFang_YuDi_ZhuangTai;
    private int AnFang_HuoYan_ZhuangTai;
    private double AnFang_ShiNei_WeiDu;
    private double AnFang_ShiNei_ShiDu;
    private int AnFang_PaiQiShan_ZhuangTai;
    private int AnFang_ChuangHu_ZhuangTai;
    private int AnFang_MieHuoQi_ZhuangTai;
    String WenDu_FuHao = "℃";
    String ShiDu_FuHao = "%";
    CountDownTimer timer;
    private TextView tv_AnFang_JiaJu_DianQi1_ZhuangTai;
    private CheckBox ck_AnFang_JiaJu_DianQi1_KaiGuan;
    private TextView tv_AnFang_JiaJu_DianQi2_ZhuangTai;
    private CheckBox ck_AnFang_JiaJu_DianQi2_KaiGuan;
    private int AnFang_JiaJu_DianQi1_ZhuangTai;
    private int AnFang_JiaJu_DianQi2_ZhuangTai;


    public fragment_AnFang() {

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
        View view = LayoutInflater.from(context).inflate(R.layout.fragment_an_fang, container, false);

        Python python = Python.getInstance(); // 初始化Python环境
        pyObject = python.getModule("Python_API");//"Python_API"为需要调用的Python文件名

        //门锁
        tv_AnFang_MenSuo_ZhuangTai = view.findViewById(R.id.tv_AnFang_MenSuo_ZhuangTai);
        btn_AnFang_YiJian_KaiMen = view.findViewById(R.id.btn_AnFang_YiJian_KaiMen);

        //CO
        tv_AnFang_CO_ZhuangTai = view.findViewById(R.id.tv_AnFang_CO_ZhuangTai);
        tv_AnFang_PaiQiShan_ZhuangTai = view.findViewById(R.id.tv_AnFang_PaiQiShan_ZhuangTai);

        //雨滴
        tv_AnFang_YuDi_ZhuangTai = view.findViewById(R.id.tv_AnFang_YuDi_ZhuangTai);
        tv_AnFang_ChuangHu_ZhuangTai = view.findViewById(R.id.tv_AnFang_ChuangHu_ZhuangTai);
        ck_AnFang_ChuangHu_KaiGuan = view.findViewById(R.id.ck_AnFang_ChuangHu_KaiGuan);

        //火焰
        tv_AnFang_HuoYan_ZhuangTai = view.findViewById(R.id.tv_AnFang_HuoYan_ZhuangTai);
        tv_AnFang_MieHuoQi_ZhuangTai = view.findViewById(R.id.tv_AnFang_MieHuoQi_ZhuangTai);

        //室内温度
        tv_AnFang_ShiNei_WenDu = view.findViewById(R.id.tv_AnFang_ShiNei_WenDu);

        //室内湿度
        tv_AnFang_ShiNei_ShiDu = view.findViewById(R.id.tv_AnFang_ShiNei_ShiDu);

        //家居电器1
        tv_AnFang_JiaJu_DianQi1_ZhuangTai = view.findViewById(R.id.tv_AnFang_JiaJu_DianQi1_ZhuangTai);
        ck_AnFang_JiaJu_DianQi1_KaiGuan = view.findViewById(R.id.ck_AnFang_JiaJu_DianQi1_KaiGuan);

        //家居电器2
        tv_AnFang_JiaJu_DianQi2_ZhuangTai = view.findViewById(R.id.tv_AnFang_JiaJu_DianQi2_ZhuangTai);
        ck_AnFang_JiaJu_DianQi2_KaiGuan = view.findViewById(R.id.ck_AnFang_JiaJu_DianQi2_KaiGuan);

        //获取云数据的安防表数据，并将获取到的数据设置到界面上
        ShuaXin_ShuJu();

        btn_AnFang_YiJian_KaiMen.setOnClickListener(this);
        ck_AnFang_ChuangHu_KaiGuan.setOnCheckedChangeListener(this);
        ck_AnFang_JiaJu_DianQi1_KaiGuan.setOnCheckedChangeListener(this);
        ck_AnFang_JiaJu_DianQi2_KaiGuan.setOnCheckedChangeListener(this);

        timer = new CountDownTimer(Long.MAX_VALUE, 2000) {
            @Override
            public void onTick(long l) {
                // 在这里执行访问云数据库的操作
                // 每隔 2 秒执行一次倒计时
                ShuaXin_ShuJu();
            }

            @Override
            public void onFinish() {
                // 在这里再次启动倒计时
            }
        };
        return view;
    }

    @Override
    public void onPause() {
        super.onPause();
        //本方法被调用的情况
        //碎片被其他碎片覆盖，例如用户在两个不同的碎片之间切换。
        //碎片所在的活动被其他活动覆盖，例如用户启动了另一个应用程序。
        //碎牌所在的活动被暂停，例如用户按下了电源键。

        // 停止倒计时
        timer.cancel();
    }

    @Override
    public void onResume() {
        super.onResume();
        //本方法被调用的情况
        //碎片被其他碎片覆盖，然后用户返回到这个碎片。
        //碎片所在的活动被其他活动覆盖，然后用户返回到这个活动。
        //碎片所在的活动被暂停，然后恢复运行。

        // 重新启动倒计时
        timer.start();
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_AnFang_YiJian_KaiMen: {
                AnFang_MenSuo_ZhuangTai = 1;
                tv_AnFang_MenSuo_ZhuangTai.setText("开");
                tv_AnFang_MenSuo_ZhuangTai.setTextColor(Color.RED);
                pyObject.callAttr("AnFang_KongZhi", "MenSuo", AnFang_MenSuo_ZhuangTai);//"AnFang_KongZhi"为需要调用的函数名
                break;
            }
        }
    }

    @Override
    public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
        switch (compoundButton.getId()) {
            case R.id.ck_AnFang_ChuangHu_KaiGuan: {
                if (isChecked) {
                    AnFang_ChuangHu_ZhuangTai = 1;
                    tv_AnFang_ChuangHu_ZhuangTai.setText("开");
                    tv_AnFang_ChuangHu_ZhuangTai.setTextColor(Color.RED);

                } else {
                    AnFang_ChuangHu_ZhuangTai = 0;
                    tv_AnFang_ChuangHu_ZhuangTai.setText("关");
                    tv_AnFang_ChuangHu_ZhuangTai.setTextColor(Color.GREEN);
                }
                pyObject.callAttr("AnFang_KongZhi", "ChuangHu", AnFang_ChuangHu_ZhuangTai);//"AnFang_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_AnFang_JiaJu_DianQi1_KaiGuan: {
                if (isChecked) {
                    AnFang_JiaJu_DianQi1_ZhuangTai = 1;
                    tv_AnFang_JiaJu_DianQi1_ZhuangTai.setText("开");
                    tv_AnFang_JiaJu_DianQi1_ZhuangTai.setTextColor(Color.RED);

                } else {
                    AnFang_JiaJu_DianQi1_ZhuangTai = 0;
                    tv_AnFang_JiaJu_DianQi1_ZhuangTai.setText("关");
                    tv_AnFang_JiaJu_DianQi1_ZhuangTai.setTextColor(Color.GREEN);
                }
                pyObject.callAttr("AnFang_KongZhi", "JiaJu_DianQi1", AnFang_JiaJu_DianQi1_ZhuangTai);//"AnFang_KongZhi"为需要调用的函数名
                break;
            }
            case R.id.ck_AnFang_JiaJu_DianQi2_KaiGuan: {
                if (isChecked) {
                    AnFang_JiaJu_DianQi2_ZhuangTai = 1;
                    tv_AnFang_JiaJu_DianQi2_ZhuangTai.setText("开");
                    tv_AnFang_JiaJu_DianQi2_ZhuangTai.setTextColor(Color.RED);

                } else {
                    AnFang_JiaJu_DianQi2_ZhuangTai = 0;
                    tv_AnFang_JiaJu_DianQi2_ZhuangTai.setText("关");
                    tv_AnFang_JiaJu_DianQi2_ZhuangTai.setTextColor(Color.GREEN);
                }
                pyObject.callAttr("AnFang_KongZhi", "JiaJu_DianQi2", AnFang_JiaJu_DianQi2_ZhuangTai);//"AnFang_KongZhi"为需要调用的函数名
                break;
            }
        }
    }

    /*
        刷新数据
     */
    @SuppressLint("SetTextI18n")
    public void ShuaXin_ShuJu() {
        PyObject ret = pyObject.callAttr("get_AnFang_ShuJu");//"get_AnFang_ShuJu"为需要调用的函数名
        AnFang_ShuJu = String.valueOf(ret);
        String[] strs = AnFang_ShuJu.split(",");//分割数据
        AnFang_MenSuo_ZhuangTai = Integer.parseInt(strs[0]);
        AnFang_CO_ZhuangTai = Integer.parseInt(strs[1]);
        AnFang_YuDi_ZhuangTai = Integer.parseInt(strs[2]);
        AnFang_HuoYan_ZhuangTai = Integer.parseInt(strs[3]);
        AnFang_ShiNei_WeiDu = Double.parseDouble(strs[4]);
        AnFang_ShiNei_ShiDu = Double.parseDouble(strs[5]);
        AnFang_PaiQiShan_ZhuangTai = Integer.parseInt(strs[6]);
        AnFang_ChuangHu_ZhuangTai = Integer.parseInt(strs[7]);
        AnFang_MieHuoQi_ZhuangTai = Integer.parseInt(strs[8]);
        AnFang_JiaJu_DianQi1_ZhuangTai = Integer.parseInt(strs[9]);
        AnFang_JiaJu_DianQi2_ZhuangTai = Integer.parseInt(strs[10]);

        //门锁
        if (AnFang_MenSuo_ZhuangTai == 1) {
            tv_AnFang_MenSuo_ZhuangTai.setText("开");
            tv_AnFang_MenSuo_ZhuangTai.setTextColor(Color.RED);
        } else {
            tv_AnFang_MenSuo_ZhuangTai.setText("关");
            tv_AnFang_MenSuo_ZhuangTai.setTextColor(Color.GREEN);
        }

        //CO
        if (AnFang_CO_ZhuangTai == 1) {
            tv_AnFang_CO_ZhuangTai.setText("有");
            tv_AnFang_CO_ZhuangTai.setTextColor(Color.RED);
        } else {
            tv_AnFang_CO_ZhuangTai.setText("无");
            tv_AnFang_CO_ZhuangTai.setTextColor(Color.GREEN);
        }
        if (AnFang_PaiQiShan_ZhuangTai == 1) {
            tv_AnFang_PaiQiShan_ZhuangTai.setText("开");
            tv_AnFang_PaiQiShan_ZhuangTai.setTextColor(Color.GREEN);
        } else {
            tv_AnFang_PaiQiShan_ZhuangTai.setText("关");
            tv_AnFang_PaiQiShan_ZhuangTai.setTextColor(Color.RED);
        }

        //雨滴
        if (AnFang_YuDi_ZhuangTai == 1) {
            tv_AnFang_YuDi_ZhuangTai.setText("有");
            tv_AnFang_YuDi_ZhuangTai.setTextColor(Color.RED);
        } else {
            tv_AnFang_YuDi_ZhuangTai.setText("无");
            tv_AnFang_YuDi_ZhuangTai.setTextColor(Color.GREEN);
        }
        if (AnFang_ChuangHu_ZhuangTai == 1) {
            tv_AnFang_ChuangHu_ZhuangTai.setText("开");
            tv_AnFang_ChuangHu_ZhuangTai.setTextColor(Color.RED);
            ck_AnFang_ChuangHu_KaiGuan.setChecked(true);
        } else {
            tv_AnFang_ChuangHu_ZhuangTai.setText("关");
            tv_AnFang_ChuangHu_ZhuangTai.setTextColor(Color.GREEN);
            ck_AnFang_ChuangHu_KaiGuan.setChecked(false);
        }

        //火焰
        if (AnFang_HuoYan_ZhuangTai == 1) {
            tv_AnFang_HuoYan_ZhuangTai.setText("有");
            tv_AnFang_HuoYan_ZhuangTai.setTextColor(Color.RED);
        } else {
            tv_AnFang_HuoYan_ZhuangTai.setText("无");
            tv_AnFang_HuoYan_ZhuangTai.setTextColor(Color.GREEN);
        }
        if (AnFang_MieHuoQi_ZhuangTai == 1) {
            tv_AnFang_MieHuoQi_ZhuangTai.setText("开");
            tv_AnFang_MieHuoQi_ZhuangTai.setTextColor(Color.GREEN);
        } else {
            tv_AnFang_MieHuoQi_ZhuangTai.setText("关");
            tv_AnFang_MieHuoQi_ZhuangTai.setTextColor(Color.RED);
        }

        //温湿度
        tv_AnFang_ShiNei_WenDu.setText(AnFang_ShiNei_WeiDu + WenDu_FuHao);
        tv_AnFang_ShiNei_ShiDu.setText(AnFang_ShiNei_ShiDu + ShiDu_FuHao);

        //家居电器1
        if (AnFang_JiaJu_DianQi1_ZhuangTai == 1) {
            tv_AnFang_JiaJu_DianQi1_ZhuangTai.setText("开");
            tv_AnFang_JiaJu_DianQi1_ZhuangTai.setTextColor(Color.RED);
            ck_AnFang_JiaJu_DianQi1_KaiGuan.setChecked(true);
        } else {
            tv_AnFang_JiaJu_DianQi1_ZhuangTai.setText("关");
            tv_AnFang_JiaJu_DianQi1_ZhuangTai.setTextColor(Color.GREEN);
            ck_AnFang_JiaJu_DianQi1_KaiGuan.setChecked(false);
        }

        //家居电器2
        if (AnFang_JiaJu_DianQi2_ZhuangTai == 1) {
            tv_AnFang_JiaJu_DianQi2_ZhuangTai.setText("开");
            tv_AnFang_JiaJu_DianQi2_ZhuangTai.setTextColor(Color.RED);
            ck_AnFang_JiaJu_DianQi2_KaiGuan.setChecked(true);
        } else {
            tv_AnFang_JiaJu_DianQi2_ZhuangTai.setText("关");
            tv_AnFang_JiaJu_DianQi2_ZhuangTai.setTextColor(Color.GREEN);
            ck_AnFang_JiaJu_DianQi2_KaiGuan.setChecked(false);
        }
    }
}