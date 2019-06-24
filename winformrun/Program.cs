using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace winformrun
{
    static class Program
    {
        [DllImport("kernel32", SetLastError = true, CharSet = CharSet.Unicode)]
        static extern IntPtr LoadLibraryW([MarshalAs(UnmanagedType.LPWStr)]string lpFileName);

        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            // ！！仅供在 VS IDE 内调试运行！！
            Environment.CurrentDirectory = Path.Combine(Environment.CurrentDirectory, "../../../", Path.GetFileName(Environment.CurrentDirectory));
            if (Environment.Is64BitProcess)
                LoadLibraryW("mactype64.core.dll");
            else
                LoadLibraryW("mactype.core.dll");
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
