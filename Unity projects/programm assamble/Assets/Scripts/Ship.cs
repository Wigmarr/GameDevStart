using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ship : MonoBehaviour
{
    // radius of collider
    float radius;
    // rigidbody component
    Rigidbody2D rg;
    //direction for thrust
    Vector2 thrustDirection = new Vector2(0 ,  1);
    // force for thrust
    [SerializeField]
    float ThrustForce = 5f;
    //  how much degrees ship rotates per second

    [SerializeField]
    float rotateDegreesPerSecond = 10f;

    // Use this for initialization
    void Start()
    {
        // get radius of collider
        radius = GetComponent<CircleCollider2D>().radius;
        // get rigidbody
        rg = GetComponent<Rigidbody2D>();
    }

    // Use this when dealing with Rigidbody
    private void FixedUpdate()
    {
        // add force if 'space' pressed
        if (Input.GetAxis("Thrust") > 0)
            rg.AddForce(thrustDirection * ThrustForce, ForceMode2D.Force);
    }
    // Update is called once per frame
    void Update()
    {
        if (Input.GetAxis("Rotate") != 0)
        {
            float rotationAmount = rotateDegreesPerSecond * Time.deltaTime;
            if (Input.GetAxis("Rotate") < 0)
                rotationAmount *= -1;
            transform.Rotate(Vector3.forward, rotationAmount);
            float z = transform.eulerAngles.z * Mathf.Deg2Rad;
            thrustDirection = new Vector2(-Mathf.Sin(z), Mathf.Cos(z));
        }
    }
    private void OnBecameInvisible()
    {
        if (transform.position.x + radius >= ScreenUtils.ScreenRight)
            transform.position = new Vector2 (ScreenUtils.ScreenLeft - radius, transform.position.y);
        else 
        if (transform.position.x - radius <= ScreenUtils.ScreenLeft)
            transform.position = new Vector2(ScreenUtils.ScreenRight + radius, transform.position.y);
        if (transform.position.y + radius >= ScreenUtils.ScreenTop)
            transform.position = new Vector2(transform.position.x, ScreenUtils.ScreenBottom - radius);
        else
        if (transform.position.y - radius <= ScreenUtils.ScreenBottom)
            transform.position = new Vector2(transform.position.x, ScreenUtils.ScreenTop + radius);
    }
}
