
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace TCallCDll
{
    [StructLayout(LayoutKind.Sequential)]
    public struct _XY
    {
        public int x;
        public int y;
    };

    public delegate void OurDllCallBack(String iin);
    public delegate bool SysCallBack(int hwnd, int lParam);

    public class TCallCDll{
        
//      [DllImport("dll.dll", EntryPoint = "TCharPara", CharSet = CharSet.Auto)]
        //////////////////////////////////////////////////////////////////////////
        //iin: 输入参数
        //oout: 输出参数
        //.NET passes your string(oout) as an ANSI char, not a wide one(UnmanagedType.LPTStr).
        //[DllImport("audiosimilarity.dll", EntryPoint = "AudioSimilarity_Process", CharSet = CharSet.Unicode)]
        [DllImport("audiosimilarity.dll")]
        //////////////////////////////////////////////////////////////////////////
        public static extern int AudioSimilarity_Process(String pRefFile, String pDeFile, Int32 pSampleRate,float pSensitivity, [MarshalAs(UnmanagedType.LPStr)] StringBuilder score);
        //public static extern int AudioSimilarity_Process(String pRefFile, String pDeFile, Int32 pSampleRate);
        //[DllImport("dll.dll")]
        //public static extern int TCharPara(String iin, int len, [MarshalAs(UnmanagedType.LPStr)] StringBuilder oout);
        
       // [DllImport("dll.dll")]
        //public static extern int TStructPara(ref _XY xy);

        //[DllImport("dll.dll", CharSet = CharSet.Ansi)]
        //public static extern void TCallback(OurDllCallBack f, String s);

        //[DllImport("user32")]
       // public static extern int EnumWindows(SysCallBack x, int y); 

    }
    public partial class callCDllMain : Form
    {
 
        public callCDllMain()
        {
            InitializeComponent();
        }

        public static void ff(String s)
        {
            Console.WriteLine(s);
        }

        public static bool Report(int hwnd, int lParam)
        {
            Console.Write("Window handle is ");
            Console.WriteLine(hwnd);
            return true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            StringBuilder score = new StringBuilder(300);
            String pRefFile = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\20180604230304.wav";
           // string filePath = "C:\\JiYF\\BenXH\\BenXHCMS.xml";
            Console.WriteLine("该文件的目录：" + pRefFile);
            String pDeFile = "E:\\project\\audiosimilarity-1.0.1\\audiosimilarity\\audiosimilarity\\Debug\\20180607224948.wav";
            Console.WriteLine("该文件的目录：" + pDeFile);
            //String pRefFile = "123456789";
            //String pDeFile = "abcdefgh";
            //[MarshalAs(UnmanagedType.ByValArray, SizeConst=10, ArraySubType=UnmanagedType.SysInt)];
            //public int[] numbers
           // [MarshalAs(UnmanagedType.ByValTStr, SizeConst=256)]
           // string name;

            Int32 pSampleRate = 16000;
            float pSensitivity = 0.5f;
            //float score = 0.0f;
            //TCallCDll.TCharPara("ABC", 3, score);
            Console.WriteLine("Before AudioSimilarity_Process");
            Console.WriteLine("\n");
            TCallCDll.AudioSimilarity_Process(pRefFile, pDeFile, pSampleRate, pSensitivity, score);
            //Int32 score = TCallCDll.AudioSimilarity_Process(pRefFile, pDeFile, pSampleRate);
            Console.WriteLine(score);
            Console.WriteLine("After AudioSimilarity_Process");
            Console.WriteLine("\n");
            this.Text = score.ToString();

            //_XY xy = new _XY();
            //TCallCDll.TStructPara(ref xy);
            //this.Text += "x:" + xy.x + ", y:" + xy.y;

            //OurDllCallBack fff = new OurDllCallBack(ff);
            //TCallCDll.TCallback(fff, "This string is output in C&C++ dll call back function set in C# code\n");

            //SysCallBack cb = new SysCallBack(Report);
            //TCallCDll.EnumWindows(cb, 0);
        }
    }
}