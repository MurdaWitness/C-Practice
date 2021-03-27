using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorControl : MonoBehaviour
{
    public enum MyColor
    {
        red,
        green,
        blue
    }

    public MyColor color;
    public MeshRenderer mr;
    void Start()
    {
        mr = GetComponent<MeshRenderer>();

        ChangeColor((MyColor)Random.Range(0,3));
    }

    public void ChangeColor(MyColor color)
    {
        this.color = color;

        if (this.color == MyColor.red)
        {
            mr.material.color = Color.red;
        }
        else if (this.color == MyColor.green)
        {
            mr.material.color = Color.green;
        }
        else
        {
            mr.material.color = Color.blue;
        }
    }
}
