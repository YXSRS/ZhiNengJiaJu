package com.example.zhineng_jiaju;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import com.chaquo.python.Python;
import com.chaquo.python.android.AndroidPlatform;

public class Activity_ZhuJieMian extends AppCompatActivity {
    private RadioGroup rg_DiBu_DaoHangLan;
    private RadioButton rb_ZhaoMing;
    private RadioButton rb_NuanTong;
    private RadioButton rb_AnFang;
    private fragment_zhao_ming ZhaoMing;
    private fragment_NuanTong NuanTong;
    private fragment_AnFang AnFang;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_zhu_jie_mian);

        // 初始化Python环境
        if (!Python.isStarted()) {
            Python.start(new AndroidPlatform(this));
        }

        // 通过资源标识符获取控件实例
        rg_DiBu_DaoHangLan = findViewById(R.id.rg_DiBu_DaoHangLan);//底部导航栏
        rb_ZhaoMing = findViewById(R.id.rb_ZhaoMing);//照明
        rb_NuanTong = findViewById(R.id.rb_NuanTong);//暖通
        rb_AnFang = findViewById(R.id.rb_AnFang);//安防

        // 创建三个碎片实例
        ZhaoMing = new fragment_zhao_ming();
        NuanTong = new fragment_NuanTong();
        AnFang = new fragment_AnFang();

        // 进行事件处理
        eventHandling();
        // 显示碎片
        showFragment(ZhaoMing);
    }

    /**
     * 显示碎片
     *
     * @param fragment
     */
    private void showFragment(Fragment fragment) {
        // 创建碎片管理器
        FragmentManager fm = getSupportFragmentManager();
        // 创建碎片事务
        FragmentTransaction ft = fm.beginTransaction();
        // 在容器里显示碎片
        ft.replace(R.id.container, fragment);
        // 提交碎片事务
        ft.commit();
    }

    private void eventHandling() {
        rg_DiBu_DaoHangLan.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.rb_ZhaoMing: //照明
                        showFragment(ZhaoMing);
                        break;
                    case R.id.rb_NuanTong: //暖通
                        showFragment(NuanTong);
                        break;
                    case R.id.rb_AnFang: //安防
                        showFragment(AnFang);
                        break;
                }
            }
        });
    }
}