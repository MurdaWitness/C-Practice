using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed;
    public float leftBorder;
    public float rightBorder;
    public int score;
    void Start()
    {
        score = 0;
    }

    // Update is called once per frame
    void Update()
    {
        Move();
    }

    void Move()
    {
        if (Input.GetKey(KeyCode.A)&&transform.position.x>leftBorder)
        {
            transform.Translate(Vector3.left * speed * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.D) && transform.position.x<rightBorder)
        {
            transform.Translate(Vector3.right * speed * Time.deltaTime);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.GetComponent<Ball>() != null)
        {
            var myColor = GetComponent<ColorControl>().color;
            var ballColor = other.GetComponent<ColorControl>().color;
            if(myColor == ballColor)
            {
                score += other.GetComponent<Ball>().scoreAmount;
            }
            else
            {
                score -= other.GetComponent<Ball>().scoreAmount;
            }
            Destroy(other.gameObject);
        }
    }
}
