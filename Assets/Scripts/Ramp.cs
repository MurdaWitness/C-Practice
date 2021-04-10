using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ramp : MonoBehaviour
{
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.GetComponent<Player>() != null)
        {
            var color = collision.gameObject.GetComponent<ColorControl>();
            var colorForChange = gameObject.GetComponentInChildren<ColorControl>().color;
            color.ChangeColor(colorForChange);
        }
    }
}
