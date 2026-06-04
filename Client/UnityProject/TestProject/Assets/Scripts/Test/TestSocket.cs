using LoginPB;
using Fuel.NetFramework.Attributes;
using Fuel.NetFramework.Core;
using UnityEngine;
using UnityEngine.UI;

public class TestSocket : MonoBehaviour
{
    public Button _loginBtn;
    public Text _logText;
    void Awake()
    {
        _logText.text = "等待登录";
        _loginBtn.onClick.AddListener(LoginReq);
        NetworkManager.Instance.InitCmdGetter(new ProtoCmds());
        NetworkManager.Instance.Connect("127.0.0.1", 9000);
        NetHandlerGenerated.RegisterAll();
    }
    // Start is called before the first frame update
    void Start()
    {

    }
    public void LoginReq()
    {
        _logText.text = "登录中";
        NetworkManager.Instance.Send(new LoginReq());
        _logText.text = "登录成功";
    }
    [NetMessageHandler(typeof(LoginRsp))]
    public static void LoginResp(LoginRsp resp)
    {
        Debug.Log($"登录成功: {resp.Result}");
    }
    public static void AcegoLoginReq(AcegoLoginReq req)
    {
        NetworkManager.Instance.Send(new AcegoLoginReq());
    }
    [NetMessageHandler(typeof(AcegoLoginReq),typeof(AcegoLoginRsp))]
    public static void AcegoLoginResp(AcegoLoginReq req, AcegoLoginRsp resp)
    {
        Debug.Log($"test");
    }
    // Update is called once per frame
    void Update()
    {

    }
}
